def CalMatrix(mat):
    n = len(mat)
    NewMat = [[0 for _ in range(n)] for i in range(n)]
    temp_mat = mat
    d = [1 for _ in range(n)]
    power = 1
    print(mat)
    while (True):
        check = 0
        for ind in range(n):
            if (d[ind] <= 0.00001):
                check += 1
        if check == n:
            break
        for i in range(n):
            for j in range(n):
                for c in range(n):
                    NewMat[i][j] += mat[i][c]*temp_mat[c][j]
        for ind in range(n):
            d[ind] = abs(NewMat[0][ind] - temp_mat[0][ind])
        temp_mat = NewMat
        NewMat = [[0 for _ in range(n)] for i in range(n)]
        power += 1
        print("power: %d" % (power))
    return temp_mat

testMatrix = [
    [0.5, 0.0, 0.5],
    [0.3, 0.7, 0.0],
    [0.5, 0.5, 0.0]
]
testMatrix = CalMatrix(testMatrix)
n = len(testMatrix)
for i in range(n):
    for j in range(n):
        print("%.2f" % (testMatrix[i][j]), end=" ")
    print()
#(0,0) = (0,0)*(0,0) + (0,1)*(1,0)
#(0,1) = (0,0)*(0,1) + (0,1)*(1,1)
#(1,0) = (1,0)*(0,0) + (1,1)*(1,0)
#(1,1) = (1,0)*(0,1) + (1,1)*(1,1)
