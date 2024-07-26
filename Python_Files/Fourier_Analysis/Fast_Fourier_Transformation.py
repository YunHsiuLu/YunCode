import numpy as np
import matplotlib.pyplot as plt

filename = 'RPM600' # 600, 630, 660, 690, 720
n = 512
t, x, y = [], [], []
fy = open(filename+'_Y.txt', 'r')
lines = fy.readlines()
for line in lines[1:n+1]:
    tmp = [float(t) for t in line.split()]
    t.append(tmp[0])
    y.append(tmp[1])

fx = open(filename+'_X.txt', 'r')
lines = fx.readlines()
for line in lines[1:n+1]:
    tmp = [float(t) for t in line.split()]
    x.append(tmp[1])

t = np.array(t)
x = np.array(x)
y = np.array(y)
fs = (n-1)/(t[-1]-t[0]) # Sampling frequency

fft_x_result = np.fft.fft(x)
x_frequencies = np.fft.fftfreq(len(fft_x_result), 1/fs)
fft_y_result = np.fft.fft(y)
y_frequencies = np.fft.fftfreq(len(fft_y_result), 1/fs)

fig_x, ax_x = plt.subplots(2, 1, figsize=(12, 8))
ax_x[0].plot(t, x, 'r.')
ax_x[0].set_title('Original Signal')
ax_x[0].set_xlabel('Time (s)')
ax_x[0].set_ylabel('Amplitude')
ax_x[1].plot(x_frequencies[1:n//2], np.abs(fft_x_result)[1:n//2])
ax_x[1].set_title('Fourier Transform')
ax_x[1].set_xlabel('Frequency (Hz)')
ax_x[1].set_ylabel('Amplitude')
plt.tight_layout()

fig_y, ax_y = plt.subplots(2, 1, figsize=(12, 8))
ax_y[0].plot(t, y, 'r.')
#ax_y[0].plot(t, 50*np.sin(2*np.pi*1/0.8*t)+220, 'k-')
ax_y[0].set_title('Original Signal')
ax_y[0].set_xlabel('Time (s)')
ax_y[0].set_ylabel('Amplitude')
ax_y[1].plot(y_frequencies[1:n//2], np.abs(fft_y_result)[1:n//2])
ax_y[1].set_title('Fourier Transform')
ax_y[1].set_xlabel('Frequency (Hz)')
ax_y[1].set_ylabel('Amplitude')
plt.tight_layout()

#plt.show()
fig_x.savefig(filename+'_X.png') # change file with .jpg, .pdf, etc.
fig_y.savefig(filename+'_Y.png')
