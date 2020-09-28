import sorting_item as si
import numpy as np
import random
import time
tStart = time.time()

n = 50
a = [random.randint(0, 999) for i in range(n)]
x = np.zeros(n)
y = np.zeros(n)
for i in range(n):
    x[i] = i + 1
    y[i] = a[i]

random.shuffle(y)
print(y)

a = [[] for i in range(10)]
b = [[] for i in range(10)]
c = [[] for i in range(10)]
d = []
# first step:百位數
for i in range(n):
    k = int(y[i] % 10)
    a[k].append(y[i])
# second step: 十位數
for i in range(10):
    for j in range(len(a[i])):
        k = int(a[i][j] % 100/10)
        b[k].append(a[i][j])
# third step: 個位數
for i in range(10):
    for j in range(len(b[i])):
        k = int(b[i][j]/100)
        c[k].append(b[i][j])
for i in range(10):
    for j in range(len(c[i])):
        d.append(c[i][j])
y = d
print(y)
tEnd = time.time()
print("Cost %f sec" % (tEnd - tStart))
