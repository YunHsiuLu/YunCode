from Inverse_polynomial import Inverse_polynomial

f = [0 for _ in range(19)]
f[len(f)-1-18] = 3
f[len(f)-1-9] = -3
f[len(f)-1-8] = 3
f[len(f)-1-4] = -3
f[len(f)-1-2] = -3
f[len(f)-1-0] = 1
print(f)

Inverse_polynomial(23, f, 31)