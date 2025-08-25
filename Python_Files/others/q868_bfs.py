n = int(input())
edges = [[] for _ in range(n + 10)]
for _ in range(n):
    a, b = map(int, input().split())
    edges[a].append(b)
g, f = map(int, input().split())

from collections import deque
visited = [False] * (n + 10)
queue = deque([g])
visited[g] = True
found = False

while queue:
    node = queue.popleft()
    if node == f:
        found = True
        break
    for neighbor in edges[node]:
        if not visited[neighbor]:
            visited[neighbor] = True
            queue.append(neighbor)

print("Yay" if found else "Come on")

