def uglyNum(n):
    lst = [0] * n
    i2 = i3 = i5 = 0
    uNum2 = 2
    uNum3 = 3
    uNum5 = 5
    uNum = 1
    lst[0] = uNum

    for i in range(n - 1):
        i = i + 1
        uNum = min(uNum2, uNum3, uNum5)
        lst[i] = uNum
        if (uNum == uNum2):
            i2 = i2 + 1
            uNum2 = lst[i2] * 2
        if (uNum == uNum3):
            i3 = i3 + 1
            uNum3 = lst[i3] * 3
        if (uNum == uNum5):
            i5 = i5 + 1
            uNum5 = lst[i5] * 5
    return lst[-1]


if __name__ == "__main__":
    for i in range(11):
        i = i + 1
        rv = uglyNum(i)
        print "i:", i, "uglyNum ", rv
    #i = 18
    #print uglyNum(i)
