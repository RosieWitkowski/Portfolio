import os

from cs50 import SQL
from datetime import datetime
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    id = session["user_id"]
    # Later, optionally, group by symbol and SUM the shares and total so it looks better
    stocks = db.execute(
        "SELECT symbol, price, shares FROM purchases WHERE user_id = ?", id
    )
    cash = db.execute("SELECT cash FROM users WHERE id=?", id)
    cash = usd(cash[0]["cash"])
    symbol = db.execute("SELECT symbol FROM purchases WHERE user_id=?", id)
    prices = {}
    names = {}
    for company in symbol:
        company = company["symbol"]
        name = lookup(company)["name"]
        price = lookup(company)["price"]
        prices[company] = price
        names[company] = name
    totalStocks = (db.execute("SELECT SUM (price) FROM purchases WHERE user_id=?", id))[
        0
    ]["SUM (price)"]
    totalCash = (db.execute("SELECT cash FROM users WHERE id=?", id))[0]["cash"]
    if totalStocks == None or totalCash == "None":
        total = usd(0)
    else:
        total = usd(totalStocks + totalCash)
    return render_template(
        "index.html", stocks=stocks, cash=cash, names=names, prices=prices, total=total
    )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "GET":
        return render_template("buy.html")
    else:
        # Input validation
        if not request.form.get("symbol") or not lookup(request.form.get("symbol")):
            return apology("Please enter a valid symbol.")

        shares = request.form.get("shares")
        if not shares.isdigit():
            return apology("Please input a valid number of shares.")
        shares = int(shares)
        if shares < 0:
            return apology("Please input a valid number of shares.")

        # Calculate
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash = cash[0]["cash"]
        price = (lookup(request.form.get("symbol"))["price"]) * shares
        if cash < price:
            return apology("Not enough money.")
        else:
            # Remaining money in account
            cash = cash - price
            db.execute("UPDATE users SET cash=? WHERE id=?", cash, session["user_id"])

            # Record of purchase
            date = datetime.strftime(datetime.now(), "%Y-%m-%d")
            db.execute(
                "INSERT INTO purchases (user_id, symbol, shares, price, date) VALUES(?, ?, ?, ?, ?)",
                session["user_id"],
                request.form.get("symbol"),
                shares,
                price,
                date,
            )
        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    else:
        if not request.form.get("symbol"):
            return apology("Input a symbol.")

        symbol = request.form.get("symbol")
        symbols = lookup(symbol)
        if symbols == None:
            return apology("Not a valid symbol.")
        price = usd(symbols["price"])
        return render_template("quoted.html", symbols=symbols, price=price)
    return apology("TODO")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        if not request.form.get("username") or not request.form.get("password"):
            return apology("Username and password required.")

        users = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )
        if len(users) != 0:
            return apology("Username taken.")

        if request.form.get("password") != request.form.get("confirmation"):
            return apology("Passwords do not match.")

        username = request.form.get("username")
        password = request.form.get("password")

        password = generate_password_hash(password)
        db.execute("INSERT INTO users (username, hash) VALUES(?,?)", username, password)
        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
