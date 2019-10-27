def canJump(nums):
    curMax = nums[0]
    if len(nums) == 1:
        return True
    for i in range(1, len(nums)):
        curMax = curMax - 1
        if curMax < 0:
            return False
        curMax = max(nums[i], curMax)
    return True

if __name__ == "__main__":
    print(canJump([2,3,1,1,4]), ':True')
    print(canJump([3,2,1,0,4]), ':False')
    print(canJump([0,1]), ":False")
    print(canJump([0]), ':True')
    print(canJump([2,0,0]), ':True')
