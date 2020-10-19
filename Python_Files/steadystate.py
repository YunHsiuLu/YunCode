def CalMatrix(mat):
    n = len(mat)
    new_mat = [[0 for _ in range(n)] for i in range(n)]
    d1 = mat[0][0] - mat[1][0]
    d2 = mat[0][1] - mat[1][1]
    power = 1
    while (abs(d1) >= 0.005 or abs(d2) >= 0.005):
        for i in range(n):
            for j in range(n):
                for c in range(n):
                    new_mat[i][j] += mat[i][c]*mat[c][j]
        mat = new_mat
        new_mat = [[0 for _ in range(n)] for i in range(n)]
        power += 1
        d1 = mat[0][0] - mat[1][0]
        d2 = mat[0][1] - mat[1][1]
        print("power: %d" % (power))
        print(mat)
    return mat

testMatrix = [[0.95, 0.05], [0.6, 0.4]]
CalMatrix(testMatrix)

#(0,0) = (0,0)*(0,0) + (0,1)*(1,0)
#(0,1) = (0,0)*(0,1) + (0,1)*(1,1)
#(1,0) = (1,0)*(0,0) + (1,1)*(1,0)
#(1,1) = (1,0)*(0,1) + (1,1)*(1,1)