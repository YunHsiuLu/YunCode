import primes
temp = primes.a
temp_c = primes.c
flag = False
while temp_c < primes.c * 100:
    n = len(temp)
    for i in range(n):
        if temp_c % temp[i] == 0:
            break
        if i == n-1:
            temp.append(temp_c)
    temp_c += 1
s1 = "a = " + str(temp) + "\n"
fp = open("primes.py", "w")
fp.write(s1)
fp.write("c = a[-1]\n")
fp.close()
