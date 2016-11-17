# -*- coding:utf-8 -*-
"""
learn to use doctest
"""
def multiply(a, b):
    """
    >>> multiply(2, 3)
    6
    >>> multiply('a', 3)
    'aaa'
    """
    return a * b

if __name__ == '__main__':
    import doctest
    doctest.testmod(verbose=True)

# python -m doctest unnecessary_math.py
# python -m doctest -v unnecessary_math.py
