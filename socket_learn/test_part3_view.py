# test_view.py
import os


def start_menu():
    print 'a'
    print 'b'
    print 'c'
    print 'd'
    print '*************'
    return 1    
    

def start_to_do():
    start_menu() | os.system('> t.txt')
    oper = raw_input()
    print 'a'
    
start_to_do()
