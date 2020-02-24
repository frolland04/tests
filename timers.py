import threading
import sys, time

def my_function():
    print(my_function.__name__)
    print('my_function sleeps 3s ...')
    time.sleep(3)
    print('... my_function slept 3s.')
    return


class MyPeriodicTimer:
    def __init__(self, f, p):
        print('__init__()')
        self.f = f
        self.p = p
        self.c = True
        self.t = threading.Timer(self.p, self.run)

    def __del__(self):
        print('__del__()')

    def run(self):
        print('run()')
        self.f()
        if self.c:
            self.t = threading.Timer(self.p, self.run)
            self.t.start()
        else:
            print('cancelled.')

    def start(self):
        print('start()')
        self.t.start()

    def stop(self):
        print('stop()')
        self.t.cancel()
        self.c = False


if __name__ == "__main__":
    print("Visual Studio Code vous dit Bonjour!")

    t = MyPeriodicTimer(my_function, 1)
    t.start()

    try:
        while True:
            print('This is the main loop that does nothing. Back in 10s. Timer should be running.')
            time.sleep(10.0)
    except KeyboardInterrupt:
        print('Stopping..')
        t.stop()

    print('END!')




