def gcd(a,b):
	if (a==0):
		return b
	return gcd(b % a, a)

def phi(n):
	result = 1
	for i in range(2, n):
		if (gcd(i,n) == 1):
			result += 1
	return result

p = 17
q = 33
N = p*q
phi = phi(N)
e = 7
d = 100
while (e*d % phi != 1):
	d += 1

m_p = [11,22,33,44,55,66,77,88,99,110,121,132]
c_p = [i**e % N for i in m_p]
dec = [i**d % N for i in c_p]
print()
print('p =', p)
print('q =', q)
print('pk =', e, 'sk =', d)
print('plaintext  =', m_p)
print('ciphertext =', c_p)
print('decryption =', dec)
print()
