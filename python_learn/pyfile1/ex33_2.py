def loop(i, number):
    while i < 6:
        print "Now i's value is : %d " % i
        number.append(i)
        print "Now num:", number
        i = i + 1

num = []
j = 0
loop(j, num)
print "Now j's value is : %d " % j
print num

num1 = range(1, 5)
print "num1 = ", num1

num2 = []
for i in range(0, 4):
    print "i = ", i
    num2.append(i)
    #i = i + 1
    print "now i = ", i
    
print "num2 = ", num2


