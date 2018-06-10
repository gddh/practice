class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
    
    def add_to_end(self, x):
        while (self.next):
            self = self.next
        self.next = ListNode(x)

    def print_list(self):
        while (self):
            print self.val , "-->",
            self = self.next
        print

def createList(lst, head):
    for num in lst:
        head.add_to_end(num)

def carryOver2(l1, l2):
     if (l1.val + l2.val > 9):
        if (not l1.next):
            l1.next = ListNode(0)
        l1.next.val = l1.next.val + 1

def carryOver(lst):
    if (lst.val > 9):
        if (not lst.next):
            lst.next = ListNode(0)
        lst.next.val = lst.next.val + 1

def addTwoNumbers(l1, l2):
    if (not l1 and not l2):
        return None
    elif (not l1):
        carryOver(l2)
        node = ListNode(l2.val % 10)
        node.next = addTwoNumbers(l1, l2.next);
    elif (not l2):
        carryOver(l1)
        node = ListNode(l1.val % 10)
        node.next = addTwoNumbers(l1.next, l2);
    else:
        carryOver2(l1, l2)
        print("l1 + l2 is: ", (l1.val + l2.val) % 10)
        node = ListNode((l1.val + l2.val) % 10)
        node.next = addTwoNumbers(l1.next, l2.next)
    return node

if __name__ == "__main__":
    head1 = ListNode(9)
    createList([9], head1)
    head1.print_list()
    head2 = ListNode(9)
    #createList([6, 4], head2)
    head2.print_list()
    addTwoNumbers(head1, head2).print_list();
