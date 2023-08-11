#python program to check leap year

def is_leap_year(year):
    if year % 4 == 0:
        if year % 100 == 0:
            if year % 400 == 0:
                return True
            else:
                return False
        else:
            return True
    else:
        return False

year = int(input("Enter Year to check:"))

if is_leap_year(year):
    print(year,"is Leap Year")
else:
    print(year,"is not Leap year")