def subsets(nums):
    res = []
    for i in range(len(nums) ** 2 - 1):
        subset = []
        indices = [i for i, x in enumerate(bin(i)[2:].zfill(len(nums))) if x == '1']
        for index in indices:
            subset.append(nums[index])
        res.append(subset)
    return res

if __name__ == "__main__":
    #nums = [1,2,3]
    #print(subsets(nums))
    nums = [0]
    print(subsets(nums))
