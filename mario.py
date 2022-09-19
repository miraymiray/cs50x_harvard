from cs50 import get_int

# checking the input
while True:
    height = get_int("Height: ")
    if 1 <= height <= 8:
        break
    
# printing the spaces and hashes
for row in range(1, height + 1):
    print(' ' * (height - row) + '#' * row)