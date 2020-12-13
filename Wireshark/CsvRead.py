import csv
import os

ListDir = os.listdir('data_csv/.')
ListDir = sorted(ListDir, key = lambda x: x[4:9])
#print(ListDir)
for item in ListDir:
    path = 'data_csv/' + item
    print('%s: ' % (item))
    with open(path, newline='') as csvfile:
        rows = csv.reader(csvfile, delimiter=',')
        print(rows)