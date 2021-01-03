from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

spaces = height - 1
hashes = 1

while spaces >= 0:
    print((" " * spaces), end="") 
    print("#" * hashes)
    hashes += 1
    spaces -= 1