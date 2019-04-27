from cs50 import get_string
from sys import argv
import crypt


def check_pw(max_pos, pos, salt, crypted, before):
    allowed = allowed_signs()
    pw = before
    allowed_len = len(allowed)
    for i in range(allowed_len):
        pw = pw[:-1] + allowed[i:i+1]
        new_hash = crypt.crypt(pw, salt)
        if new_hash == crypted:
            return pw

        if max_pos > pos:
            pw_other = check_pw(max_pos, pos + 1, salt, crypted, pw)
            if pw_other != False:
                return pw_other

    if max_pos < 4:
        pw_later = check_pw(max_pos + 1, 0, salt, crypted, "")
        if pw_later != False:
            return pw_later
    return False


def allowed_signs():
    allowed = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    return allowed


error = True
if len(argv) == 2:
    crypted = argv[1]
    salt = argv[1][0:2]
    pw = check_pw(0, 0, salt, crypted, "")
    if pw != False:
        print(pw)
        crypt.crypt(crypted, salt)
    error = False

if error == True:
    exit("Usage: ./crack hash")