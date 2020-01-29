#!/usr/bin/python
# -*- coding: UTF-8 -*-

"""
Quelques essais avec le framework web Flask.
"""

# Quelques informations
__author__ = 'Frédéric ROLLAND'
__version__ = '1'

# Dépendances
import flask
import flask_bootstrap


app = flask.Flask(__name__)
flask_bootstrap.Bootstrap(app)


@app.route('/')
def www_slash() -> str:
    app.logger.debug('slash')
    return 'coucou, bienvenue sur cette page!'


@app.route('/test')
def www_test() -> str:
    app.logger.debug('test')
    return 'Vous vouliez un test?!'


@app.route('/test2')
def www_test2() -> str:
    app.logger.debug('test2')
    return 'Vous vouliez vraiment un test?!'


@app.route('/test3')
def www_test3() -> str:
    app.logger.debug('test3')
    return flask.redirect(flask.url_for('www_test2'))


@app.route('/test4')
def www_test4() -> str:
    app.logger.debug('test4')
    return flask.redirect('/')


@app.errorhandler(404)
def page_not_found(error) -> str:
    return 'Too bad!'


if __name__ == '__main__':
    app.run(debug=True)
