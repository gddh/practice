class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def add(self, x):
        while (self.next):
            self = self.next
        self.next = ListNode(x)

    def print_list(self):
        print "here"
        while (self):
            print self.val, "-->",
            self = self.next
        print

def mergeKLists(lists):
    res = []
    lists = [lst for lst in lists if lst != None]
    while lists != []:
        min_i = 0
        if lists[0] != None:
            min_val = lists[0].val
        for i in range(len(lists)):
            lst = lists[i]
            if lst == None:
                del lists[i]
            elif lst.val < min_val:
                min_val = lst.val
                min_i = i
        lst = lists[min_i]
        res.append(min_val)
        lists[min_i] = lst.next
        if lst.next == None:
            del lists[min_i]
    return res

if __name__ == "__main__":
    l0 = None
    l1 = ListNode(1)
    l2 = ListNode(1)
    l3 = ListNode(2)
    l1.add(4)
    l1.add(5)
    l2.add(3)
    l2.add(4)
    l3.add(6)
    l1.print_list()
    l2.print_list()
    l3.print_list()
    l4 = ListNode(8)
    print(mergeKLists([l0, l1, None,l2, l3, l4]))
