#-- coding:utf-8 --

from math import sqrt

def IsPrimer(num):
    if num == 1:
        return False
    if num > 1:
        for i in range(2, int(sqrt(num) + 1)):
            if num % i == 0:    
                return False
    else:
        return False
    return True

L = []
for i in range(1, 101):
    L.append(i)

for j in range(1, 101):
    if IsPrimer(j):        #判断是否为素数,是就删除
        L.remove(j)         

print L
