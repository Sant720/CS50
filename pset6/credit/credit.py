from cs50 import get_string
from math import floor

card = get_string("Number: ")

lenght = len(card)
card_type = "INVALID"

if lenght > 16 or lenght < 13:
    print(card_type)
    exit()

# Determine possible type
if (lenght in {13, 16}) and card.startswith("4"):
    card_type = "VISA"

elif lenght == 15 and card.startswith(("34", "37")):
    card_type = "AMEX"

elif lenght == 16 and card.startswith(("51", "52", "53", "54", "55")):
    card_type = "MASTERCARD"

if card_type == "INVALID":
    print(card_type)
    exit()

# Run Luhn's Algorithm
N = int(card)

sum1 = 0
sum2 = 0

while (N > 0):
    sum1 = sum1 + (N % 10)
    N = floor(N / 10)
    
    prod1 = 0
    break1 = 0
    prod1 = (N % 10) * 2

    if prod1 >= 10:
        while prod1 > 0:
            break1 = break1 + (prod1 % 10)
            prod1 = floor(prod1 / 10)

    sum2 = sum2 + prod1 + break1
    N = floor(N / 10)

if ((sum1 + sum2) % 10) != 0:
    card_type = "INVALID"

print(card_type)