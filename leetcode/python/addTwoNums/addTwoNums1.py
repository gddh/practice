class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def get_next(l):
    if l:
        return l.val, l.next
    else:
        return 0, None

def addTwoNumbers(l1, l2):
    head = None
    cur = head
    while l1 or l2:
        val1, l1 = get_next(l1)
        val2, l2 = get_next(l2)
        cur = ListNode(val1 + val2)
    return total

if __name__ == '__main__':
    head1 = ListNode(2)
    head1.next = ListNode(4)
    head1.next.next = ListNode(3)

    head2 = ListNode(5)
    head2.next = ListNode(6)
    head2.next.next = ListNode(4)

    res = addTwoNumbers(head1, head2)
    print(res)

