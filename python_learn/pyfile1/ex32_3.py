one = [1, 1, 2, 2, 3, 4, 4, 5]
two = [5, 6, 7]

one.extend(two)

set_four = set(one)

print set_four[2]

print "one ", one

print "one[0] ", one[0]

print "one[1:5] ", one[-1:6]

del one[4]
print "after ", one

three = [one[0]] * 4
print three

