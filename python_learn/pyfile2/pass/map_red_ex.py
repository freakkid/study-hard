# -- coding:utf-8 --
#利用map()函数，把用户输入的不规范的英文名字，变为首字母大写，其他小写的规范名字。输入：['adam', 'LISA', 'barT']，输出：['Adam', 'Lisa', 'Bart']。

#Python提供的sum()函数可以接受一个list并求和，请编写一个prod()函数，可以接受一个list并利用reduce()求积。

from string import capitalize


print map(capitalize, ['adam', 'LISA', 'barT'])

def prod(l):
    def mul(x, y):
        return x * y
    return reduce(mul, l)
    
t = [2, 3, 4, 5, 7, 0]
print prod(t)
