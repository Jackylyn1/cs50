from cs50 import get_string
from sys import argv


def char_to_int(c):
    if c.isupper():
        plus = 65
    else:
        plus = 97
    return plus


if len(argv) != 2 or not str(argv[1]).isalpha():
    exit("Usage: python vigenere.py k")
plaintext = get_string("plaintext:  ")
cypher = ""
i = 0
k = str(argv[1])
k_len = len(k)
for c in plaintext:
    if c.isalpha():
        i = i % (k_len)
        key = k[i:i+1]
        key_plus = char_to_int(key)
        key = ord(key) - key_plus
        i = i + 1
        new_c = c
        plus = char_to_int(new_c)
        new_c = ord(new_c)
        new_c = chr((new_c - plus + key) % 26 + plus)
    else:
        new_c = c
    cypher = cypher + new_c
print(f"ciphertext: {cypher}")