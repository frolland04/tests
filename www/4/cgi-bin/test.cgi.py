#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

# -----------------------------------------------------------
# Exemple d'une 'cgi' en Python

print('Content-type: text/html; charset=UTF-8\n\n')
print('<!DOCTYPE html>')
print("<html lang='FR'>")

print('<head>')
print("<meta http-equiv='Content-Type' content='text/html; charset=utf-8'/>")
print('<title>CGI PYTHON</title>')
print('</head>')

print('<body>')
print('Coucou depuis la CGI Python!<br><br>')
print('</body>')
print('</html>')

