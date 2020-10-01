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
        self.normal_exit_arg = None
        self.unexpected_exit_func = None
        self.unexpected_exit_arg = None
        self.unexpected_exit_suppress_exc = True

    def __del__(self):
        print('BigTest', '__del__()', self.instance_id)

    def register_normal_exit_func(self, func, arg=None):
        self.normal_exit_func = func
        self.normal_exit_arg = arg

    def register_unexpected_exit_func(self, func, arg=None, suppress_exc=True):
        self.unexpected_exit_func = func
        self.unexpected_exit_suppress_exc = suppress_exc
        self.unexpected_exit_arg = arg

    def __enter__(self):
        print('BigTest', '__enter__()', self.instance_id)
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        print('BigTest', '__exit__()', self.instance_id, exc_type, exc_val, exc_tb)
        if exc_val is None and self.normal_exit_func is not None:
            self.normal_exit_func(self.normal_exit_arg)
        else:
            if exc_val is not None and self.unexpected_exit_func is not None:
                self.unexpected_exit_func(self.unexpected_exit_arg)
        return self.unexpected_exit_suppress_exc


class OtherTest:
    def __init__(self, instance_id):
        print('OtherTest', '__init__()', instance_id)
        self.instance_id = instance_id
        self.ct = BigTest(instance_id)

    def __del__(self):
        print('OtherTest', '__del__()', self.instance_id)

    def __enter__(self):
        print('OtherTest', '__enter__()', self.instance_id)
        self.ct.__enter__()
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        print('OtherTest', '__exit__()', self.instance_id, exc_type, exc_val, exc_tb)
        return self.ct.__exit__(exc_type, exc_val, exc_tb)


def destroy_notification(s):
    print('Boooom! Destruction!', s)


def release_notification(s):
    print('[Released.]', s)


if __name__ == '__main__':
    print('>>> coucou les gens !')

    print('>>> plain sequence of object creation...')
    a = BigTest('a')
    b = BigTest('b')

    print('>>> hierarchical contexts of object creation...')
    with BigTest('c') as c:
        print('c?')

        with BigTest('d') as d:
            print('d?')

            with BigTest('e') as e:
                print('e?')

                with BigTest('z') as z:
                    z.register_normal_exit_func(release_notification, ('zN',))
                    z.register_unexpected_exit_func(destroy_notification, ('zU',))
                    raise SystemExit

    print('>>> collapsed contexts of object creation...')
    with BigTest('f') as f, BigTest('g') as g:
        print('f,g?')
        f.register_normal_exit_func(release_notification)
        f.register_unexpected_exit_func(destroy_notification, 'fU', True)
        g.register_normal_exit_func(release_notification)
        g.register_unexpected_exit_func(destroy_notification, 'gU', False)
        raise KeyboardInterrupt

    print('>>> dedicated object...')
    with OtherTest('o') as o:
        print('o?')

        with OtherTest('oo') as oo:
            print('oo?')
            oo.ct.register_normal_exit_func(release_notification, ('ooN',))
            oo.ct.register_unexpected_exit_func(destroy_notification, ('ooU',))
            raise SystemExit

    print('>>> end of scope...')
    sys.exit(0)
