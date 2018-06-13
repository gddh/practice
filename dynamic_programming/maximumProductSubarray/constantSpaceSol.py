def maxProduct(nums):
    minNum = maxNum = curMax = nums[0]
    for num in nums[1:]:
        tmp = maxNum
        maxNum = max(num, maxNum * num, minNum * num)
        minNum = min(num, tmp * num, minNum * num)
        curMax = max(curMax, maxNum)
    return curMax
    
if __name__ == "__main__":
    #print(maxProduct([2,3,-2,4]))
    #print(maxProduct([-2, 0,-1]))
    #print(maxProduct([-2, 3, -4]))
    #print(maxProduct([-2]))
    print(maxProduct([-4, -3, -2]))
