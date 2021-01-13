from cs50 import get_int

# get height
height = 0
while height < 1 or height > 8:
    height = get_int("Height: ")

for i in range(height):
    width = i+1
    spaces = height - width
    
    for ch in range(spaces):
        print(" ", end="")
    
    # left pyramid    
    for j in range(width):
        print("#", end="")
        
    print("  ", end="")
    
    # right pyramid
    for j in range(width):
        print("#", end="")
    print("")