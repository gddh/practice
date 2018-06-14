def lengthOfLIS(nums):
    if nums == []:
        return 0
    dp = [1] * len(nums)
    for i in range(1, len(nums)):
        for j in range(i):
            if nums[j] < nums[i]:
                dp[i] = max(dp[i], dp[j] + 1)
    return max(dp)

if __name__ == "__main__":
    print(lengthOfLIS([5, 2, 8, 6, 3, 6, 9, 7]))
    print(lengthOfLIS([0]))
