# Explanation:

# let's say we want to represent all numbers with 11s and 111s
# if a number is not a multiple of 11, the remainder will be 1 to 10
# we can fill the remainder by combining 11s and 111s
# the count of 111s needed will always be equal to remainder
# like if n was 343, we need 2 111s (= 343 % 11) and some 11s
# and to accomodate 2 111s, we must replace 20 11s out of 31 11s (343 / 11)
# so 343 = 11 11s and 2 111s

# so in general, n = ((n / 11) - (n % 11) * 10) elevens + (n % 11) 111s
# for that to happen, we must have (n / 11) >= (n % 11)*10

# also, in this way we can represent all numbers greater than 1100 with 11s and 111s


def solve(n):
    if (n < 11):
        return False
    elevens = int(n / 11)
    remainder = n % 11
    if (elevens >= remainder * 10):
        return True
    return False


t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    canBeRepresented = solve(n)
    if (canBeRepresented):
        print("YES")
    else:
        print("NO")
