from cs50 import get_string
from sys import argv

if len(argv) != 2:
    exit("Usage: python caesar.py k")
plaintext = get_string("plaintext:  ")
cypher = ""
k = int(argv[1])
for c in plaintext:
    if c.isalpha():
        if c.isupper():
            plus = 65
        else:
            plus = 97
        new_c = c
        new_c = ord(new_c)
        new_c = chr((new_c - plus + k) % 26 + plus)
    else:
        new_c = c
    print(new_c)
    cypher = cypher + new_c
print(f"ciphertext: {cypher}")