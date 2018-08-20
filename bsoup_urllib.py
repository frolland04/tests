from bs4 import BeautifulSoup
import urllib.request
import urllib.error
import re


def fouine(a, links):
    try:
        html_page = urllib.request.urlopen(a)
        soup = BeautifulSoup(html_page)

        for link in soup.findAll('a', attrs={'href': re.compile("^http://|^https://")}):
            if link.get('href') not in links:
                links.append(link.get('href'))
    except:
        print('Fouine() failed.')


if __name__ == "__main__":

    # Liste des URL (unique) à parcourir, à mesure de leur découverte
    cibles = list()
    cible_index = 0

    # Ici on gardera les URL des documents à conserver
    resultat = list()

    fouine('https://python.developpez.com/cours', cibles)

    while (cible_index != len(cibles)) and (cible_index < 5000):

        lien = cibles[cible_index]
        print(cible_index, len(cibles), len(resultat), lien)

        if ('py' in lien or 'Py' in lien) and ('forums' not in lien) and ('actu' not in lien) and ('.developpez.com/' in lien):
            if lien.endswith('.pdf'):
                print('YEAH!', len(resultat), lien)
                if lien not in resultat:
                    resultat.append(lien)
            else:
                if not (lien.endswith('.zip') or lien.endswith('.azw') or lien.endswith('.mobi') or lien.endswith('.epub')):
                    fouine(lien, cibles)

        cible_index += 1

    cibles.sort()

    fichier_cible = open('cibles.txt', 'w')
    for cible in cibles:
        fichier_cible.write('%s\n' % cible)

    resultat.sort()

    fichier_resultat= open('resultat.txt', 'w')
    for s in resultat:
        print(s)
        fichier_resultat.write('%s\n' % s)

    fichier_html = open('resultat.html', 'w')
    for s in resultat:
        print(s)
        fichier_html.write("<a href='%s'>%s</a><br>\n" % (s,s))

    fichier_cible.close()
    fichier_resultat.close()
    fichier_html.close()



