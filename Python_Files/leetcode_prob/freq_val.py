list = [1, 2, 3, 4]
freq_val = []
for i in range(0, len(list), 2):
    freq = list[i]
    val = list[i+1]
    for j in range(freq):
        freq_val.append(val)
print(freq_val)