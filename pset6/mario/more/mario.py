from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break
    
spaces = height - 1
hashes = 1
    n
while spaces >= 0:
    print((" " * spaces) + ("#" * hashes) + ("  ") + ("#" * hashes))
    spaces -= 1
    hashes += 1