class Node:
    def __init__(self, val=None, next=None):
        self.Val = val
        self.Next = next


def NodePrint(node):
    if node.Val == None:
        print("[]", end="")
        if node.Next == None:
            return 0
        else:
            print("->", end="")
            NodePrint(node.Next)
    else:
        print("[%d]" % (node.Val), end="")
        if node.Next == None:
            return 0
        else:
            print("->", end="")
            NodePrint(node.Next)


def makeList(*nodes):
    for i in range(len(nodes)-1):
        nodes[i].Next = nodes[i+1]
    return nodes[0]


list = makeList(Node(), Node(1), Node(4), Node(2), Node(3), Node(5))
NodePrint(list)
