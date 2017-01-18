def ADD(a, b):
    print "ADD %d + %d" %(a, b)
    return a + b

def SUBTRACT(a, b):
    print "SUBTRACT %d - %d" %(a, b)
    return a - b

def MULTIPLE(a, b):
    print "MULTIPLE %d * %d" %(a, b)
    return a * b

def DIVIDE(a, b):
    print "DIVIDE %d / %d" %(a, b)
    return a / b

print "2 + 5 * 4 / 2 - 1", 2 + 5 * 4 / 2 - 1

sum = ADD(2, SUBTRACT(DIVIDE(MULTIPLE(5, 4), 2), 1))

print sum
