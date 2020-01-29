#!/usr/bin/python
# -*- coding: UTF-8 -*-

"""
Quelques tests de gestion structurée des erreurs.
Je les mets sous forme de programme pour s'en souvenir facilement.
"""

# Quelques informations
__author__ = 'Frédéric ROLLAND'
__version__ = '1'

# Dépendances
import sys


class BigTest:
    def __init__(self, instance_id):
        print('__init__', instance_id)
        self.instance_id = instance_id

    def __del__(self):
        print('__del__', self.instance_id)

    def stuff(self, exc=None):
        print('stuff', self.instance_id, exc)
        if exc is not None:
            raise exc

    def __enter__(self):
        print('__enter__', self.instance_id)
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        print('__exit__', self.instance_id, exc_type, exc_val, exc_tb)


if __name__ == '__main__':
    print('coucou les gens !')

    a = BigTest('a')
    b = BigTest('b')

    with BigTest('c') as c:
        print('c?')

        with BigTest('d') as d:
            print('d?')

            with BigTest('e') as e:
                print('e?')

    with BigTest('f') as f, BigTest('g') as g:
        print('f,g?')
        f.stuff()
        g.stuff(SystemExit)

    sys.exit(0)
