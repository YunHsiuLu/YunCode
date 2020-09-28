import sorting_item as si
import numpy as np
import random
import imageio
import math

image = []

n = 100
x = np.zeros(n)
y = np.zeros(n)

for i in range(n):
    x[i] = i + 1
    y[i] = i + 1

random.shuffle(y)
# print(y)
image.append(si.plot_gif(x, y))
y = np.reshape(y, (n, 1))

k = int(math.ceil(n/2))
temp = [[] for i in range(k)]
a = temp
for i in range(k):
    a[i].append(y[2*i][0])
    si.find_correct_place(a[i], y[2*i+1])
temp = a
y = si.read_2darray_element(temp)
image.append(si.plot_gif(x, y))

while(k != 1):
    a = []
    t = int(math.ceil(k/2))
    for i in range(t):
        a.append(temp[2*i])
        if (i+1 == t and k % 2 == 1):
            continue
        si.find_correct_place(a[i], temp[2*i+1])
    temp = a
    k = t
    y = si.read_2darray_element(temp)
    image.append(si.plot_gif(x, y))
imageio.mimsave('./mergesort.gif', image, duration=0.1)
