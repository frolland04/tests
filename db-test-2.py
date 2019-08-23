#! python3

# -*- coding: UTF-8 -*-

# Dépendances
import MySQLdb as dbapi
# Besoin de MySQLdb "mysqlclient" (100% python)
# ou
# Besoin de MySQL "Connector/Python" (100% python ou C natif lorsque disponible)
# -> import mysql.connector as dbapi
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
# Nécessite dans python : mysqlclient ou mysql Connector/Python
# >>>> python3 -m pip install --upgrade pip
# >>>> python3 -m pip install mysqlclient
# ou
# >>>> python3 -m pip install mysql-connector-python


class Database:
    USER_NAME = 'test'
    USER_PASSWORD = 'test'
    DATABASE_NAME = 'test'

    def __init__(self):
        """Quand on crée un objet Database, on obtient directement une connexion à la BDD"""
        print('DATABASE_NAME=' + self.DATABASE_NAME)

        self.connection = dbapi.connect(host='localhost',
                                        user=self.USER_NAME,
                                        password=self.USER_PASSWORD,
                                        database=self.DATABASE_NAME)

        self.engine = self.connection.cursor()


if __name__ == "__main__":
    print("Coucou !", "(", datetime.datetime.now(), ")")

    db = Database()

    # On insère 100000 lignes avec des valeurs : le timestamp et des valeurs aléatoires
    sql = "INSERT INTO test VALUES (%s,%s,%s)"
    values = []
    for i in range(100000):
        values.append((datetime.datetime.now(), random.randint(-99999, 99999), random.randint(0, 999)))

    db.engine.executemany(sql, values)
    print("Insert OK.", "(", datetime.datetime.now(), ")")

    # Il est temps de répercuter définitivement ces modifications
    db.connection.commit()
    print("Commit OK.", "(", datetime.datetime.now(), ")")

    # Une seconde fois on requête le contenu
    db.engine.execute("SELECT COUNT(*) FROM test")
    res = db.engine.fetchall()
    print("Select OK.", "(", datetime.datetime.now(), ")")

    # On affiche tout, cette fois on saute des lignes pour y voir clair
    for i in range(len(res)):
        print("!>>>", res[i])

    print("len =", len(res))

    db.engine.close()

    print("bye bye!")
