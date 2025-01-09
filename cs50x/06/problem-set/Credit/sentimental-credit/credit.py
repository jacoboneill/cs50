import re


def main():
    card = input("Number: ")
    print(check(card))


def luhn(card):
    digits = ""
    for i in range(len(card) - 2, -1, -2):
        digits += str(int(card[i]) * 2)

    sum = 0
    for digit in digits:
        sum += int(digit)

    for i in range(len(card) - 1, -1, -2):
        sum += int(card[i])

    return sum % 10 == 0


def check(card):
    if len(card) == 15 and re.match(r"^3[4,7]", card) and luhn(card):
        return "AMEX"
    elif len(card) == 16 and re.match(r"^5[1-5]", card) and luhn(card):
        return "MASTERCARD"
    elif len(card) in [13, 16] and re.match(r"^4", card) and luhn(card):
        return "VISA"
    else:
        return "INVALID"


main()
