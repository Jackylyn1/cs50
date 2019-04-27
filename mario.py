from cs50 import get_int

height = get_int("Height: ")

for n in range(height):
    print(" " * (height - n - 1), end = "")
    print("#" * (n + 1), end = "")
    print()