#!usr/bin/env python3
# -*- coding:utf-8 -*-
# 生成随机数

import string
import random
# 模仿百度云盘生成四位数的提取密码，由不重复的十进制数字和英文字母组成
# 方法一：
seed = string.ascii_letters + string.digits
for i in range(4):
    sa.append(random.choice(seed))
sa = ''.join(sa)

# 方法二：
s = ''.join(random.sample(string.ascii_letters + string.digits, 4))


# 代码来自 http://m.blog.csdn.net/article/details?id=45341241
