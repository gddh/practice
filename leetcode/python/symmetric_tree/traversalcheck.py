class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def inOrder(root, lst, rvr):
    if (not root):
        return
    else:
        helper1(root, lst, rvr, inOrder) 
        lst.append(root.val)
        helper2(root, lst, rvr, inOrder)

def preOrder(root, lst, rvr):
    if (not root):
        return
    else:
        lst.append(root.val)
        helper1(root, lst, rvr, preOrder)
        helper2(root, lst, rvr, preOrder)

def helper1(root, lst, rvr, func):
    if not rvr:
        func(root.left, lst, rvr)
    else:
        func(root.right, lst, rvr)

def helper2(root, lst, rvr, func):
    if not rvr:
        func(root.right, lst, rvr)
    else:
        func(root.left, lst, rvr)

def check(root, func):
    orderLst = []
    func(root, orderLst, False)
    rvrLst = []
    func(root, rvrLst, True)

    print orderLst
    print rvrLst
    return orderLst == rvrLst


def isSymmetric(root):
    return check(root, inOrder) and check(root, preOrder)

if __name__ == "__main__":
    #root = TreeNode(1)
    #root.left = TreeNode(2)
    #root.right = TreeNode(2)
    #root.left.left = TreeNode(3)
    #root.left.right = TreeNode(4)
    #root.right.left = TreeNode(4)
    #root.right.right = TreeNode(3)
    #print(isSymmetric(root))
    #root = TreeNode(1)
    #root.left = TreeNode(2)
    #root.left.right = TreeNode(3)
    #root.right = TreeNode(2)
    #root.right.right = TreeNode(3)
    #print(isSymmetric(root))
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.left = TreeNode(3)
    root.right = TreeNode(3)
    root.right.left = TreeNode(2)
    print(isSymmetric(root))
