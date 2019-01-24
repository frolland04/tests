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
    return "ma_fonction: " + 'Et oui!' + ' a=' + str(a) + ' (je ne peux pas modifier l\'argument effectif si c\'est un immuable)'


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
    print('jeu_parametres: arguments=', arguments)
    for p in arguments:
        print(p, type(p))

    return


def coucou(ss, j=0) -> str:
    """Fonction basique qui retourne une chaîne de caractères formées par 'La phrase ... coucou ...'
    et la chaîne 'ss' et l'entier j passés en arguments. Les types sont vérifiés.
    """
    if type(ss) is str and type(j) is int:
        return "La phrase pour {0} est: 'coucou {0}, comment ça va?' ({1})".format(ss, j)
    else:
        return 'KO'


def enter_exit(f):
    """Un petit décorateur de fonction"""
    def wrapper(*args):
        """
        La fonction wrapper est interne à enter_exit()
        Note : très important, elle accède à tout ce qui est dans enter_exit(), y compris les paramètres !
        """
        print('ENTER =>', f.__name__, args)
        obj = f(*args)
        print('EXIT <=', f.__name__, ':', obj, type(obj))
        return obj
    return wrapper


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
    print('')

    # Jouons avec les nombres, les chaînes et les tuples
    aa = 2
    print('Avant: aa=', aa)  # Plusieurs choses à afficher
    print('Avant: aa=' + str(aa))  # Concaténation de chaînes de caractères

    # Appels de fonctions sur immuables (nombres, chaînes, tuples)
    print(ma_fonction(a=aa))
    print(ma_fonction())

    print('Après: aa=' + str(aa))  # immuable 'aa' non modifié par 'ma_fonction()' ! (nombres, chaînes, tuples)
    print('')

    # Les paramètres d'une fonction sont transportés par un tuple
    jeu_parametres()
    a = 0
    b = 10
    c = 5.0
    jeu_parametres(a, b, c)
    print('')

    # Fonctions en argument, fonctions internes et décorateurs
    phrase_coucou_a_une_personne = coucou
    print(phrase_coucou_a_une_personne(s))
    ss = ma_fonction(4)
    print(ss)
    print('')

    f2 = enter_exit(ma_fonction)
    ss = f2(4)
    print(ss)
    print('')

    # Jouons aussi avec les listes (non immuables)
    aaa = [2, "oui"]
    print('aaa=', aaa)
    print('retour ->', seconde_fonction(a=aaa))  # liste 'aaa' modifiée par la fonction !
    print('aaa=', aaa)
    for i, e in enumerate(aaa):  # Enumérer les éléments d'une liste
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
