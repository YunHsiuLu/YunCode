import random
a = [1, -1]
spin = [[[] for j in range(4)] for i in range(4)]
energy = [[[-999, -999, -999, -999] for j in range(4)] for i in range(4)]
for k in range(4):  # random spin up or down
    for j in range(4):
        for i in range(4):
            spin[k][j].append(random.choice(a))
print("spin: ", spin)
cate = [[[0, 0, 0, 0] for j in range(4)] for i in range(4)]
for k in range(4):  # category
    for j in range(4):
        for i in range(4):
            if (k == 0 or k == 3):
                if ((i == 0 and j == 0) or (i == 0 and j == 3) or (i == 3 and j == 0) or (i == 3 and j == 3)):
                    cate[k][j][i] = "corner"
                elif ((j == 0 or j == 3) and (i == 1 or i == 2)):
                    cate[k][j][i] = "border"
                elif ((i == 0 or i == 3) and (j == 1 or j == 2)):
                    cate[k][j][i] = "border"
                elif ((i == 1 or i == 2) and (j == 1 or j == 2)):
                    cate[k][j][i] = "b_area"
            elif (k == 1 or k == 2):
                if ((j == 0 or j == 3) and (i == 0 or i == 3)):
                    cate[k][j][i] = "border"
                elif ((j == 0 or j == 3) and (i == 1 or i == 2)):
                    cate[k][j][i] = "b_area"
                elif ((i == 0 or i == 3) and (j == 1 or j == 2)):
                    cate[k][j][i] = "b_area"
                else:
                    cate[k][j][i] = "center"

for k in range(4):  # energy calculation
    for j in range(4):
        for i in range(4):
            c_i = 1
            c_j = 1
            c_k = 1
            if (i == 3):
                c_i = -1
            if (j == 3):
                c_j = -1
            if (k == 3):
                c_k = -1
            if (cate[k][j][i] == "corner"):  # corner calculation done
                energy[k][j][i] = \
                    spin[k][j][i]*spin[k][j][i+c_i] \
                    + spin[k][j][i]*spin[k][j + c_j][i] \
                    + spin[k][j][i]*spin[k + c_k][j][i]
            elif (cate[k][j][i] == "border"):  # border calculation done
                if (i == 1 or i == 2):
                    energy[k][j][i] = \
                        spin[k][j][i]*spin[k][j][i-1] \
                        + spin[k][j][i]*spin[k][j][i+1] \
                        + spin[k][j][i]*spin[k][j+c_j][i] \
                        + spin[k][j][i]*spin[k+c_k][j][i]
                if (j == 1 or j == 2):
                    energy[k][j][i] = \
                        spin[k][j][i]*spin[k][j-1][i] \
                        + spin[k][j][i]*spin[k][j+1][i] \
                        + spin[k][j][i]*spin[k][j][i+c_i] \
                        + spin[k][j][i]*spin[k+c_k][j][i]
                if (k == 1 or k == 2):
                    energy[k][j][i] = \
                        spin[k][j][i]*spin[k-1][j][i] \
                        + spin[k][j][i]*spin[k+1][j][i] \
                        + spin[k][j][i]*spin[k][j][i+c_i] \
                        + spin[k][j][i]*spin[k][j+c_j][i]
            elif (cate[k][j][i] == "b_area"):  # b_area calculation done
                if (k == 0 or k == 3):
                    energy[k][j][i] = \
                        spin[k][j][i]*spin[k][j][i+1] \
                        + spin[k][j][i]*spin[k][j][i-1] \
                        + spin[k][j][i]*spin[k][j+1][i] \
                        + spin[k][j][i]*spin[k][j-1][i] \
                        + spin[k][j][i]*spin[k+c_k][j][i]
                elif (j == 0 or j == 3):
                    energy[k][j][i] = \
                        spin[k][j][i]*spin[k][j][i+1] \
                        + spin[k][j][i]*spin[k][j][i-1] \
                        + spin[k][j][i]*spin[k][j+c_j][i] \
                        + spin[k][j][i]*spin[k+1][j][i] \
                        + spin[k][j][i]*spin[k-1][j][i]
                else:
                    energy[k][j][i] = \
                        spin[k][j][i]*spin[k][j][i+c_i] \
                        + spin[k][j][i]*spin[k][j+1][i] \
                        + spin[k][j][i]*spin[k][j-1][i] \
                        + spin[k][j][i]*spin[k+1][j][i] \
                        + spin[k][j][i]*spin[k-1][j][i]
            else:  # center calculation done
                energy[k][j][i] = \
                    spin[k][j][i]*spin[k][j][i+1] \
                    + spin[k][j][i]*spin[k][j][i-1] \
                    + spin[k][j][i]*spin[k][j+1][i] \
                    + spin[k][j][i]*spin[k][j-1][i] \
                    + spin[k][j][i]*spin[k+1][j][i] \
                    + spin[k][j][i]*spin[k-1][j][i]
print("Energy: ", energy)
