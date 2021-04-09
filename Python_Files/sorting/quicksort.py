import sorting_item as si
import numpy as np
import random
import time
tStart = time.time()

n = 50
x = np.zeros(n)
y = np.zeros(n)
for i in range(n):
    x[i] = i + 1
    y[i] = i + 1

random.shuffle(y)
print(y)
y = si.sort_quick(y)
print(y)
tEnd = time.time()
print("Cost %f sec" % (tEnd - tStart))
