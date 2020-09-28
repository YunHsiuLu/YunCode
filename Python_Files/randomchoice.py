import random
import os

a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]


for i in range(100):
    b = random.sample(a, 3)
    if (i == 99):
        print(b)
os.system("pause")
