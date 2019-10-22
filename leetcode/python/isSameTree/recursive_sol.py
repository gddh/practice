class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def isSameTree(p, q):
    if p is None and q is None:
        return True
    elif p is None:
        return False
    elif q is None:
        return False
    return p.val == q.val and \
            isSameTree(p.left, q.left) and \
            isSameTree(p.right, q.right)
            
