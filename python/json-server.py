#!/usr/bin/env python3
"""An example HTTP server with GET and POST endpoints."""

from http.server import HTTPServer, BaseHTTPRequestHandler
from http import HTTPStatus
import json
import time


# Sample blog post data similar to
# https://ordina-jworks.github.io/frontend/2019/03/04/vue-with-typescript.html#4-how-to-write-your-first-component
_blog_post = {
    'title': 'HELLO WORLD!',
    'body': 'Lorem ipsum dolor sit amet.',
    'author': 'Frédéric ROLLAND',
    'date_ms': 1593607500000,  # 2020 July 1 8:45 AM Eastern
}


class _RequestHandler(BaseHTTPRequestHandler):
    # Borrowing from https://gist.github.com/nitaku/10d0662536f37a087e1b
    def _set_headers(self):
        self.send_response(HTTPStatus.OK.value)
        self.send_header('Content-type', 'application/json')
        # Allow requests from any origin, so CORS policies don't
        # prevent local development.
        self.send_header('Access-Control-Allow-Origin', '*')
        self.end_headers()

    def do_GET(self):
        print('Receiving GET from', self.client_address, '...')
        self._set_headers()
        self.wfile.write(json.dumps(_blog_post).encode('utf-8'))

    def do_POST(self):
        print('Receiving POST from', self.client_address, '...')
        length = int(self.headers.get('content-length'))
        message = json.loads(self.rfile.read(length))
        print(message)
        self._set_headers()
        self.wfile.write(json.dumps({'success': True}).encode('utf-8'))

    def do_OPTIONS(self):
        # Send allow-origin header for preflight POST XHRs.
        self.send_response(HTTPStatus.NO_CONTENT.value)
        self.send_header('Access-Control-Allow-Origin', '*')
        self.send_header('Access-Control-Allow-Methods', 'GET, POST')
        self.send_header('Access-Control-Allow-Headers', 'content-type')
        self.end_headers()


def run_server():
    server_address = ('', 8001)
    httpd = HTTPServer(server_address, _RequestHandler)
    print('serving at %s:%d' % server_address)
    httpd.serve_forever()


if __name__ == '__main__':
    run_server()
