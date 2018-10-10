
# python -m pip install --upgrade pip
# python -m pip install --upgrade BeautifulSoup4

from bs4 import BeautifulSoup
import urllib.request
import urllib.error
import re
import os, glob
import browser_cookie3
import wget  # DEBUG!


def fouine(a, links):
    """Contacte et fouine dans l'URL web passée en 1er paramètre, rajoute dans le conteneur passé en 2ème paramètre
    les URLs des balises HTML 'href' renvoyées dans la réponse par le serveur web que l'on contacte"""
    try:
        # Contacte le serveur avec urllib et attend la réponse
        html_page = urllib.request.urlopen(a)
        # Parse la réponse avec BeautifulSoup
        soup = BeautifulSoup(html_page)

        for link in soup.findAll('a', attrs={'href': re.compile("^http://|^https://")}):
            # Ne rajoute les URLs que si elles n'y sont pas déjà
            if link.get('href') not in links:
                links.append(link.get('href'))
    except:
        print('Fouine() failed.')


if __name__ == "__main__":

    # Liste des URL (unique) à parcourir, à mesure de leur découverte
    cibles = list()
    cible_index = 0

    # Ici on gardera les URL des documents à conserver
    resultats = list()

    fouine('https://python.developpez.com/cours', cibles)

    while (cible_index != len(cibles)) and (cible_index < 5000):

        lien = cibles[cible_index]
        print(cible_index, len(cibles), len(resultats), lien)

        if ('py' in lien or 'Py' in lien) and ('forums' not in lien) and ('actu' not in lien) and ('.developpez.com/' in lien):
            # Il n'y a que les PDF et les ZIP qui m'intéresse
            if lien.endswith('.pdf') or lien.endswith('.zip'):
                print('YEAH!', len(resultats), lien)
                # Si on a pas encore ce document, on l'ajoute aux résultats
                if lien not in resultats:
                    resultats.append(lien)
            else:
                # On ne fouine pas dans les documents complexes
                if not (lien.endswith('.azw') or lien.endswith('.mobi') or lien.endswith('.epub')):
                    fouine(lien, cibles)

        cible_index += 1

    cibles.sort()

    # Construisons un fichier avec toutes les URLs traitées (même celles ignorées)
    fichier_cibles = open('cibles.txt', 'w')
    for cible in cibles:
        fichier_cibles.write('%s\n' % cible)

    resultats.sort()

    # Construisons un fichier avec toutes les URLs des documents conservés
    fichier_resultats= open('resultats.txt', 'w')
    for s in resultats:
        print(s)
        fichier_resultats.write('%s\n' % s)

    # Le même sous forme de liens HTML
    fichier_html = open('resultats.html', 'w')
    for s in resultats:
        print(s)
        fichier_html.write("<a href='%s'>%s</a><br>\n" % (s,s))

    fichier_cibles.close()
    fichier_resultats.close()
    fichier_html.close()

    print('Récupération ...')

    # Téléchargement des URLs retenues dans un dossier dédié
    dossier_sauve = os.getcwd() + '/downloads'
    if os.path.exists(dossier_sauve):
        fichiers = glob.glob(dossier_sauve + '/*')
        for f in fichiers:
            os.remove(f)
        os.rmdir(dossier_sauve)

    os.mkdir(dossier_sauve)

    cj = browser_cookie3.firefox()
    print(cj)
    opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cj))
    urllib.request.install_opener(opener)

    for s in resultats:
        print('->', s)
        obj = urllib.request.urlopen(s)
        print(type(obj), obj)
        body = obj.read()
        print(type(body), len(body))

        wget.download(s,dossier_sauve)
