import random

with open("test_m802.txt", "w") as f:
    N, M = random.randint(1, 20), random.randint(1, 20)
    f.write("%d\n" % (N))
    f.write("%d\n" % (M))
    for i in range(M):
        arrow = random.choice('VH')
        word = random.randint(65, 90)
        x = random.randint(0, N-1)
        y = random.randint(0, N-1)
        f.write("%c %c %d %d\n" % (arrow, chr(word), x, y))


