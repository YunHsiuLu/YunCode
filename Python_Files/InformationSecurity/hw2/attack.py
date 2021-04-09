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
c_block = [[] for _ in range(len(cipher))]
for i in range(len(cipher)):
	for j in range(0, len(cipher[i]), 2):
		c_block[i].append(cipher[i][j:j+2])
	
print(c_block)

for i in range(1, len(cipher)):
	f = open("inter%d.txt" % i, "r")
	print(f.readline())
	f.close()
