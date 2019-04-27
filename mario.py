from cs50 import get_int

height = get_int("Height: ")

for n in range(height):
    start = (height - n - 1)
    for i in range(height * 2 - start):
        if i < start:
            print("-", end = "")
        elif i in (i < start + n, i > start + n + 2):
            print("#", end = "")
        else:
            print(" ", end="")
    print()