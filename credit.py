from cs50 import get_float


def valid(number):
    start_nums = False
    is_valid = False
    valid_num = sum_every2(number, 1)
    valid_num += sum_every2(number, 10)

    if valid_num % 10 == 0:
        for i in range(12, 16):
            rest_mode = 10
            for j in range(i - 2):
                rest_mode *= 10
            rest = number // rest_mode
            if rest >= 10 and rest < 100:
                if rest >= 40 and rest < 50:
                    print("VISA")
                    is_valid = True
                elif rest == 34 or rest == 37:
                    print("AMEX")
                    is_valid = True
                elif rest > 50 and rest < 56:
                    print("MASTERCARD")
                    is_valid = True

    if is_valid == False:
        print("INVALID")


def sum_every2(number, start):
    sum = 0
    number //= start
    while number > 0:
        summand = number % 10
        if start == 10:
            summand *= 2
        number //= 100
        if start == 10:
            while summand > 9:
                sum += summand % start
                summand //= 10
            sum += summand % start
        else:
            sum += summand
    return sum


while True:
    number = get_float("Number: ")
    if number > 0:
        break
valid(number)