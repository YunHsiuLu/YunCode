import pyshark
import os

ListDir = []
cap = []

for filename in os.listdir('data_pcap/.'):
    if filename[0:7] == 'testpks':
        ListDir.append('data_pcap/' + filename)

ListDir = sorted(ListDir, key=lambda x: x[18:23])
print(ListDir)

for i in range(len(ListDir)):
    temp = pyshark.FileCapture(ListDir[i])
    temp.load_packets()
    cap.append(temp)

print(cap)
