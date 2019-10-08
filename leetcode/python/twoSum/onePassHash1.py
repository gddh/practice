def twoSum(nums, target):
    d = {}
    for i, num in enumerate(nums):
        if target - num in d:
            return d[target - num], i
        d[num] = i


if __name__ == "__main__":
    nums = [3, 2, 4]
    target = 6
    #nums = [2, 7, 11, 15]
    #target = 9
    print(twoSum(nums, target))
