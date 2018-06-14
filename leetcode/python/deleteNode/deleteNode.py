class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def add_to_end(self, x):
        while self.next:
            self = self.next
        self.next = ListNode(x)

    def print_lst(self):
        while self:
            print self.val, "-->",
            self = self.next
        print
    
    def deleteNode(self, node):
        while self.next and self.next.val != node:
            self = self.next
        self.next = self.next.next

    
if __name__ == "__main__":
    node = ListNode(1)
    for i in range(2, 5):
        node.add_to_end(i)
    node.print_lst()
    node.deleteNode(3)
    node.print_lst()

