import numpy as np
import random
import imageio
import sorting_item as si


image = []
n = 100
x = np.zeros(n)
y = np.zeros(n)
for i in range(n):
    x[i] = i + 1
    y[i] = i + 1

random.shuffle(y)

for i in range(n):
    for j in range(n-1-i):
        if (y[j] > y[j+1]):
            si.SWAP(y, j, j+1)
    image.append(si.plot_gif(x, y))

imageio.mimsave('./bubblesort.gif', image, duration=0.1)
