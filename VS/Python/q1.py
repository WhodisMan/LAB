r = int(input("no of rats = "))
unit = int(input("no of units = "))
n = int(input("no of lements in an array  = "))

arr = list(map(int,input("space separated elements = ").split()))

print()


def calculate(r,unit,arr,n):
    if arr is None or n == 0:
        return -1
    tfr = r*unit
    ftn = 0
    for i in range(n):
        ftn += arr[i]
        if ftn >= tfr:
            return i+1
    return 0