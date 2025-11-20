try:
    while True:
        line = list(map(int, input().split()))
        # line[4] = (line[1]+line[3])/(line[0]+line[2])
        mask = line.index(-1)
        if (mask == 0):
            print("%.2f" % ((line[1]+line[3])/line[4] - line[2]))
        elif (mask == 1):
            print("%.2f" % (line[4]*(line[0]+line[2]) - line[3]))
        elif (mask == 2):
            print("%.2f" % ((line[1]+line[3])/line[4] - line[0]))
        elif (mask == 3):
            print("%.2f" % (line[4]*(line[0]+line[2]) - line[1]))
        elif (mask == 4):
            print("%.2f" % ((line[1]+line[3])/(line[0]+line[2])))
except EOFError:
    pass
