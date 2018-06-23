def helper(n):
    if (n <= 1):
        return n
    return helper(n - 1) + helper(n - 2)

def climbStairs(n):
    return helper(n + 1)

if __name__ == "__main__":
    print(climbStairs(3))
    print(climbStairs(2))
