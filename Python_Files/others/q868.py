n = int(input())
parent = {}
rank = {}

def find(i):
    if parent[i] == i : return i
    else : return find(parent[i])

for i in range(n):
    x, y = list(map(int, input().split()))
    if x not in parent:
        parent[x] = x
        rank[x] = 1
    if y not in parent:
        parent[y] = y
        rank[y] = 1

    x = find(x)
    y = find(y)
    if rank[x] >= rank[y]:
        rank[x] += rank[y]
        parent[y] = x
    else:
        rank[y] += rank[x]
        parent[x] = y

query = list(map(int, input().split()))
if find(query[0]) == find(query[1]) : print("Yay")
else : print("Come on")
