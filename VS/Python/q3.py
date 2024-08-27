# Autobiographical number 



def FindAutoCount(num):
    count = 0
    for i in range(len(num)):
        if (int(num[i]) == num.count(str(i))):
            count+=1
    if count == len(num):
        return len(set(num))
    else:
        return 0



num = input("Enter number : ")
print(FindAutoCount(num))