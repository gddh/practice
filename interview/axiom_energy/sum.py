def for_sum(lst):
    total = 0
    for num in lst:
        total = total + num
    return total

def while_sum(lst):
    total = 0
    i = 0
    while i < len(lst):
        total = total + lst[i]
        i = i + 1
    return total

def recursive_sum(lst):
    if lst == []:
        return 0
    else:
        return lst[0] + recursive_sum(lst[1:])


lst = []
print for_sum(lst), while_sum(lst), recursive_sum(lst)
lst = [1,2,3,4,5,6,7,8,9]
print for_sum(lst), recursive_sum(lst), while_sum(lst)



