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


def seconde_fonction(a=[]):
    """Petite fonction encore plus gentille"""
    a.append(1000)
    a.append('Les listes ne sont pas immuables, les listes en argument sont donc modifiables')
    return a


def jeu_parametres(*arguments) -> None:
    """
    On peut aussi jouer avec les paramètres d'une fonction,
    que l'on peut capturer dans un tuple.
    Et aussi spécifier le type de retour.
    """
    print('jeu_parametres', arguments)
    for p in arguments:
        print(p, type(p))

    return


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

    # Jouons avec les nombres, les chaînes et les tuples
    aa = 2
    print('aa=', aa)  # Plusieurs choses à afficher
    print('aa=' + str(aa))  # Concaténation de chaînes de caractères

    # Appels de fonctions sur immuables
    print(ma_fonction(a=aa))
    print(ma_fonction())

    print('aa=' + str(aa))  # immuable 'aa' non modifié par 'ma_fonction()' ! (nombres, chaînes, tuples)

    # Les paramètres d'une fonction sont transportés par un tuple
    jeu_parametres()
    a = 0
    b = 10
    c = 5.0
    jeu_parametres(a, b, c)

    # Jouons aussi avec les listes (non immuables)
    aaa = [2, "oui"]
    print('aaa=', aaa)
    print('retour ->', seconde_fonction(a=aaa)) # liste 'aaa' modifiée par la fonction !
    print('aaa=', aaa)
    for i, e in enumerate(aaa):
        print(i, '->', e)

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
