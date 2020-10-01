#!/usr/bin/python
# -*- coding: UTF-8 -*-

"""
Quelques trucs sympas avec BeautifulSoup4 et Urllib
"""

# Quelques informations
__author__ = 'Frédéric ROLLAND'
__version__ = '1'

# Dépendances
import MySQLdb  # Besoin de "mysqlclient"
import datetime
import random

# *** Notes sur la création de la table, par exemple dans Mysql-Workbench ou HeidiSQL ***
# CREATE TABLE `test` (
#   `tm` datetime(6) NOT NULL,
#   `val1` int(11) DEFAULT NULL,
#   `val2` int(11) DEFAULT NULL,
#   PRIMARY KEY (`tm`)
# ) ENGINE=InnoDB DEFAULT CHARSET=latin1;


# *** Notes sur "mysqlclient" ***
# Nécessite sur le système : python3, python3-pip, python3-dev et libmysqlclient-dev
# >>>> sudo apt-get update
# >>>> sudo apt-get install python3 python3-pip python3-dev libmysqlclient-dev
# Nécessite dans python : mysqlclient
# >>>> python3 -m pip install --upgrade pip
# >>>> python3 -m pip install mysqlclient


class Database:
    USER_NAME = 'test'
    USER_PASSWORD = 'test'
    DATABASE_NAME = 'test'

    def __init__(self):
        """Quand on crée un objet Database, on obtient directement une connexion à la BDD"""
        print('DATABASE_NAME=' + self.DATABASE_NAME)

        self.connection = MySQLdb.connect('localhost', self.USER_NAME, self.USER_PASSWORD, self.DATABASE_NAME)
        self.engine = self.connection.cursor()


if __name__ == "__main__":
    print("coucou!")

    db = Database()

    # Une première requête de contenu
    db.engine.execute("SELECT * FROM test")
    res = db.engine.fetchall()

    # On affiche tout :-)
    print("!>>>", res)

    # On insère 10 lignes avec des valeurs : le timestamp et des valeurs aléatoires
    for i in range(10):
        print("+", i)
        db.engine.execute("INSERT INTO test VALUES (%s,%s,%s)", (datetime.datetime.now(),
                                                                 random.randint(-99999, 99999),
                                                                 random.randint(0, 999)))
    # Il est temps de répercuter définitivement ces modifications
    db.connection.commit()

    # Une seconde fois on requête le contenu
    db.engine.execute("SELECT * FROM test")
    res = db.engine.fetchall()

    # On affiche tout, cette fois on saute des lignes pour y voir clair
    for i in range(len(res)):
        print("!>>>", res[i])

    print("len =", len(res))

    print("bye bye!")
