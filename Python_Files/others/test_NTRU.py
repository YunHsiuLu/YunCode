from Inverse_polynomial import Add, Multiply, Divide
print()
r = [1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,-1,0,0]
h = [-13,-15,0,12,-14,0,8,-14,-6,14,-3,7,-5,-14,3,10,5,-8,0,0,4,1,8]
m = [1,0,0,-1,0,0,0,0,1,0,0,0,0,0,0,-1]
N = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1]
f = [3,0,0,0,0,0,0,0,0,-3,3,0,0,0,-3,0,-3,0,1]
g = [3,0,0,0,0,3,0,0,3,0,0,0,0,0,3,0,-3,0]

print('encrypt message is: ', m)
t = Multiply(r,h)
_, t = Divide(t, N)
result = Add(t, m)
_, result = Divide(result, N)
for i in range(len(result)):
	result[i] = result[i] % 31
print('decrypt test......')

_, a1 = Divide(Multiply(r, g), N)
_, a2 = Divide(Multiply(f, m), N)
a = Add(a1, a2)
for i in range(len(a)):
	a[i] = a[i] if abs(a[i]) < 15.5 else a[i] - 31
	a[i] = int(a[i] % 3)
while (a[0] == 0):
	a.pop(0)
print()
print('decrypt message is: ', a)
m = [i % 3 for i in m]
print('decrypt success? ', a == m, '(in Z3)')
print()
print('If we can solve CVP......')
t = [i % 31 for i in t]
print('    we can know the nearest vector (r, r*h mods q) to (0, y)')
print('    (0, y) = (r, r*h mods q) + (-r, m)')
print()
print('    r*h mods q = ', t)
print()
print('    encrypt message is: y = ', result)
temp = Add(result, t, -1)
while (temp[0] == 0):
	temp.pop(0)
temp = [int(i) % 3 for i in temp]
print('    Simply know that m = (y - r*h mods q) mods p')
print('    ', temp)
print('is it same as message m?', temp == m)
print()


