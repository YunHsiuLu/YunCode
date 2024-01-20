def Add(l1, l2, m=1):
	ind = min(len(l1), len(l2))
	lt1 = l1 if len(l1) >= len(l2) else l2
	lt2 = l1 if len(l1) < len(l2) else l2
	l = [i for i in lt1]
	for i in range(-1, -ind-1, -1):
		l[i] = l[i] + lt2[i]*m
	return l

def Poly_to_par_and_exp(poly):
	Par = []
	Exp = []
	first = poly[0]
	lar_exp = 0
	for s in range(len(first)):
		if first[s] == 'x':
			lar_exp = int(first[s+1:]) if s+1 != len(first) else 1
	#print('large exponent: %d' % lar_exp)

	Par = [0 for _ in range(lar_exp+1)]

	for item in poly:
		par = -999
		exp = -999
		if 'x' in item:
			pos_x = item.index('x')
			if pos_x == 0:
				par = 1
			elif pos_x == 1 and item[0] == '-':
				par = -1
			else:
				par = int(item[0:pos_x])
			if pos_x+1 == len(item):
				exp = 1
			else:
				exp = int(item[pos_x+1:])
		else:
			exp = 0
			par = int(item)
		
		#print('parameter, exponent = %d, %d' % (par, exp))
		Par[lar_exp-exp] = par

	#print('parameters: ', Par)
	return Par

def cut_poly(s):
	poly = []
	temp = ''
	for i in range(len(s)):
		if s[i] == '+' or s[i] == '-':
			poly.append(temp)
			temp = ''
		temp = temp + s[i]
		if '+' in temp:
			temp = temp[1:]	
	poly.append(temp)
	#print('poly cut: ', poly)
	return Poly_to_par_and_exp(poly)
		
def Divide(par_n,par_d):
	step = len(par_n) - len(par_d) + 1
	par_q = [0 for _ in range(step)]
	par_r = [0 for _ in range(len(par_d) - 1)] if len(par_d)-1 > 0 else [0]
	for i in range(step):
		q = -999
		t = par_n[i:i+len(par_d)]
		q = t[0]/par_d[0]
		par_q[i] = q
		par_n[i:i+len(par_d)] = Add(t, par_d, -q)
	par_r = par_n[-len(par_r):]
	#print(par_n, par_d, par_q, par_r)
	return par_q, par_r

def Multiply(parA, parB):
	lar_A = len(parA) - 1
	lar_B = len(parB) - 1
	T = [0 for _ in range(lar_A + lar_B + 1)]
	for i in range(len(parA)):
		for j in range(len(parB)):
			T[j+i] += int(parA[i])*int(parB[j])
	return T

def PrintPoly(**kwargs):
	for name, poly in kwargs.items():
		P = ''
		isConst = False
		ppar = str(int(poly[0])) if int(poly[0]) > 1 else ''
		pexp = str(len(poly)-1) if len(poly)-1 > 1 else ''
		isConst = True if len(poly)-1 == 0 else False
		px = 'x' + pexp if not isConst else ''
		P = P + ppar + px
		for i in range(1, len(poly)):
			ppar = str(int(poly[i])) if int(poly[i]) > 1 else ''
			pexp = str(len(poly)-i-1) if len(poly)-i-1 > 1 else ''
			isConst = True if len(poly)-i-1 == 0 else False
			px = 'x' + pexp if not isConst else ''
			P = P + '+' + ppar + px
		print('%s is: %s' % (name, P))

def Divide_Poly(N="x3+x2+x+1",D="x-1"):

	print()
	print("Dividend is %s" % N)
	Par_N = cut_poly(N)
	print("Divisor is %s" % D)
	Par_D = cut_poly(D)
	print()
	print("Calculating Quotient and Reminder...")
	Par_Q, Par_R = Divide(Par_N, Par_D)
	print()

	PrintPoly(Quotient = Par_Q, Reminder = Par_R)
	return Par_Q, Par_R

def find_inv(a, p):
	isNeg = False if a > 0 else True
	a = abs(a)
	i = 1
	while (a*i % 1 != 0):
		i += 1
	t = int(a*i)
	s = 1
	while (i*s % p != t):
		s += 1
	if isNeg:
		s = -s % p
	return s

def Inverse_polynomial(N=5, f=[1,0,1], p=3):
	n = [0 for _ in range(N+1)]
	n[0] = 1
	n[-1] = -1
	r = [n, f]
	t = [[0], [1]]
	q = []
	qt = []
	rt = []
	step = 0
	space = 'x%d-1' % N
	print('Space is: Z_%d[x]/%s' % (p, space))
	print('\tf(x) par is:', f)

	while (rt != [0]):
		print('step: %d' % step)
		print(r[step], r[step+1])
		qt, rt = Divide(r[step], r[step+1])
		for i in range(len(qt)):
			qt[i] = int(qt[i] % p) if qt[i] % 1 == 0 else find_inv(qt[i], p)
		for i in range(len(rt)):
			rt[i] = int(rt[i] % p) if rt[i] % 1 == 0 else find_inv(rt[i], p)
		
		start = 0
		for i in range(len(rt)):
			if rt[i] != 0:
				start = i
				break
		rt = rt[start:]
		r.append(rt)
		q.append(qt)
		step += 1

	for i in range(len(q)-1):
		m = Multiply(t[i+1], q[i])
		s = Add(t[i], m)
		for j in range(len(s)):
			s[j] = s[j] % p
		t.append(s)

	result = t[-1]
	for i in range(len(result)):
		result[i] = -result[i] % p

	print('\tthe inverse of f(x) par is:', result)





