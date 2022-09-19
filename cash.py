from cs50 import get_float

#set the money counter
count = 0

# as the situation is true continue
while True:
    change = get_float("The change is: ")
    if change > 0:
        break
    
dollarCent = round(change * 100)

#checking for 0.25 dollars
while dollarCent >= 25:
    dollarCent = dollarCent - 25
    count += 1

#checkin' for 0.10 dollars
while dollarCent >= 10:
    dollarCent = dollarCent - 10
    count += 1
    
# checkin' for 0.05 dollars 
while dollarCent >= 5:
    dollarCent = dollarCent - 5
    count += 1

#checking for 0.01 dollars
while dollarCent >= 1:
    dollarCent = dollarCent - 1
    count += 1
    
# printing the sum
print(count)