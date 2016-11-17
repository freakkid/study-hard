def multiply(a, b):
    return a * b

def test_numbers():
    assert multiply(3, 4) == 12

def test_strings():
    assert multiply('a', 3) == 'aaa'

# nosetests test.py
# python -m nose test.py
