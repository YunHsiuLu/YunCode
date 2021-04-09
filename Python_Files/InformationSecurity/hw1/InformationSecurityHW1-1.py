import numpy as np

def Entropy(p):
	n = len(p)
	temp = 0
	for i in range(n):
		temp += p[i]*np.log2(p[i])
	temp = -temp
	return temp

def Expect(bc, p):
	n = len(bc)
	temp = 0
	for i in range(n):
		temp += bc[i]*p[i]
	return temp

p = [0.08167, 0.01492, 0.02782, 0.04253,
	0.12702, 0.02228, 0.02015, 0.06094,
	0.06966, 0.00153, 0.00772, 0.04025,
	0.02406, 0.06749, 0.07507, 0.01929,
	0.00095, 0.05987, 0.06327, 0.09056,
	0.02758, 0.00978, 0.02360, 0.00150,
	0.01974, 0.00074]

bc = [4, 6, 5, 5,
	3, 5, 6, 4,
	4, 9, 7, 5,
	5, 4, 4, 6,
	9, 4, 4, 3,
	5, 6, 5, 9,
	6, 9]

print(f'Entropy: {Entropy(p)}')
print(f'Expect Value: {Expect(bc, p)}')

