def fibn(n = 100):
    if n == 1:
        return [0]
    lst = [0, 1]
    for _ in range(2, n):
        lst.append(lst[-1] + lst[-2])
    return lst

print(fibn())
