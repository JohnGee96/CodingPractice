class Node(object):
    def __init__(self, v, l=None, r=None):
        self.v = v
        self.l = l
        self.r = r

l3_r = Node(7)
l3_l = Node(6, l3_r)
l2_l = Node(4)
l2_r = Node(5)
l1_l = Node(2,l2_l, l2_r)
l1_r = Node(3, l3_l)
root = Node(1, l1_l, l1_r)

def isBalanceTree(root):
    if root == None:
        return True
    else:
        if isBalanceTree(root.l) and isBalanceTree(root.r):
            h_l = getSubtreeHeight(root.l)
            h_r = getSubtreeHeight(root.r)
            return abs(h_l - h_r) <= 1
        else:
            return False

def getSubtreeHeight(root, height=0):
    if root == None:
        return height
    else:
        return max(getSubtreeHeight(root.l, height + 1), 
                   getSubtreeHeight(root.r, height + 1))


# print(getSubtreeHeight(root))
print(isBalanceTree(root))