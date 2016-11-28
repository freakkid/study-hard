import hashlib
def encrypt_passwd(password):
    m = hashlib.md5()
    m.update(password)
    return m.digest()

a = "123"
a = encrypt_passwd(a)
print type(a)
