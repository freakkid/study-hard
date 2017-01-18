# -- coding: utf-8 --
x = "There are %d types of people." % 10
# binary是一个字符串
binary = "binary"
do_not = "don't"
# %s %s的位置是两个字符串
y = "Those who know %s and those who %s." % (binary, do_not)
# 打印出字符串x, y
print x
print y
# 
print "I said: %r." % x
print "I also said: '%s'." % y

hilarious = False
joke_evaluation = "Isn't that joke so funny?! %r"

print joke_evaluation % hilarious

w = "This is the left side of..."
e = "a string with a right side."

print w + e + x
