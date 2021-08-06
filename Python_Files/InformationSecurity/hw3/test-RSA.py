e = 7
d = 103
N = 143

secret = 53 #110101

#cipher = pow(secret, e, N)
cipher = 92

cipher *= pow(2, -e, N)
m = pow(cipher, d, N)
m_b = bin(m)[2:]
print(m_b)
if len(m_b) > 1:
	print(m_b[-2])
