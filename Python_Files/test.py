import numpy as np
import matplotlib.pyplot as plt
import time

x = np.linspace(0, 10, 100)
y1 = np.sin(x)
y2 = np.cos(x)

fig1 = plt.figure()

plt.plot(x, y1, "r-")
time.sleep(0.5)
plt.plot(x, y2, "b.")
plt.show()
