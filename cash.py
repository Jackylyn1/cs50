from cs50 import get_float

while True:
    change = get_float("Change owed: ") * 100
    if change > 0:
        break

coins = {25, 10, 5, 1}

min_coins = 0
for i in coins:
    if change > 0:
        min_coins += change // i
        change %= i

print(f"{min_coins:.0f}")