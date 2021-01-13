from cs50 import get_float

change = -1
while change < 0:
    change = get_float("Change owed: ")
    
coins = 0
while round(change, 2) > 0:
    if round(change, 2) >= 0.25:
        change -= 0.25
        coins += 1
        continue
    
    if round(change, 2) >= 0.10:
        change -= 0.10
        coins += 1
        continue
    
    if round(change, 2) >= 0.05:
        change -= 0.05
        coins += 1
        continue
    
    if round(change, 2) >= 0.01:
        change -= 0.01
        coins += 1
        continue
     
print(coins)