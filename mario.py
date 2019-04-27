from cs50 import get_int

height = get_int("Height: ")

for n in range(height):
    for i in range(height):
        if i < (height - n - 1):
            print("-", end = "")
        else:
            print("#", end = "")
    print()