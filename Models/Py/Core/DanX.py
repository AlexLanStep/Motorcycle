import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import pyarrow

class DanX:
    def __init__(self, *params):
        self._work_dir = params[0]
        self._file = self._work_dir + "\\" + params[1]
        print(f"    ===>  рабочий файл  {params[1]}  ")
        self.LoadFeather()
        self._basaName = ['Speed',
                          'Fr1.x', 'Fr1.y', 'Fr1.z',
                          'YawAcc', 'YawVel', 'PitchVel', 'RollVel',
                          'TF.muRoad', 'TR.muRoad',
                          'TF.vBelt', 'TR.vBelt',
                          'TR.Frc.x', 'TR.Frc.y', 'TR.Frc.z',
                           'Engine.Trq', 'Engine.rotv',
                          'Time']

    #        os.chdir(self._work_dir)

    def Show(self):
        plt.show()

    def Get(self, name):
        if 'str' in str(type(name)):
            return np.array(self.df[name].values)
        elif 'list' in str(type(name)):
            return np.array(self.df[name])
        else:
            return None

    def Plot(self, name):
        if 'str' in str(type(name)):
            df = pd.Series(self.df[name].values)  # self.df[name].values
            df = df.cumsum()
            plt.figure()
            plt.title(name)
#            df.plot()
        #            plt.show()
        elif 'list' in str(type(name)):
            __couunt = len(name)
            dd = self.df[name]
            dd.plot(subplots=True, figsize=(__couunt, 1))
        #            plt.show()
        else:
            return

    def AddColumn(self, d, name):
        self.df[name] = pd.Series(d, index=self.df.index)

    def LoadFeather(self):
        self.df = pd.read_feather(self._file)

    def SaveFeather(self, xfile=""):
        if xfile=="":
            self.df.to_feather(self._file)
        else:
            self.df.to_feather(xfile)

    # def _getFSignal(self, name):
    #     fname = "f" + name
    #     self.tran.danx.AddColumn(self.tran.myFilter.FEllip(self.tran.danx.Get(name), self._Kus), fname)

    def GetSignalFun(self, name, pref, fun, _Kus=1):
        print(f"  ==-=-=---> {name}")
        self.AddColumn(fun(self.Get(name), _Kus), pref+name)
        return self.Get(pref + name)

    def GetAllSignal(self, name, func):
        print(f"  ==-----> {name}")
        __eSpf = name[:4]
        __eSp = name[:3]
        if __eSpf == "eSpf":
            __name = name[4:]
            if not(__name in self.df.columns):
                   return None

            __fname = "f" + __name
            if not(__fname in self.df.columns):
                self.GetSignalFun(__name, "f", func.FEllip, 0)

            eSpectr, mSpectr = func.FFTAll(self.Get(__fname))
            self.AddColumn(eSpectr, "eSpf" + __name)
            return self.Get("eSpf" + __name)

        elif __eSp == "eSp":
            __name = name[3:]
            eSpectr, mSpectr = func.FFTAll(self.Get(__name))
            self.AddColumn(eSpectr, "eSp" + __name)
            return self.Get("eSp" + __name)
        else:
            return None

    def DeleteBasa(self):
        self.df = self.df.drop(columns= list(set(self.df.columns) - set(self._basaName)))
        self.SaveFeather()

    def Slippage(self):
        R = (17*0.0254)*3             #радиус колеса
        x = 1-(self.Get('TR.vBelt')/(self.Get('Engine.rotv')*R ))
        basa = x[30]
        x[:30]=basa
        self.AddColumn(x, "Slip")

    def BoxPlot(self, name):
        if 'str' in str(type(name)):
            df = pd.Series(self.df[name].values)  # self.df[name].values
            plt.figure()
            df.plot.box()
            plt.title(name)

        elif 'list' in str(type(name)):
            __couunt = len(name)
            dd = self.df[name]
            dd.plot.box(vert=False)
        else:
            return

    def DeltaSlipp(self, nsd=1):
        if not("Slip" in self.df.columns):
                self.Slippage()
        x0 = self.Get("Slip")
        _coun = x0.shape
        x1 = np.insert(x0, 0,np.zeros(nsd))[:_coun[0]]
        x2=x0-x1
        basa = x2[30]
        x2[:30]=basa
        self.AddColumn(x2, "dSlip")

    def __testStrList(self, name):
     if 'str' in str(type(name)):
         return True
     else:
        return False

    def ClearBasa(self, nameBasas):
        if self.__testStrList(nameBasas):
            # str
            pass
        else:
            # list
            pass
