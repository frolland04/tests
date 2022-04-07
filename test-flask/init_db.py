import sqlite3

cnx = sqlite3.connect('database.sqlite')

with open('create_db_schema.sql') as f:
    cnx.executescript(f.read())

cur = cnx.cursor()

cur.execute("INSERT INTO T_messages (title, content) VALUES (?, ?)", ('Message 1', 'Content 1.'))
cur.execute("INSERT INTO T_messages (title, content) VALUES (?, ?)", ('Message 2', 'Content 2.'))

cnx.commit()
cnx.close()
