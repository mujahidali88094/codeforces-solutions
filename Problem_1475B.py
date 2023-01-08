# Problem 1475B

def _isValid(n):
    ''' brute force solution '''
    if (n < 2020):
        return False
    if (n % 2021 == 0 or n % 2020 == 0):
        return True
    if (_isValid(n-2021)):
        return True
    if (_isValid(n-2020)):
        return True
    return False


def isWholeNumber(x):
    if x < 0:
        return False
    return (x - int(x) == 0)


def isValid(n):
    ''' accepted solution '''
    # description at the end of file
    if (n < 2020):
        return False
    y = n % 2020
    x = (n - y)/2020 - y
    if isWholeNumber(x):
        return True
    return False


n = int(input())
while (n > 0):
    n -= 1
    x = int(input())
    if (isValid(x)):
        print("YES")
    else:
        print("NO")

# Explanation of Accepted Solution
# --------------------------------
#
# n = 2020 x + 2021 y ---> eq(1)
#
# n = 2020 x + 2020 y + y
# n = 2020 (x + y) + y
# x = (n - y)/2020 - y ---> eq(2)
#
# Also, y can be greater than 2019 (beacause if it is, it will be added to x)
# so y = n % 2020 ---> eq(3)
#
# first get y from eq(1), then put in eq(2)
# if x is whole number, n can be represented as eq(1)
