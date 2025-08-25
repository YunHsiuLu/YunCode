try:
    while True:
        line = input().split()
        line = [int(i) for i in line]
        a = 0
        for l in line : a += l
        print(a)
except EOFError:
    pass
