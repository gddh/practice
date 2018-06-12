def fib(n):
    lst = [0] * n
    if (n < 0):
        return -1
    if (n > 0):
        lst[0] = 0
    if (n > 1):
        lst[1] = 1
    for i in range(2, n):
        lst[i] = lst[i - 1] + lst[i - 2]
    return lst[n - 1]

if __name__ == "__main__":
    for i in range(1,14):
        print "fib",i,": ",fib(i)

