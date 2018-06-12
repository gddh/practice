def rob(nums):
    if nums == []:
        return 0
    if len(nums) == 1:
        return nums[0]
    robbed = [0] * len(nums)
    robbed[0] = nums[0]
    robbed[1] = max(nums[0], nums[1])
    for i in range(2, len(nums)):
        robbed[i] = max(robbed[i - 1], robbed[i - 2] + nums[i])
    return robbed[-1]

if __name__ == "__main__":
    print(rob([1, 7, 9, 2]))
    print(rob([2, 7, 9, 3, 1]))
    print(rob([1, 2, 3, 1]))
    print(rob([2,1,1,2]))
    print(rob([]))
    print(rob([6,3,10,8,2,10,3,5,10,5,3]))
