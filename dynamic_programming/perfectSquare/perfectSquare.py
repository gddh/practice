import math

def numSquares(n):
    pool = [i * i for i in range(1, int(pow(n, 0.5)) + 1)]
    mem = {x:1 for x in pool}
    for i in range(1, n + 1):
        if not i in mem:
            mem[i] = min([mem[a] + mem[i - a] for a in pool if a < i])
    return mem[n]

if __name__ == "__main__":
    print(numSquares(5))
