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
        print('BigTest', '__init__()', instance_id)
        self.instance_id = instance_id
        self.normal_exit_func = None
        self.unexpected_exit_func = None

    def __del__(self):
        print('BigTest', '__del__()', self.instance_id)

    def stuff(self, exc=None):
        print('BigTest', 'stuff', self.instance_id, exc)
        if exc is not None:
            raise exc

    def register_normal_exit_func(self, func):
        self.normal_exit_func = func

    def register_unexpected_exit_func(self, func):
        self.unexpected_exit_func = func

    def __enter__(self):
        print('BigTest', '__enter__()', self.instance_id)
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        print('BigTest', '__exit__()', self.instance_id, exc_type, exc_val, exc_tb)
        if exc_val is None and self.normal_exit_func:
            self.normal_exit_func()
        else:
            if exc_val is not None and self.unexpected_exit_func:
                self.unexpected_exit_func()
        return True


def destroy_notification():
    print('Boooom! Destruction!')


def release_notification():
    print('[Released.]')


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

                with BigTest('z') as z:
                    z.register_normal_exit_func(release_notification)
                    z.register_unexpected_exit_func(destroy_notification)

    with BigTest('f') as f, BigTest('g') as g:
        print('f,g?')
        f.register_normal_exit_func(release_notification)
        f.register_unexpected_exit_func(destroy_notification)
        g.register_normal_exit_func(release_notification)
        g.register_unexpected_exit_func(destroy_notification)

        f.stuff()
        f.stuff(KeyboardInterrupt)

        g.stuff()
        # g.stuff(SystemExit)

    sys.exit(0)
