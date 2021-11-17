import pprint

from Convert.ConverBasa import *
from Core.SettingsAtStartup import *
from Core.DanX import *
from Core.FllterSignal import *
from Core.PlotGraphs import *
from Core.ITransportClass import *
from Core.Analysis import *
from Core.ServisDf import *
import numpy as np

from Core.Sigmoid import *

def start_programm():
    print("***  Start programm  модель поиска заноса  *** ")


def _convertDan(path):
    _conveet = ConverBasa(path)
    _conveet.Run()
    exit(0)

def Show():
    plt.show()


if __name__ == '__main__':
# конвертация данных в matlab & pandas
#    _convertDan("E:\ExchangeRateStability\Log")

    _server = ServisDf()
#    _server.MaxField(_server.GetWorks(WorkingWay.Work64), ["eSpYawAcc", "eSpfYawAcc", "eSpfYawVel", "eSpfRollVel"])

    _set64 = SetParamsStart(_server.GetWorks(WorkingWay.Work64))
    (_files64, _path64) = _set64.Run()
    pp = pprint.PrettyPrinter(indent=4)
    pp.pprint(_files64)

#    _set128 = SetParamsStart(_server.GetWorks(WorkingWay.Work128))
#    (_files128, _path128) = _set128.Run()
#    pp = pprint.PrettyPrinter(indent=4)
#    pp.pprint(_files128)

    _NumFiles = 4

    _analys64 = Analysis(_server.GetWorks(WorkingWay.Work64), _files64[_NumFiles], 64)
    _analys64.SignalPlotDan(["eSpYawAcc","eSpfYawAcc", "eSpfYawVel", "eSpfRollVel", "Slip"])
    rez =  _analys64.NormDanAndFind()
#    _analys128 = Analysis(_server.GetWorks(WorkingWay.Work128), _files128[_NumFiles], 128)
#    _analys128.SignalPlotDan(["eSpYawAcc","eSpfYawAcc", "eSpfYawVel", "eSpfRollVel", "Slip"])

    _analys64.TestSigmoid()  #

    Show()

    kk = 1

'''

    _works = {
        WorkingWay.Work: "E:\ExchangeRateStability\Log\DanPy",
        WorkingWay.Work64: "E:\ExchangeRateStability\Log\DanPy\\64",
        WorkingWay.Work128: "E:\ExchangeRateStability\Log\DanPy\\128",
              WorkingWay.Home: "E:\!!!!ateStability\Log\DanPy"
    }



def IniciallDan(_files):
    for i in range(len(_files)):
        print(f" =============>  {_files[i]}   <=====================")
        _danx = DanX(_works[WorkingWay.Work], _files[i])  #6   # 3
        transport = ITransportClass()
        transport.danx = _danx
        transport.myFilter = _myFilter
        transport.plot = _plot

        _analysis = Analysis(transport)
        _analysis.InicialBasa()
        exit(-2)
        

#    _server.ClearDan(_works[WorkingWay.Work], _files )
#    _server.FormDan(_works[WorkingWay.Work], _files, 128)
        
#    _danx = DanX(_works[WorkingWay.Work], _files[_NumFiles])    #6   # 3
#    _danx.DeleteBasa()

#    _analysis.InicialBasa()

    #_analysis.SignalPlotDan(["YawAcc", "fYawAcc", "eSpfYawAcc"])
    #_analysis.SignalPlotDan(["YawVel","fYawVel", "eSpfYawVel"])
#    _analysis.Slippage()
    _analysis.Vector()
    _analysis.DeltaSlipp(3)
#    _analysis.SignalPlotDan(["Vector", "Slip", "dSlip", "Speed", 'Engine.Trq', "eSpfPitchVel"])

#    dSplipp = _analysis.FrontSlipp()
#    _plot.OnePlot(dSplipp, "Front slipp")

#    _danx.BoxPlot(["eSpfYawAcc", "eSpfYawVel", "eSpfRollVel", "eSpfPitchVel", "Vector"])
#    _danx.BoxPlot(["fYawAcc", "fYawVel", "fRollVel", "fPitchVel"])
#    _danx.BoxPlot(["YawAcc", "YawVel", "RollVel", "PitchVel"])

    # _analysis.SignalPlotDan(["TR.Frc.y", "fTR.Frc.y", "eSpfTR.Frc.y"])
    # _analysis.SignalPlotDan(["eSpfTR.Frc.y", "eSpfTR.Frc.x", "eSpfTR.Frc.z"])
#    _analysis.SignalPlotDan(["eSpfYawVel", "eSpfRollVel", "eSpfPitchVel"])

    #_analysis.Correlation("eSpfYawAcc", "eSpfYawVel")
    #_analysis.Correlation("eSpfYawAcc", "eSpfRollVel")
    #_analysis.Correlation("eSpfYawAcc", "eSpfPitchVel")

#    _analysis.SignalPlotDan(["eSpfYawVel", "Vector"])

'''
