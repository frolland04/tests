#!/usr/bin/python3

# sudo -H python3 -m pip install pip --upgrade
# sudo -H python3 -m pip install simple_websocket_server


from simple_websocket_server import WebSocketServer, WebSocket
import json
import time
import threading


class SimpleEcho(WebSocket):
        
    def handle(self):
        print(self.data)
        try:
            jsn = json.loads(self.data)
            print(jsn, type(jsn))
            
            if jsn['value'] is not None:
                self.__i = jsn['value']
                self.send_message('{"success": True}')
                self.f()
                
        except Exception as e:
            print('???', e)
            

    def connected(self):
        print(self.address, 'connected')
        

    def handle_close(self):
        print(self.address, 'closed')
        
    
    def f(self):
        print('f', self.__i)
        self.__i += 1
        self.send_message('{"value": ' + str(self.__i) + '}')
        
        t = threading.Timer(0.2, self.f)
        t.start()        


if __name__ == "__main__": 
    server_address = ''
    server_port = 8000
    server = WebSocketServer(server_address, server_port, SimpleEcho)
    
    print('serving at %s:%d' % (server_address, server_port))
    server.serve_forever()
