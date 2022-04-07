from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def app_index():
    return render_template('index-2.html')

