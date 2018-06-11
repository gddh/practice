class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def recursive(root1, root2):
    if (root1 == None and root2 == None):
        return True
    if (root1 == None or root2 == None):
        return False
    return (root1.val == root2.val and
            recursive(root1.left, root2.right) and
            recursive(root1.right, root2.left))

def isSymmetric(root):
    return recursive(root, root)

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(2)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(3)
    print(isSymmetric(root))
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.right = TreeNode(3)
    root.right = TreeNode(2)
    root.right.right = TreeNode(3)
    print(isSymmetric(root))
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.left = TreeNode(3)
    root.right = TreeNode(3)
    root.right.left = TreeNode(2)
    print(isSymmetric(root))
