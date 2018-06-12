def isInterleave(s1,s2,s3):
    if len(s1) + len(s2) != len(s3):
        return False
    dp = [[0] * (len(s2) + 1) for _ in range(len(s1) + 1)]
    for i in range(len(s1) + 1):
        for j in range(len(s2) + 1):
            if i == 0 and j == 0:
                dp[i][j] = True
            elif i == 0:
                dp[i][j] = dp[i][j - 1] and s2[j - 1] == s3[j - 1]
            elif j == 0:
                dp[i][j] = dp[i - 1][j] and s1[i - 1] == s3[i - 1]
            else:
                dp[i][j] = ((dp[i - 1][j] and s1[i - 1] == s3[i + j - 1])
                            or (dp[i][j - 1] and s2[j - 1] == s3[i + j - 1]))
    return dp[len(s1)][len(s2)]

if __name__ == "__main__":
    print(isInterleave("aabcc", "dbbca", "aadbbbaccc"))
