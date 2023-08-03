#!/usr/bin/python3

import apt

if __name__ == '__main__':
    print('coucou!')

    # First of all, open the cache
    cache = apt.Cache()

    # Now, lets update the package list
    # try:
    #     cache.update()
    # except apt.cache.FetchFailedException:
    #     pass

    # We need to re-open the cache because it needs to read the package list
    cache.open(None)

    print(f'{len(cache)} packages')

    pkg_name = "qtbase5-dev"
    pkg_exists = pkg_name in cache

    print(f'Has package {pkg_name}: {pkg_exists}')
    pkg = None

    if pkg_exists:
        pkg = cache.get(pkg_name)
        print('>>>', pkg, pkg.fullname, pkg.candidate)
        for d in enumerate(pkg.candidate.dependencies):
            print(d[0], d[1])

    print('finishing', pkg)
    print('bye bye!')
