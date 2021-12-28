
from Regression import Regression
import numpy as np
import matplotlib.pyplot as plt

if __name__ == '__main__':
   print(" ==  TEST signalov Moment")

   # _max_point =20
   # m = np.zeros(_max_point)
   # m[_max_point-1] = 1
   # m[1]=9
   # x = m[1:_max_point]
   # m[:_max_point-1] = m[1:_max_point]
   # m[_max_point-1] = 2
   # m[0:_max_point-1] = m[1:_max_point]
   # m[_max_point-1] = 3
   # m[0:_max_point-1] = m[1:_max_point]
   # m[_max_point-1] = 4
   # k=1
   #


   'E:\Motorcycle\Data\Py\Moment/1/Acc.npy'  # Acc.npy  Moment.npy  Oborot.npy
   Acc = np.load('E:\Motorcycle\Data\Py\Moment/1/Acc.npy')
   Acc= Acc[690:]
   # plt.figure()
   # plt.plot(Acc)
   # plt.show()

   nPointTest = 200
   nReg = 20
   _rg = Regression()
   for i in range(nPointTest):
      print(i)
      __y = Acc[i]

      if i>=6 or __y>0:
         jjj=1
      dsd = _rg.CalcStep(nReg, Acc[i])
      kkk=1
   k=1
