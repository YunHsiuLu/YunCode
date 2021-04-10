# -*- coding: utf-8 -*-
"""
Created on Sun Apr 11 00:38:35 2021

@author: user
"""
a = ["4977024a2b204613e7f78dcfecb68090",
     "8e674e4cd810df398bb26ce37e49fa03",
     "450c03ad2e1dd1335aa11f541e38f5b1",
     "123dc5af2aec3d18ecdcac357549abbd",
     "45214786d53b511b611ba53562fceb27",
     "c3070f5e870ef74d3cfbea6ec961a847",
     "c711c89809528178433361ad0e1e4652",
     "639908a195dd0ca6d0d209769df2972d"]
c = ["00112233445566778899aabbccddeeff",
     "f9473924bd62ba19f2dd19c309289477",
     "65786c8d4972fd132ec97a3a3e518191",
     "7652a0dc44cb493881bdd841103b8bca",
     "2d4824eef54b306f093bdc5a17dc9f46",
     "a862217ecb6b80244fdba90fbb13c72b",
     "ab3de8d9653be21d635a0f8d59712836",
     "06eb64c0fbb922afd9db007f94fb9e24",
     "a899a6c0a65b687b85f45d4840d47df4"]
A = [[] for _ in range(8)]
C = [[] for _ in range(8)]
P = [[] for _ in range(8)]

for i in range(8):
    for j in range(0, 32, 2):
        A[i].append(a[i][j:j+2])
        C[i].append(c[i][j:j+2])

print("message is: ")
for i in range(8):
    for j in range(16):
        if i == 0:
            temp = int(C[i][j], base=16) ^ int(A[i][j], base=16)
            P[i].append("0" + hex(temp)[-1] if temp < 16 else hex(temp)[-2:])
            print(chr(temp), end="")
            
        else:
            temp = int(C[i][j], base=16) ^ int(A[i][j], base=16)
            P[i].append("0" + hex(temp)[-1] if temp < 16 else hex(temp)[-2:])
            print(chr(temp), end="")
print()