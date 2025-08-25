init = input()
prompt = int(input())
for i in range(prompt):
    line = input().split()
    if (len(line) == 1):
        init = init[::-1]
    elif (len(line) == 2):
        if (line[0] == "APPEND"):
            init += line[1]
        elif (line[0] == "PREPEND"):
            init = line[1] + init
    else:
        if (line[0] == "INSERT"):
            init = init[0:int(line[1])] + line[2] + init[int(line[1]):]
        elif (line[0] == "DELETE"):
            init = init[0:int(line[1])] + init[int(line[1])+int(line[2]):]
        elif (line[0] == "REPLACE"):
            init = init.replace(line[1], line[2])
        elif (line[0] == "SLICE"):
            init = init[int(line[1]):int(line[2])]
print(init)
