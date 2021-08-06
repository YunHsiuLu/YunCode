import random
import numpy as np
random.seed(10)
N = 3
N2 = N**2

a = np.array([random.randint(0, 1) for _ in range(N2)])
A = np.reshape(a, (N, N))
print(A)

ind0 = (np.argwhere(A == 0)).tolist()
ind1 = (np.argwhere(A == 1)).tolist()
new_ind1 = []
for pt in ind1:
	x = pt[0]
	y = pt[1]
	if x == 0:
		if y == 0:
			if [x+1, y] in ind0 or [x, y+1] in ind0:
				new_ind1.append([x, y])
		elif y == N-1:
			if [x+1, y] in ind0 or [x, y-1] in ind0:
				new_ind1.append([x, y])
		else:
			if [x+1, y] in ind0 or [x, y-1] in ind0 or [x, y+1] in ind0:
				new_ind1.append([x, y])
	elif x == N-1:
		if y == 0:
			if [x-1, y] in ind0 or [x, y+1] in ind0:
				new_ind1.append([x, y])
		elif y == N-1:
			if [x-1, y] in ind0 or [x, y-1] in ind0:
				new_ind1.append([x, y])
		else:
			if [x-1, y] in ind0 or [x, y-1] in ind0 or [x, y+1] in ind0:
				new_ind1.append([x, y])
	else:
		if [x+1, y] in ind0 or [x-1, y] in ind0 or [x, y-1] in ind0 or [x, y+1] in ind0:
				new_ind1.append([x, y])

print(new_ind1)