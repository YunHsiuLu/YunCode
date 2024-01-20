import random
A = 'LRUDFBMlrudfb'
S = ['', '\'', '2']

for _ in range(16):
	s = random.choice(A) + random.choice(S)
	print(s, end=' ')

print()