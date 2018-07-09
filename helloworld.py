"""Quelques tests basiques en Python.
Je les mets sous forme de programme pour s'en souvenir facilement
"""

# Quelques informations
__author__ = 'Frédéric ROLLAND'
__version__ = '1'


# Importations
import sys
import time


# Quelques fonctions
def ma_fonction(a):
    """Petite fonction gentille"""
    return 'Et oui!' + ' a=' + str(a)


# On commence par là
if __name__ == '__main__':
    """Code à exécuter"""

    print(sys.api_version, sys.version)
    print(time.asctime())

    print('**** Hello Word! ****')
    s = input('Quel est ton prénom?\n')
    print('Bonjour', s)

    print(ma_fonction(a=2))

