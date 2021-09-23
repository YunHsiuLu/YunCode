S = '0x0000000F'
import time
# w + x + y + z = 4
count = 0
zeros = 28
avg = 0
for _ in range(10):
	heap = []
	s = '0'*zeros
	start = time.time_ns()
	for i in range(zeros+1):
		t1 = s[0:i] + '1' + s[i:]
		for j in range(zeros+2):
			t2 = t1[0:j] + '1' + t1[j:]
			for k in range(zeros+3):
				t3 = t2[0:k] + '1' + t2[k:] + '1'
				if not t3 in heap:
					heap.append(t3)
	end = time.time_ns()
	avg += (end-start)
avg = int(avg/10/1000)
print(len(heap))
print('time: %d ms' % avg)
