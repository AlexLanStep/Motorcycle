
from scipy import interpolate
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import numpy as np




if __name__ == '__main__':
    mas = np.zeros((3, 16))
    X = np.array([600.0, 1000.0, 1250.0, 1500.0, 1750.0, 2000.0, 2250.0, 2500.0, 2750.0, 3000.0, 3500.0, 4000.0, 4500.0, 5000.0, 57500.0, 65000.0 ])
    Y = np.array([0.0, 5.0049, 9.9976])
    mas[0,:] = np.array([0,     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0])
    mas[1,:] = np.array([35.9,  28.5,   23.0,   18.1,   16.2,   14.2,   10.7,   9.7,    9.1,    9.8,    10.9,   11.8,   13.40,  16.3,   19.0,   20.0 ])
    mas[2,:] = np.array([80.20, 68.6,   58.5,   53.3,   47.0,   45.0,   42.1,   39.8,   38.0,   36.7,   38.0,   35.3,   36.4,   38.1,   43.0,   42.0 ])
    f = interpolate.interp2d(X, Y, mas)
    VqR = f(1275, 7)


    fig = plt.figure()
    ax = fig.gca(projection='3d')

    # Make data.
    # X = np.arange(-5, 5, 0.25)
    # Y = np.arange(-5, 5, 0.25)
    X, Y = np.meshgrid(X, Y)


    # Plot the surface.
    surf = ax.plot_surface(X, Y, mas, cmap=cm.coolwarm, linewidth=0, antialiased=False)

    # Customize the z axis.
    # ax.set_zlim(-1.01, 1.01)
    # ax.zaxis.set_major_locator(LinearLocator(10))
    # ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))

    fig.colorbar(surf, shrink=0.5, aspect=5)

    plt.show()
    k =1
