from nltk.tokenize import sent_tokenize


def compare(a, b):
    cmp_list = set()
    for old in a:
        for new in b:
            if old == new:
                cmp_list.add(old)
    cmp_list = list(cmp_list)
    return cmp_list


def handle_split(a):
    a = a.split("\n")
    return a


def lines(a, b):
    """Return lines in both a and b"""
    a = handle_split(a)
    print(a)
    b = handle_split(b)
    print(b)
    line = compare(a, b)
    return line


def sentences(a, b):
    """Return sentences in both a and b"""
    a = sent_tokenize(a)
    b = sent_tokenize(b)
    sentence = compare(a, b)
    return sentence


def substr_list(a, n):
    a_list = list()
    i = 0
    while i < n:
        a_new = a[i:]
        while len(a_new) >= n:
            a_list.append(a_new[0:n])
            a_new = a_new[n:]
        i += 1
    return a_list


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    a_list = substr_list(a, n)
    b_list = substr_list(b, n)
    substrs = compare(a_list, b_list)
    # TODO
    return substrs
