def mergeLst(lst1, lst2):
    i = 0
    res = []
    while i < len(lst1) and i < len(lst2):
        res.append(lst1[i])
        res.append(lst2[i])
        i = i + 1
    while i < len(lst1):
        res.append(lst1[i])
        i = i + 1
    while i < len(lst2):
        res.append(lst2[i])
        i = i + 1
    return res

lst1 = ['a', 'b', 'c']
lst2 = [ 1, 2, 3]
print(mergeLst(lst1, lst2))
lst1 = []
print(mergeLst(lst1, lst2))
lst2 = []
print(mergeLst(lst1, lst2))
lst1 = ['a', 'b', 'c']
print(mergeLst(lst1, lst2))

