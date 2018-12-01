"""Quelques tests de sérialisation/désérialisation en Python.
Je les mets sous forme de programme pour s'en souvenir facilement
"""

import sys
import datetime
import json


# Quelques informations
__author__ = 'Frédéric ROLLAND'
__version__ = '1'


if __name__ == '__main__':
    print('coucou les gens !')

    z = dict()
    z['toto'] = 4
    z['i'] = 4
    z['j'] = 12.0
    z['liste1'] = (2, 3, 5)
    z['liste2'] = [2, 5, 7]
    z[2] = 'totoXXX'
    z['version'] = sys.api_version
    z['date'] = datetime.datetime.now().isoformat()

    print(z)

    print(json.dumps(z, sort_keys=False, indent=4))