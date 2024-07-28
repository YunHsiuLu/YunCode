class Node():
    def __init__(self, value=None):
        self.value = value
        self.Parent = None
        self.Left = None
        self.Right = None
        self.passed = 0


s = input()
Tree = {"head":Node()}

for i in range(1, len(s)+1):
    now = s[i-1]
    if (now == "-") : continue
    Tree[now] = Node(now)
    if (i>1):
        Tree[now].Parent = Tree[list(Tree.keys())[i//2]]
        if not i%2:
            Tree[list(Tree.keys())[i//2]].Left = Tree[s[i-1]]
        else:
            Tree[list(Tree.keys())[i//2]].Right = Tree[s[i-1]]
"""
for i in Tree:
    if not Tree[i].value:
        print(i,
            Tree[i].Parent.value if (Tree[i].Parent) else "None",
            Tree[i].Left.value if (Tree[i].Left) else "None",
            Tree[i].Right.value if (Tree[i].Right) else "None")
"""

query = int(input())
for i in range(query):
    count = 0
    s, e = input().split()
    q1 = [s]
    q2 = []
    for i in Tree:
        Tree[i].passed = 0
    while (q1 or q2):
        s = q1.pop(0)
        Tree[s].passed = 1
        if s == e:
            print(count)
            break
        
        if (Tree[s].Parent and not Tree[s].Parent.passed) : q2.append(Tree[s].Parent.value)
        if (Tree[s].Left and not Tree[s].Left.passed) : q2.append(Tree[s].Left.value)
        if (Tree[s].Right and not Tree[s].Right.passed) : q2.append(Tree[s].Right.value)
        
        if not q1:
            while q2:
                q1.append(q2[0])
                q2 = q2[1:]
        
            count += 1
