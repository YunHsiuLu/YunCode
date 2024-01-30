n = int(input())

div = {}
c = 2

while not n == 1:
	if (n % c == 0):
		if not c in div : div[c] = 1
		else : div[c] += 1
		n /= c
	else:
		c += 1

ans = ""
for k in div:
	if div[k] > 1:
		ans += "%d^%d " % (k, div[k])
	else:
		ans += "%d " % (k)
	ans += "* "
print(ans[:-2])

