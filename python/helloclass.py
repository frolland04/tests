#!/usr/bin/python
# -*- coding: UTF-8 -*-

"""
Quelques essais sur les classes Python.
Je les mets sous forme de programme pour s'en souvenir facilement.
"""

# Quelques informations
__author__ = 'Frédéric ROLLAND'
__version__ = '1'

# Dépendances
import sys
import time

if __name__ == "__main__":
    print(time.ctime(), 'coucou!')
    time.sleep(2)
    print(time.ctime(), 'fin.')
    sys.exit(0)
