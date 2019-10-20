def maxSubArray(nums) -> int:
    max_so_far = nums[0]
    cur_max = nums[0]
    for i in range(len(nums)):
        cur_max = max(cur_max + nums[i], nums[i])
        max_so_far = max(cur_max, max_so_far)
    return max_so_far

if __name__ == '__main__':
    x = [-2,1,-3,4,-1,2,1,-5,4]
    print(maxSubArray(x))
