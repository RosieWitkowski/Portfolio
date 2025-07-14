import os
from cs50 import SQL
from flask import Flask, render_template, request, redirect

app = Flask(__name__)

db = SQL("sqlite:///bookshelf.db")

@app.route("/")
def index():
    books = db.execute("SELECT * FROM books ORDER BY title")
    return render_template("index.html", books=books)

@app.route("/all")
def all():
    books = db.execute("SELECT * FROM books ORDER BY title")
    return render_template("viewAll.html", books = books)

@app.route("/delete", methods=["GET", "POST"])
def delete():
    if request.method == "POST":
        if not request.form.get("confirm"):
            id = request.form.get("id")
            title=request.form.get("title")
            author=request.form.get("author")
            return render_template("delete.html", id = id, title=title,author=author)
        else:
            if request.form.get("confirm") == "yes":
                id = request.form.get("id")
                db.execute("DELETE FROM books WHERE id = ?", id)
                return redirect("/")
            else:
                return redirect("/")

@app.route("/search", methods=["GET", "POST"])
def search():
    if request.method == "POST":
        if not request.form.get("text"):
            return redirect("/")
        text = request.form.get("text")
        books = db.execute("SELECT * FROM books WHERE title LIKE ('%' || ? || '%') OR author like ('%' || ? || '%')", text, text)
        return render_template("index.html", books=books)
        # CONSIDER USING JAVA SCRIPT

@app.route("/number")
def number():
    number = db.execute("SELECT COUNT(*) FROM books")
    return render_template("count.html", number = number)

@app.route("/sort", methods=["GET", "POST"])
def sort():
    if request.form.get("sort") == "title":
        books = db.execute("SELECT * FROM books ORDER by title")
        return render_template("index.html", books=books)
    else:
        print("sort author")
        books = db.execute("SELECT * FROM books ORDER by author")
        return render_template("index.html", books=books)
@app.route("/desc", methods=["GET", "POST"])
def desc():
     if request.form.get("sort") == "title":
        books = db.execute("SELECT * FROM books ORDER BY title DESC")
        return render_template("index.html", books=books)
     else:
        books = db.execute("SELECT * FROM books ORDER by author DESC")
        return render_template("index.html", books = books)

@app.route("/help")
def help():
    return render_template("help.html")

@app.route("/add", methods=["GET", "POST"])
def add():
    if request.method == "POST":
        if request.form.get("title"):
            title = request.form.get("title")
            if not request.form.get("author"):
                author = "Default"
            else:
                author = request.form.get("author")

            db.execute("INSERT INTO books (title, author) VALUES(?, ?)", title, author)
            return redirect("/")

    else:
        return render_template("add.html")


