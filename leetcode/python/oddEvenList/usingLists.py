class   ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def add_to_end(self, x):
        while (self.next):
            self = self.next
        self.next = ListNode(x)
    
    def printList(self):
        while (self):
            print self.val, "-->",
            self = self.next
        print

    def create_from_list(self, lst):
        for elem in lst:
            self.add_to_end(elem)

def addToHead(arr, head):
    for elem in arr:
        head.val = elem
        head = head.next
    return head

def oddEvenList(head):
    tmp = head
    odd = []
    even = []
    odd_num = 1
    while (tmp):
        if (odd_num):
            odd_num = 0
            odd.append(tmp.val)
        else:
            odd_num = 1
            even.append(tmp.val)
        tmp = tmp.next
    head = addToHead(odd, head)
    addToHead(even, head)

if __name__ == "__main__":
    head = ListNode(2)
    head.create_from_list([1,3,5,6,4,7])
    oddEvenList(head)
    head.printList()
