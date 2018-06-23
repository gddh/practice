def longestConsecutive(nums):
    if nums == []:
        return 0
    map = {}
    for num in nums:
        if not num in map.keys():
            map[num] = 1
            if num - 1 in map.keys():
                map[num] = map[num - 1] + map[num]
                map[num - 1] = map[num]
            if num + 1 in map.keys():
                map[num] = map[num + 1] + map[num]
                map[num + 1] = map[num]
        print "adding ", num
        print [(key, map[key]) for key in sorted(map.keys())]
    return max(map.values())

if __name__ == "__main__":
    nums = [100,4,200,1,3,2]
    #print(longestConsecutive(nums))
    #print(longestConsecutive([]))
    #print(longestConsecutive([2, 3, 2]))
    print(longestConsecutive([3,7,2,5,8,4,6,0,1]))
