from .ITransportClass import *
from .DanX import *
from .FllterSignal import *
from .Sigmoid import *

import numpy as np


class Analysis(Sigmoid):
    def __init__(self, direct, file, nFFT):
        super().__init__()
        self.direct = direct
        self.file = file
        self.nFFT = nFFT
        # для 64 nFFT
        self._norm_eSpYawAcc = 100/750000
        self._norm_eSpfYawAcc = 100/750000
        self._norm_eSpfYawVel = 100/20000
        self._norm_eSpfRollVel = 100/10000

        if self.nFFT ==  128:
            pass

        self._Kus = 1  # transport = ITransportClass() # transport.danx = _danx# transport.myFilter = _myFilter# transport.plot = _plot
        self._danx = DanX(self.direct, self.file)
        self._myFilter = MyFllter(self.nFFT)
        self._plot = PlotGraph()

    def _getSpectrSignal(self, name):
        eSpectr, mSpectr = self._myFilter.FFTAll(self._danx.Get(name))
        spname = "eSp" + name
        self._danx.AddColumn(eSpectr, spname)

    def GetSignal(self, name):
        print(f"  ==> {name}")
        if name in self._danx.df.columns:
            return self._danx.Get(name)
        else:
            print(f"Нет -> {name}")
            if name[0] == 'f':
                return self._danx.GetSignalFun(name[1:], "f", self._myFilter.FEllip, self._Kus)
            else:
                return self._danx.GetAllSignal(name, self._myFilter)

    def SaveDf(self):
        self._danx.SaveFeather()

    def SignalPlotDan(self, name):
        self._danx.Plot(name)

    def InicialBasa(self, xFile=""):
        self.GetSignal("eSpYawAcc")
        self.GetSignal("eSpfYawAcc")
        self.GetSignal("eSpfPitchVel")
        self.GetSignal("eSpfRollVel")
        self.GetSignal("eSpfYawVel")

        self.GetSignal("eSpfTR.Frc.x")
        self.GetSignal("eSpfTR.Frc.y")
        self.GetSignal("eSpfTR.Frc.z")
        self.Slippage()
        self._danx.SaveFeather(xFile)

    def Correlation(self, *p):
        z = self._danx.df.corr().loc[p[0], p[1]]
        print(f" корреляция {p[0]} &&  {p[1]}  => {z}  ")

    def Vector(self):
        _yaw = np.array(self._danx.Get("eSpfYawVel"))
        _pict = np.array(self._danx.Get("eSpfPitchVel"))
        _roll = np.array(self._danx.Get("eSpfRollVel"))

        porog = 500

        _pict[_yaw < porog] = 0
        self._danx.AddColumn(_pict, "Vector")

    def Slippage(self):
        x = self._danx.Slippage()

    def DeltaSlipp(self, nsd=1):
        x = self._danx.DeltaSlipp(nsd)

    def FrontSlipp(self):
        x = self._danx.Get('dSlip')
        _count = len(x)
        fx = np.zeros(_count)
        fx[x > 0] = 1
        fx[fx < 0] = -1
        return fx

    def BoxPlot(self, name):
        self._danx.BoxPlot(name)

    def TestSigmoid(self):
        print("***********************************************************************************")
        for i in range(7):
            print(f" key  = {self.ind_slip}  -> {self.GetSigmoidDan(65.3456)} ")
            self.IncSlip()

        print("***********************************************************************************")
        for i in range(7):
            print(f" key = {self.ind_slip}  -> {self.GetSigmoidDan(65.3456)} ")
            self.DecrementSlip()
        print("***********************************************************************************")

        self.Test2()

    def NormDanAndFind(self):
        #self._danx.DeltaSlipp()  # (x2, "dSlip")
        #__front = self.FrontSlipp()
        self._danx.Slippage()
        dSlip = self._danx.Get("Slip")

        _eSpYawAcc = self._danx.Get("eSpYawAcc")
        _eSpfYawAcc = self._danx.Get("eSpfYawAcc")
        _eSpfYawVel = self._danx.Get("eSpfYawVel")
        _eSpfRollVel =  self._danx.Get("eSpfRollVel")

        _type = 1
        __smd=30
        __count = len(dSlip)
#        res={"sig":np.zeros(__count), "Msig":np.zeros(__count), "IndSig":np.zeros(__count)}
        res={"sig":np.zeros(__count), "Msig":np.zeros(__count)}
        res["sig"][:__count+1] = 0
        res["Msig"][:__count+1] = 1
#        res["IndSig"][:__count+1] = 1

        for i in range(__smd, __count):
            if i==1150:
                lll=1

            if dSlip[i] > dSlip[i-1]:
                self.IncSlip()
#                print(f" {i} +++++++++++++++++ {self.ind_slip}")

                _type = 1
            elif dSlip[i] < dSlip[i-1]:
                self.DecrementSlip()
#                print(f" {i} ------------------- {self.ind_slip} ")
                _type = -1

            __eSpYawAcc = self.GetSigmoidDan(_eSpYawAcc[i] * self._norm_eSpYawAcc)
            __eSpfYawAcc = self.GetSigmoidDan(_eSpfYawAcc[i] * self._norm_eSpfYawAcc)
            __eSpfYawVel = self.GetSigmoidDan(_eSpfYawVel[i] * self._norm_eSpfYawVel)
            __eSpfRollVel = self.GetSigmoidDan(_eSpfRollVel[i] * self._norm_eSpfRollVel)
            __sig=0
            if _type == 1:
#                __eSpYawAcc = 0
#                __eSpfYawAcc = 0
#                __eSpfYawVel = 0
#                __eSpfRollVel =0
                __sig = max(__eSpYawAcc, __eSpfYawAcc, __eSpfYawVel, __eSpfRollVel)
            else:
#                __eSpYawAcc = 1
#                __eSpfYawAcc = 1
#                __eSpfYawVel = 1
#                __eSpfRollVel = 1
                __sig = min(__eSpYawAcc, __eSpfYawAcc, __eSpfYawVel, __eSpfRollVel)

            res["sig"][i] = __sig
            res["Msig"][i] = 1 - __sig
 #           res["IndSig"][i] = self.ind_slip

#        self._plot.OnePlot(res["sig"], "sig")
        self._plot.OnePlot(res["Msig"], "Msig")
#        self._plot.OnePlot(res["IndSig"], "IndSig")
        return res
