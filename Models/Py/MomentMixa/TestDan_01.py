
# Адаптивная скользящая средняя Кауфмана
# https://ru.wikipedia.org/wiki/%D0%90%D0%B4%D0%B0%D0%BF%D1%82%D0%B8%D0%B2%D0%BD%D0%B0%D1%8F_%D1%81%D0%BA%D0%BE%D0%BB%D1%8C%D0%B7%D1%8F%D1%89%D0%B0%D1%8F_%D1%81%D1%80%D0%B5%D0%B4%D0%BD%D1%8F%D1%8F_%D0%9A%D0%B0%D1%83%D1%84%D0%BC%D0%B0%D0%BD%D0%B0

import numpy as np
from scipy import signal
import matplotlib.pyplot as plt

def calculate_ema(prices, days, smoothing=2):
    ema = [sum(prices[:days]) / days]
    for price in prices[days:]:
        ema.append((price * (smoothing / (1 + days))) + ema[-1] * (1 - (smoothing / (1 + days))))

    _count = len(prices)
    _x = _count - len(ema)
    z =  np.zeros((_x))
    z[0:_x] = ema[0]
    ema = np.r_[z, ema]
    return ema

def MomentChanel(dan, n):
    _count = len(dan)
    hi =  np.zeros((_count))
    low = np.zeros((_count))
    midl = np.zeros((_count))
    x = dan[0]
    hi[0] = x
    low[0] = x
    midl[0]=x

    k0 = n    # индкх для Hi
    k1 = n    # индкх для Low
    for i in range(1, _count):
        k0 -=1
        k1 -=1
        hi[i] = hi[i-1]
        low[i] = low[i-1]

        if(dan[i] >= hi[i-1]) or k0<0:
            hi[i] = dan[i]
            k0 = n

        if(dan[i] <= low[i-1])  or k1<0:
            low[i] = dan[i]
            k1 = n

        midl[i] = (hi[i]+low[i])/2.0
    return (hi, low, midl)

if __name__ == '__main__':
    with open('E:\Motorcycle\Data\Py\Moment\Filtr/ACCFiltr.npy', 'rb') as f:
        Acc = np.load(f)
    Acc=Acc[:-6]

    _count = len(Acc)
    t = np.linspace(0, _count, _count, False, dtype=np.int32)  # 1 second

    # NPoint=75
    # resul =  MomentChanel(Acc, 35)
    # ema= np.array(calculate_ema(resul[2], 40, smoothing=0.25))
    #
    # resul =  MomentChanel(ema, 25)
    # ema= np.array(calculate_ema(resul[2], 20, smoothing=0.5))

    ema= np.array(calculate_ema(Acc, 15, smoothing=0.25))
#    resul =  MomentChanel(ema, 25)
    ema= np.array(calculate_ema(ema, 15, smoothing=0.5))
    ema= np.array(calculate_ema(ema, 10, smoothing=0.5))


    # resul =  MomentChanel(ema, NPoint)
    # ema= np.array(calculate_ema(resul[2], 50, smoothing=0.75))

#    ema= np.array(calculate_ema(ema, 30, smoothing=2))
#    ema=  np.array(calculate_ema(ema , 20, smoothing=2))


    plt.figure(1)
#    plt.plot(t, Acc, t, resul[0], t, resul[1], t, resul[2] )
#    plt.plot(t, Acc, t, resul[2] )
#    plt.plot(t, Acc, t, ema, t, ema1 )
    plt.plot(t, Acc, t, ema)
    plt.show()

    k=1

    t = np.linspace(0, len(Acc), len(Acc), False)
    sig = Acc
    fig, (ax1, ax2) = plt.subplots(2, 1, sharex=True)
    ax1.plot(t, sig)
    ax1.set_title('исходный сигнал')

#    sos = signal.butter(2, 20, 'Low', fs=100, output='sos')
#    filtered = signal.sosfilt(sos, sig)
    filtered= np.array(calculate_ema(sig, 50, smoothing=2))
    filtered= np.array(calculate_ema(filtered, 30, smoothing=2))
    filtered= np.array(calculate_ema(filtered, 20, smoothing=2))
    filtered[0:5] = filtered[5]
    ax2.plot(filtered)
    ax2.set_title('после фильтра')
    ax2.set_xlabel('Time [seconds]')
    plt.tight_layout()
    plt.show()

'''

'''
