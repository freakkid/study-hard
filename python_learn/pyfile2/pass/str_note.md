
string = "123456789"

# string.count(substr, start = 0, end = 0)
  返回子字符串的个数

# 解码字符串
    str.decode(encoding = 'UTF-8', error = 'strict')
   
    error: 'strict':遇到非法字符抛出异常
            'ignore':忽略非法字符;
            'replace':会用?取代非法字符
  编码字符串
  str.encode(encoding = 'UTF-8', error = 'strict')
   
# r/R
    所有字符串按照字面的意思来的意思来使用
    print r'a\nb'   # print R'a\nb'
输出:   a\nb

# u'str' unicode字符串
# string.center(width)
 返回一个原字符串居中，并使用空格填充至长度width的新字符串

# 找str在不在string中，返回下标
  string.find(str, start = 0, end = len(string))
  不存在则返回 -1
  string.rfind(str, start = 0, end = len(string))
  string.index(str, start = 0, end = len(string))
  rindex()
  不存在会报一个异常
# string.isalnum()      True 字母或数字
1.  string.isalpha()      True 字母  string.isdigit()      True 数字
( string.isdecimal()    只有十进制数字;  srting.isnumeric()    数字)
2.  isspace()             True 只有空格
    istitle()             True 如果str是标题化
    isupper() islower()
3.  lower()  upper()
    swapcase()  翻转大小写
4.  max(str)    min(str)  返回最大或最小的字符
5.  str.join(seq)  以str 作为分隔符连接seq
6.  str.ljust(width)  返回一个原字符串左对齐，并使用空格填充至长度为wiidth的新字符串
    str.r"just(width)
    str.zfill(width)   原字符串右对齐,前面充000000
7.  删除空格： str.strip() str.lstrip() str.rstrip()
8.  str.maketrans(intab, outtab)
    创建字符映射的转换表
    eg.intab = "abcde" ,outtab = "12345"
    trantab = maketrans(intab, outtab)
    str = "asdcvbert"
    print str.translate(trantab)
    # 1s43v25rt
    
    str.translate(table[, deletechars])
    table 翻译表，来自maketrans
    deletechars 字符串中要过滤的字符列表
    print str.translate(trantab, 'rt')
    # 1s43v25
    
9.  str.replace(str1, str2, num = string.count(str1))
    把str中str1替换成str2,如果num指定则不超过num次
    
10. string.partition(str)
    eg.  a = "cii.wuhcw.wuuw.wnijw"
         a.partition('.')
         # ('cii', '.', 'wuhcw.wuuw.wnijw')
    string.rpartition(str) 从右开始找起

11. string.split(str = ' ', num)
    通过分隔符（默认空格）对字符串进行切片，如果num有指定，仅分割num个子字符串，返回分割后的字符串列表
    q.split('.', 1)
    ['iohq', 'hhudi.hid']

12. strip('char')  lstrip() rstrip()
    移除字符

13. string.startswith(obj, beg = 0, end = len(string))
    是否以obj开头
14. splitlines([keepends])
    按照换行符（\r \r\n \n）分隔，返回一个包含各行作为元素的列表
    keepends--在输出结果里是否去掉换行符（\r \r\n \n）默认为False
15. format()
    通过{}代替%
    1)通过位置:
    可以接受不限个参数，位置可以不按顺序，可以不用或用多次，2.7以上{}才可以为空
    
'{0} {1} {0}'.format('kl',18)
  # kl 18 kl

    2)通过关键字参数
    '{a}{b}'.format(a = 18, b = 'hajk')
    
    3)通过下标
    p = ['dd',18]
    '{0[0]},{0[1]}'.format(p)
    
    4)通过对象属性
    
    5)格式限定符
        1)填充对齐 
        ^ 居中 < 左对齐 > 右对齐
        : 后面带填充的字符，只能一个字符，默认为空格 
        '{:0>8}.format('123')
        # 00000123
        2)精度
        {:.2f}.format('123.456789)
        # 123.45
        3)进制类型
        b d o x
        {:b}.format(17)
        # 10001
    6)作为金额的千位分隔符
        '{:,}'.format(num)
        num是数字


