def groupAnagrams(strs):
    pairs = [(i, ''.join(sorted(s))) for i, s in enumerate(strs)]
    sorted_pairs = sorted(pairs, key = lambda pair:pair[1])
    res =  []
    prev_str = sorted_pairs[0][1]
    cur = [strs[sorted_pairs[0][0]]]
    for i in range(1,len(sorted_pairs)):
        if sorted_pairs[i][1] != prev_str:
            res.append(cur)
            cur = [strs[sorted_pairs[i][0]]]
            prev_str = sorted_pairs[i][1]
        else:
            cur.append(strs[sorted_pairs[i][0]])
    if not cur in res:
        res.append(cur)
    return res

if __name__ == "__main__":
    x = ["eat", "tea", "tan", "ate", "nat", "bat"]
    print(groupAnagrams(x))
    x = ["eeat", "aeet", "eat"]
    print(groupAnagrams(x))
