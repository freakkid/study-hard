class MyError(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return repr(self.value)

def MyFunction():
    raise MyError(2*2)    

if __name__ == '__main__':
    MyFunction()    
