# -*- coding:utf-8 -*-


# 默认根据第一个元素排序
L = [('b', 6), ('a', 1), ('c', 3), ('d', 4)]
L.sort()
# L.sort(reverse=True)
print L


# 根据第二个元素排序
# 自定义排序逻辑
L = [('b', 6), ('a', 1), ('c', 3), ('d', 4)]
L.sort(lambda x, y: cmp(x[1], y[1]))
print L

# [('a', 1), ('c', 3), ('d', 4), ('b', 6)]


# 使用key参数，对每一行的第二列排序
L = [('b', 6), ('a', 1), ('c', 3), ('d', 4)]
L.sort(key=lambda x:x[1])
print L
# [('a', 1), ('c', 3), ('d', 4), ('b', 6)]

# 先对第二列排序再对第一列排序
L = [('b', 6), ('a', 1), ('c', 3), ('d', 4)]
L.sort(key=lambda x:(x[1], x[0]))
print L


