class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def printList(listNode):
        while (listNode):
            print(listNode.val)
            listNode = listNode.next

class Solution:
    def mergeTwoLists(self, l1, l2):
        if (not l1 and not l2):
            return None
        newList = ListNode(3)
        curNode = newList
        while (l1 and l2):
            if (l1.val < l2.val):
                curNode.next = ListNode(l1.val)
                l1 = l1.next
            else:
                curNode.next = ListNode(l2.val)
                l2 = l2.next
            curNode = curNode.next
        while (not l1 and l2):
            curNode.next = ListNode(l2.val)
            curNode = curNode.next
            l2 = l2.next
        while (not l2 and l1):
            curNode.next = ListNode(l1.val)
            curNode = curNode.next
            l1 = l1.next
        return newList.next

l1 = ListNode(1)
tmp = l1
tmp.next = ListNode(2)
tmp = tmp.next
tmp.next = ListNode(4)

l2 = ListNode(1)
tmp = l2
tmp.next = ListNode(3)
tmp = tmp.next
tmp.next = ListNode(4)

sol = Solution()
ListNode.printList(sol.mergeTwoLists(l1, l2))
