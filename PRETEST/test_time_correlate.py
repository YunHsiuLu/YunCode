import time
import numpy as np
import matplotlib.pyplot as plt

private = '1010101010011010'

def guess_private(guess):
	if len(guess) != len(private):
		return False
	for i in range(len(guess)-1, -1, -1):
		if guess[i] != private[i]:
			return False
	return True

for i in range(-1, len(private)):

	if i == -1:
		guess = private
	else:
		t = ''
		if private[i] == '1':
			t = '0'
		else:
			t = '1'
		guess = private[0:i] + t + private[i+1:]
	
	avg_cost = 0
	runtime = 50
	for _ in range(runtime):
		start = time.time_ns()
		guess_private(guess)
		end = time.time_ns()
		avg_cost += end - start

	avg_cost /= runtime
	print(f'{i}: Average cost: {avg_cost}')




