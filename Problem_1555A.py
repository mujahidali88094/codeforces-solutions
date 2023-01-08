import math
import decimal
timePerSlice = decimal.Decimal(2.5)  # = 25/10 or 20/8 or 15/6
n = int(input())
while (n != 0):
    n -= 1
    slices = decimal.Decimal(input())
    # minimum 6 slices are baked
    slices = max(6, slices)
    minTime = decimal.Decimal(math.ceil(slices * timePerSlice))
    # actual time taken will be nearest multiple of 5 greater than min time
    actualTime = decimal.Decimal(5 * math.ceil(minTime / 5))
    print(actualTime)
