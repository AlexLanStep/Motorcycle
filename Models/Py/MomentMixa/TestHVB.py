
import numpy as np
from numpy.fft import rfft
import os
import matplotlib.pyplot as plt
from scipy import signal
# from __future__ import division, print_function
from numpy.random import randn


if __name__ == '__main__':
    print("--  start ---")
    with open('E:\Motorcycle\Data\Py\Moment\Filtr/HVB.npy', 'rb') as f:
        sigBasa = np.load(f)

#     plt.figure(1)
#     plt.plot(sig)
#
#     plt.figure(2)
#     b, a = signal.butter(4, 0.01, 'lowpass')   # Конфигурационный фильтр 8 указывает порядок фильтра
#     out = signal.filtfilt(b, a, sig)  # данные - это сигнал, который нужно отфильтровать
#
# #    b, a = signal.butter(2, 0.1, 'highpass')   # Конфигурационный фильтр 8 указывает порядок фильтра
# #    out =1.5* signal.filtfilt(b, a, sig)  # данные - это сигнал, который нужно отфильтровать
#
#     plt.plot(out)
#
#     plt.figure(3)
    _count = len(sigBasa)
    t = np.linspace(0, _count, _count, False)  # 1 second
#    fig, (ax1, ax2, ax3) = plt.subplots(3, 1, sharex=True)
#    ax1.plot(t, sigBasa)
    sos = signal.ellip(8, 1, 8, 18, 'hp', fs=100, output='sos') # 17
    filtered = signal.sosfilt(sos, sigBasa)
#    ax2.plot(t, filtered)
        # ax2.set_title('After 17 Hz high-pass filter')
        # ax2.axis([0, 1, -2, 2])
        # ax2.set_xlabel('Time [seconds]')
    ss = sigBasa - filtered
#    ax3.plot(t, ss)
#    plt.tight_layout()

    plt.figure(1)
    plt.plot(t, sigBasa, t, ss)
    plt.show()


