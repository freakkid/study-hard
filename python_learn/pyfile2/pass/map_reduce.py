# --coding:utf-8--
def str2int(s):
    def char2num(s):
        return {'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9}[s]
    def fn(x, y):
        return x * 10 + y
    return reduce(fn, map(char2num, s))

print str2int("13579")


#用lambda函数进一步简化:

def char2num(s):
    return {'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9}[s]
def str2int(s):
    return reduce(lambda x, y: x * 10 + y, map(char2num, s))
print str2int("82042")
