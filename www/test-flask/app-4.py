from flask import Flask, render_template
from werkzeug.exceptions import abort
import sqlite3

def get_db_connection():
    l_conn = sqlite3.connect('database.sqlite')
    l_conn.row_factory = sqlite3.Row
    return l_conn

def get_message_from_db(id):
    l_conn = get_db_connection()
    l_msg = l_conn.execute('SELECT * FROM T_messages WHERE id = ?', (id,)).fetchone()
    l_conn.close()
    if l_msg is None:
        abort(404)
    return l_msg


app = Flask(__name__)

@app.route('/')
def app_index():
    cnx = get_db_connection()
    msgs = cnx.execute('SELECT * FROM T_messages').fetchall()
    cnx.close()
    return render_template('index-4.html', jmsgs=msgs)

@app.route('/<int:msg_id>')
def app_show(msg_id):
    msg = get_message_from_db(msg_id)
    return render_template('show-message.html', jmsg=msg)