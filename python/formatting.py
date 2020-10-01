#!/usr/bin/python
# -*- coding: UTF-8 -*-

"""
Quelques tests de formatage en Python.
Je les mets sous forme de programme pour s'en souvenir facilement.
"""

# Quelques informations
__author__ = 'Frédéric ROLLAND'
__version__ = '1'

# Dépendances
import sys
import datetime


if __name__ == '__main__':
    print('coucou les gens !')

    print(sys.path, sys.version_info)

    tags = \
        {
            'PTEC': '',
            'PAPP': 0,
            'IINST': 0,
            'HCHC': 0,
            'HCHP': 0,
            'ADCO': 0,
            'ISOUSC': 0,
            'IMAX': 0,
            'OPTARIF': '',
            'HHPHC': '',
            'MOTDETAT': '',
            'OK': False
        }

    print(tags)

    request = """ UPDATE T_TELEINFO_INST set
            PTEC = %(PTEC)s,
            PAPP = %(PAPP)s,
            IINST = %(IINST)s,
            HC = %(HCHC)s,
            HP = %(HCHP)s,
            ADCO = %(ADCO)s,
            ISOUSC = %(ISOUSC)s,
            IMAX = %(IMAX)s,
            OPTARIF = %(OPTARIF)s,
            HHPHC = %(HHPHC)s,
            ETAT = %(MOTDETAT)s,
            TEMPERATURE = %(TEMPERATURE)s,
            RH = %(RH)s,
            TS = %(TS)s """

    print(request)

    tags2 = {'TEST_INT': 0, 'TEST_STR': 'OUI'}
    print(tags2)

    try:
        print("""01 toto""", tags2)
    except:
        print('01 FAILED!')

    try:
        print("""02 toto %(COCO)s""", tags2)
    except:
        print('02 FAILED!')

    try:
        print("""03 toto %(TEST_INT)s""", tags2)
    except:
        print('03 FAILED!')

    try:
        print('04 toto {COCO}', tags2)
    except:
        print('04 FAILED!')

    try:
        print('05 toto {COCO}'.format(tags2))
    except:
        print('05 FAILED!')

    try:
        print("""06 toto {TEST_INT}""".format(tags2))
    except:
        print('06 FAILED!')

    try:
        print("""07 toto {COCO}""".format(**tags2))
    except:
        print('07 FAILED!')

    try:
        print("""08 toto {TEST_INT}""".format(**tags2))
    except:
        print('08 FAILED!')

    try:
        print("""09 toto {COCO}""".format_map(tags2))
    except:
        print('09 FAILED!')

    try:
        print("""10 toto {TEST_INT}""".format_map(tags2))
    except:
        print('10 FAILED!')

    try:
        print("""11 toto {:5.1f}/{:5.1f}""".format(2, 3))
    except:
        print('11 FAILED!')

    try:
        print("""12 toto {:d}/{:s}""".format(round(2), 'toto'))
    except:
        print('12 FAILED!')

    try:
        ts = datetime.datetime.now()
        print("""12 toto {:d}/{:s}""".format(round(2), ts.strftime('%y-%m-%d')))
    except:
        print('12 FAILED!')

    try:
        ts = datetime.datetime.now()
        print("""13 toto %s,%s""" % (ts, 4))
    except:
        print('13 FAILED!')

    try:
        ts = datetime.datetime.now()
        print("""14 toto {:s}""".format(str(ts)))
    except:
        print('14 FAILED!')

    try:
        val = 12.8503
        val2 = round(val, 2)
        print("""15 toto {:.2f} {:f}""".format(val, val2))
    except:
        print('15 FAILED!')

    try:
        val = 1025.42
        print("""16 toto {:010.3f}""".format(val))
    except:
        print('16 FAILED!')

    print('FIN.')
