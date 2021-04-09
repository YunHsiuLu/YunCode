import numpy as np
import matplotlib.pyplot as plt

fig, ax = plt.subplots(figsize=(8, 5))


def plot_gif(x, y):
    ax.cla()
    ax.plot(x, y)
    fig.canvas.draw()
    img = np.frombuffer(fig.canvas.tostring_rgb(), dtype='uint8')
    img = img.reshape(fig.canvas.get_width_height()[::-1] + (3,))
    return img


def SWAP(data, i, j):
    temp = data[i]
    data[i] = data[j]
    data[j] = temp


def read_2darray_element(data):
    temp = np.array([])
    for i in range(len(data)):
        for j in range(len(data[i])):
            temp = np.append(temp, data[i][j])
    return temp


def find_correct_place(data, item):
    for j in range(len(item)):
        for i in range(len(data)-1, -1, -1):
            if (data[i] < item[j]):
                if (i == len(data)-1):
                    data.append(item[j])
                    break
                else:
                    data.insert(i+1, item[j])
                    break
            else:
                if (i == 0):
                    data.insert(0, item[j])


def sort_quick(data):
    if (len(data) == 1):
        return data
    pivot = data[0]
    data[0] = -999
    data = np.append(data, 999)
    current_i = 0
    current_j = len(data)
    while(1):
        for i in range(current_i, len(data)):
            if (data[i] > pivot):
                current_i = i
                break
        for j in range(current_j-1, -1, -1):
            if (data[j] < pivot):
                current_j = j
                break
        if (current_i > current_j):
            break
        SWAP(data, current_i, current_j)
    data[0] = pivot
    data = np.delete(data, len(data)-1)
    SWAP(data, 0, current_j)
    k = current_j
    if (k != 0):
        data[0:k] = sort_quick(data[0:k])
    if (k != len(data)-1):
        data[k+1:len(data)] = sort_quick(data[k+1:len(data)])
    return data
