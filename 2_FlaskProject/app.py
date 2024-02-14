from flask import Flask, render_template, redirect

app = Flask(__name__)

@app.route("/")
def home():
    return render_template("home.html")

@app.route("/songs")
def songs():
    return render_template("songs.html")

@app.route("/about")
def about():
    return render_template("about.html")


# import sys

# print(sys.path)
