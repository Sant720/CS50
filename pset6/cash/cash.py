from cs50 import get_float

while True:
    change_float = get_float("Change owed: ")
    if change_float > 0:
        break

change = change_float * 100
total_coins = 0
# quarters = 0
# dimes = 0
# nickels = 0
# pennies = 0

while change >= 25:
    change -= 25
    # quarters += 1
    total_coins += 1
    
while change >= 10:
    change -= 10
    # dimes += 1
    total_coins += 1
    
while change >= 5:
    change -= 5
    # nickels += 1
    total_coins += 1

while change >= 1:
    change -= 1
    # pennies += 1
    total_coins += 1
    
print(f"{total_coins}")
# print(f"Quarters: {quarters}")
# print(f"Dimes: {dimes}")
# print(f"Nickels: {nickels}")
# print(f"Pennies: {pennies}")