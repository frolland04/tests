from flask import Flask, render_template, request, url_for, flash, redirect
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
app.config['SECRET_KEY'] = 'Blablabla'

@app.route('/')
def app_index():
    cnx = get_db_connection()
    msgs = cnx.execute('SELECT * FROM T_messages').fetchall()
    cnx.close()
    return render_template('index-5.html', jmsgs=msgs)  # browser get the page ...

@app.route('/<int:msg_id>')
def app_show(msg_id):
    msg = get_message_from_db(msg_id)
    return render_template('show-message2.html', jmsg=msg)  # browser get the page ...

@app.route('/create', methods=('GET', 'POST'))
def app_create():
    if request.method == 'POST':
        title = request.form['title']
        content = request.form['content']

        if not title:
            flash('Title is required!')  # flash message !
        else:
            cnx = get_db_connection()
            cnx.execute('INSERT INTO T_messages (title, content) VALUES (?, ?)', (title, content))
            cnx.commit()
            cnx.close()
            return redirect(url_for('app_index'))  # new item successfully created, return to index page ! 

    return render_template('create-message.html')  # browser get the page ...

@app.route('/<int:msg_id>/edit', methods=('GET', 'POST'))
def app_edit(msg_id):
    msg = get_message_from_db(msg_id)

    if request.method == 'POST':
        title = request.form['title']
        content = request.form['content']

        if not title:
            flash('Title is required!')  # flash message !
        else:
            cnx = get_db_connection()
            cnx.execute('UPDATE T_messages SET title = ?, content = ? WHERE id = ?', (title, content, msg_id))
            cnx.commit()
            cnx.close()
            return redirect(url_for('app_index'))  # item successfully edited, return to index page ! 

    return render_template('edit-message.html', jmsg=msg)  # browser get the page ...

@app.route('/<int:msg_id>/delete', methods=('POST',))
def app_delete(msg_id):
    msg = get_message_from_db(msg_id)
    cnx = get_db_connection()
    cnx.execute('DELETE FROM T_messages WHERE id = ?', (msg_id,))
    cnx.commit()
    cnx.close()
    flash('"{}" was successfully deleted!'.format(msg['title']))  # flash message !
    return redirect(url_for('app_index'))  # item successfully deleted, return to index page ! 