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
def ma_fonction(a=0):
    """Petite fonction gentille"""
    a += 1
    return 'Et oui!' + ' a=' + str(a) + '(je ne peux pas modifier l\'argument effectif immuable)'


# On commence par là
if __name__ == '__main__':
    """Code à exécuter"""

    # Quelques informations sur le runtime Python
    print(sys.api_version, sys.version)
    print(time.asctime())

    # Affichage et entrée au clavier
    print('**** Hello Word! ****')
    s = input('Quel est ton prénom?\n')
    print('Bonjour', s)

    aa = 2
    print('aa=', aa)  # Plusieurs choses à afficher
    print('aa=' + str(aa))  # Concaténation de chaînes de caractères

    # Appels de fonctions
    print(ma_fonction(a=aa))
    print(ma_fonction())

    print('aa=' + str(aa))  # immuable 'aa' non modifié par 'ma_fonction()' ! (nombres, chaînes, tuples)

    input('(Appuyez sur une touche...)')

    print('**** Symboles : ****')
    print('Le type de "dir()" est', type(dir))
    print('Le type de retour de "dir()" est', type(dir()))

    print(dir())
    print('Le contenu est :')

    for e in dir():
        print(e)

    input('(Appuyez sur une touche...)')

    phrase = 'La vie est belle, la belle est douce, la vie est douce.'
    print('une chaîne ->', phrase)

    # Modifications d'une chaîne de caractères
    phrase = phrase.replace('.', '')
    phrase = phrase.replace(',', '')
    phrase = phrase.lower()
    print(phrase)

    # Découpage en mots puis tri alpha
    tokens = phrase.split(' ')
    print('une liste ->', tokens)
    tokens.sort()

    # Un dict. pour comptabiliser les répétitions
    m = {}
    for t in tokens:
        if t in m:
            m[t] += 1
        else:
            m[t] = 1
    print('un dict. ->', m)

    for t in m:
        print(t, tokens.count(t), '/', len(tokens))

    print("*** C'est fini pour aujourd'hui ! ***")
