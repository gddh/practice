
def twoSum(nums, target):
    for i in range(len(nums)):
        if ((target - nums[i]) in nums and nums.index(target - nums[i]) != i):
            return [i, nums.index(target - nums[i])]

if __name__ == "__main__":
    nums = [3, 2, 4]
    target = 6
    print(twoSum(nums, target))
