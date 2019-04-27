from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

for n in range(height):
    print(" " * (height - n - 1), end="")
    print("#" * (n + 1), end="")
    print()