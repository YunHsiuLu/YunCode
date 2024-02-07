class node:
	def __init__(self):
		self.s = [0, 0]
		self.t = 0
		self.c = 0
		self.v = -99

p,q,r,m = map(int,input().split())
NODE = [node() for _ in range(p+q+r)]
ip = input().split()
for i in range(p):
	NODE[i].v = int(ip[i])
gc = input().split()
for i in range(p, p+q):
	NODE[i].c = int(gc[i-p])

for i in range(m):
	s, t = map(int, input().split())
	NODE[s-1].t = t
	if NODE[t-1].s[0] == 0 : NODE[t-1].s[0] = s
	else : NODE[t-1].s[1] = s
	if (any(NODE[t-1].s)) or (NODE[t-1].c == 4 and not NODE[t-1].s[0]):
		if (NODE[t-1].c == 1) : NODE[t-1].v = int(NODE[NODE[t-1].s[0]-1].v and NODE[NODE[t-1].s[1]-1].v)
		elif (NODE[t-1].c == 2) : NODE[t-1].v = int(NODE[NODE[t-1].s[0]-1].v or NODE[NODE[t-1].s[1]-1].v)
		elif (NODE[t-1].c == 3) : NODE[t-1].v = int(NODE[NODE[t-1].s[0]-1].v ^ NODE[NODE[t-1].s[1]-1].v)
		else : NODE[t-1].v = int(not NODE[NODE[t-1].s[0]-1].v)

delay = 0
def dfs(n, de):
	global delay
	if n.c > 0:
		de+=1
	if n.s[0] > 0 : dfs(NODE[n.s[0]-1], de)
	else : return 0
	if n.s[1] > 0 : dfs(NODE[n.s[1]-1], de)
	else : return 0
	delay = max(delay, de)


for i in range(p+q, p+q+r):
	NODE[i].v = NODE[NODE[i].s[0]-1].v
	dfs(NODE[i], 0)

print(delay)
for i in range(p+q, p+q+r):
	print(NODE[i].v, end=" ")
print()
