import requests

IV = "00112233445566778899aabbccddeeff"
cipher = ["00112233445566778899aabbccddeeff",
		 "f9473924bd62ba19f2dd19c309289477",
         "65786c8d4972fd132ec97a3a3e518191",
         "7652a0dc44cb493881bdd841103b8bca",
         "2d4824eef54b306f093bdc5a17dc9f46",
         "a862217ecb6b80244fdba90fbb13c72b",
         "ab3de8d9653be21d635a0f8d59712836",
         "06eb64c0fbb922afd9db007f94fb9e24",
         "a899a6c0a65b687b85f45d4840d47df4"]

guess = ""
n = len(cipher)
guess_block = []
inter = []
answer = [[] for _ in range(n)]
for i in range(n):
	inter.append(["0"*32])

inter[0] = IV


#index = 8 #down to 1
for index in range(8, 0, -1):
	print(f"index: {index}")
	guess_block = [["0"*32] for _ in range(index+1)]
	guess_block[index] = cipher[index]

	#pos = 30
	padding = 0 #up to 16
	testing = "0"*32
	for pos in range(30, -2, -2):
		padding += 1
		print("\tpadding: ", padding)
		temp_h = ""
		for i in range(pos, 30, 2):
			#print("\t***in temp_h loop")
			temp = int(testing[i+2:i+4], base=16) ^ padding
			temp_h += "0" + hex(temp)[-1] if temp < 16 else hex(temp)[-2:]
		for i in range(256):
			h = "0" + hex(i)[-1] if i < 16 else hex(i)[-2:]
			testing = testing[0:pos] + h + temp_h
			guess_block[index-1] = testing
			for j in range(index+1):
				guess += guess_block[j]

			URL = "http://140.122.185.210:8080/oracle/" + guess
			r = requests.get(URL)
			if r.text == "valid":
				break
		print()
		temp_inter = int(h, base=16) ^ padding
		temp_inter = "0" + hex(temp_inter)[-1] if temp_inter < 16 else hex(temp_inter)[-2:]
		inter[index] = inter[index][0:pos] + temp_inter + inter[index][pos+2:]
		print(f"\ttesting{padding}: ", testing)
		print("\tinter:    ", inter[index])

for i in range(len(inter)):
	inter[i] = [inter[i][j:j+2] for j in range(0, len(inter[i], 2))]

answer[0] = inter[0]
for i in range(len(inter) - 1):
	for j in range(len(inter[i])):
		answer[i+1].append(chr(int(inter[i][j], base=16) ^ inter[i+1][j], base=16))






