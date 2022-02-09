import csv
import matplotlib.pyplot as plt
import pylab
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.colors import LinearSegmentedColormap
import numpy as np


if __name__ == '__main__':
    _path = "E:\\test.csv"
    a= []
    b=[]
    with open(_path, newline='') as File:
        reader = csv.reader(File, delimiter=";")
        for row in reader:
            a+=[float(row[0].replace(',',"."))]
            b+=[float(row[1].replace(',',"."))]
            print(row)
            kk=1

    plt.figure()
#    plt.title(title)
    _count = len(a)
#    t= np.linspace(0, len(a)/100, len(a), dtype=np.int32)
    t= np.linspace(0, len(a)/100, len(a), endpoint=False)
    plt.plot(t,a, t, b)
#    plt.plot(t, b)
    plt.grid()
#     plt.figure()
# #    plt.title(title)
#     plt.plot(b)
#     plt.grid()

    plt.show()

    k=1
