website = {1: "google", "sec": "baidu", 3: "facebook", "twitter": 4}

print website.keys()

print website.values() 

print website.items()

print "__key__"
# print the key
for key in website.keys():
    print key, type(key)
    
print "_____"

for key in website:
    print key, type(key)
    
print "__value__"

# print the value
for value in website.values():
    print value

print "_____"

for key in website:
    print website[key]

print "__items__"

#print items

for k, v in website.items():
    print str(k) + ":" + str(v)

print "_____"

for k in website:
    print str(k) + ":" + str(website[k])





