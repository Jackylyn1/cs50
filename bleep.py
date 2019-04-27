from cs50 import get_string
from sys import argv
import re


global banned
banned = set()


def main():
    if len(argv) != 2:
        exit("Usage: python bleep.py dictionary")
    else:
        if load(argv[1]):
            new_message = " "
            message = get_string("What message would you like to censor?\ncheck50 cs50/2019/x/bleep")
            message = message.split()
            for word in message:
                word2 = word.lower()
                if word2 in banned:
                    word = re.sub('.', '*', word2)
                new_message = new_message + " " + word
            new_message = new_message.strip()
            print(new_message)


def load(words):
    file = open(words)
    for line in file:
        line = line.strip('\n')
        banned.add(line)
    file.close()
    return True


if __name__ == "__main__":
    main()