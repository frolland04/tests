from flask import Flask, render_template
import sqlite3

def get_db_connection():
    l_conn = sqlite3.connect('database.sqlite')
    l_conn.row_factory = sqlite3.Row
    return l_conn

app = Flask(__name__)

@app.route('/')
def app_index():
    cnx = get_db_connection()
    msgs = cnx.execute('SELECT * FROM T_messages').fetchall()
    cnx.close()
    return render_template('index-3.html', jmsgs=msgs)
