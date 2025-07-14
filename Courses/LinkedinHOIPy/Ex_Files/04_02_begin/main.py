from flask import Flask

app = Flask(__name__)

@app.route("/")
def hello():
  return "Mainpage"

@app.route("/shop")
def shop():
  return "$10-Hat $5-Gloves"

@app.route("/about")
def about():
  return "Established 07/07/2025"

app.run(debug=True)