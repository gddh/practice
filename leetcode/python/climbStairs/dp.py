def helper(n):
    if n <= 1:
        return n
    dp = [0] * (n + 1)
    dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]

def climbStairs(n):
    return helper(n + 1)

if __name__ == "__main__":
    print(climbStairs(3))
