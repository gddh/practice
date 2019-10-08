def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    print("hello")
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if target == nums[i] + nums[j]:
                return (i, j)


if __name__ == '__main__':
    print("Starting script")
    nums = [2, 7, 11, 15]
    target = 9  
    print(twoSum(nums, target))
