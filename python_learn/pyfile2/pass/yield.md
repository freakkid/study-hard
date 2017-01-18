关于yield 和 generator的笔记，整理自下面的网站
https://www.ibm.com/developerworks/cn/opensource/os-cn-python-yield/
http://pyzh.readthedocs.io/en/latest/the-python-yield-keyword-explained.html#id6




#1.引入：
def fab(max):
    n, a, b = 0, 0, 1
    while n < max:
        print b
        a, b = b, a + b
        n = n + 1
fab(5)
函数复用性差，返回一个None,而不是一个List

class Fab(object):
    def __init__(self, max):
        self.max = max
        self.n, self.a, self.b = 0, 0, 1
        
    def __iter__(self):
        return self
    
    def next(self):
        if self.n < self.max:
            r = self.b
            self.a, self.b = self.b, self.a + self.b
            self.n += 1
            return r
        raise StopIteration()

------------------------------------------
def fab(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield b
        a, b = b, a + b
        n += 1

执行：f = fab(5)
      f.next()  #多次
      # 执行结束时，generator自动抛出 StopIteration 异常表示迭代完成，在循环中正常结束
      
      
=========================================
#2.介绍

 * generator函数，调用时内部代码不立马执行，而是返回一个生成器对象，代码在for循环时执行
 
 * 生成器是可以迭代，但只可以读取它一次（只能被迭代一次，即使用一次for i in mygenerator），实时生成数据
----------------KEY------------

 * 第一次迭代中，代码执行到yield，后返回yield后的值作为第一次迭代的返回值，然后，每次执行这个函数都会继续执行你在函数内部定义的那个循环的下一次，再返回那个值，直到没有可以返回的
 * 如果生成器内部没有定义 yield 关键字，会被认为成空：可能是因为循环进行没了，或没有满足 if/else 条件
 * 生成器好处：不必读两次所有值，可以有很多子对象，但不必叫他们都存储在内存里面



#3.区分
 * 判断是否是一个特殊的 generator 函数
from inspect import isgeneratorfunction
isgeneratorfunction(fab)  //True
 * fab : 是一个generator函数
   fab(5) : 是调用fab返回的一个generator
import types
isinstance(fab, type.GeneratorType)  // False
isinstance(fab(5), type.GeneratorType)  // True
 * fab : 无法迭代
   fab(5) : 可迭代
from collection import Iterable
isinstance(fab, Iterable)       // False
isinstance(fab(5), Iterable)       // True
 * 每次调用fab函数都会生成一个新的 generator 实例，各实例互不影响：
f1 = fab(5)
f2 = fab(5)

 * 在generation function中如果没有return, 默认执行至函数完毕，如果在执行过程中return,则直接跑出StopIteration终止迭代

================================================

# yield与文件读取
如果直接用read()读取，会导致不可预测的内存占用，好的方法是利用固定长度的缓冲区来不断读取文件内容

def read_file(fpath):
    BLOCK_SIZE = 1024
    with open(fpath, 'rb') as f:
        while True:
            block = f.read(BLOCK_SIZE)
            if block:
                yield block
            else:
                return

#4.
迭代是一个实现可迭代对象（实现的是__iter__() 方法）和迭代器（实现的是__next__() 方法）的过程。可迭代对象是你可以从其获取一个迭代器的任一对象，迭代器是那些允许迭代你可迭代对象的对象。


      
      
      
      
      
   
