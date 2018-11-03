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

def lcm(root, a, b):
    if root == None:
        return None
    elif root.v == a:
        return a
    elif root.v == b:
        return b
    else:
        r1 = lcm(root.l, a, b)
        r2 = lcm(root.r, a, b)
        if a in (r1,r2) and b in (r1,r2):
            return root.v
        elif a in (r1,r2):
            return a
        elif b in (r1,r2):
            return b
        else:
            return None

print(lcm(root, 2, 3))