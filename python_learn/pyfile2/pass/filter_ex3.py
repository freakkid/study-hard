#-- coding:utf-8 --

from math import sqrt

def IsNotPrimer(num):
    if num == 1:
        return True
    if num > 1:
        for i in range(2, int(sqrt(num) + 1)):
            if num % i == 0:    
                return True
    else:
        return True
    return False

L = []
for i in range(1, 101):
    L.append(i)


L = filter(IsNotPrimer, L)     

print L
