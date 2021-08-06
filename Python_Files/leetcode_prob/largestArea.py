import numpy as np
import random
random.seed(10)
N = 3
N2 = N**2
a = [random.randint(0, 1) for _ in range(N2)]
a = (np.reshape(a, (N, N))).tolist()
ind0 = []
for i in range(len(a)):
	for j in range(len(a[i])):
		if a[i][j] == 0:
			ind0.append([i, j])
print("0's position:")
print(ind0)
print()

def infect(pt):
	x = pt[0]
	y = pt[1]
	seen = [[x, y]]
	stack = [[x, y]]
	while stack:
		x, y = stack.pop()
		for (nx, ny) in ((x-1, y), (x+1, y), (x, y-1), (x, y+1)):
			if (nx, ny) not in seen and 0 <= nx < N and 0 <= ny < N and a[nx][ny]:
				seen.append((nx, ny))
				stack.append((nx, ny))
	return len(seen)

c = 0
p = 0
for pt in ind0:
	A = a
	print("point %d" % (p+1))
	t = 0
	t = infect(pt)
	if t > c:
		c = t
	p += 1
	print("Area is: %d" % (t))
print("The largest Area is: %d" % (c))
