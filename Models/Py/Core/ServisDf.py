
from .DanX import *
from .ClassFun import *
from .ITransportClass import *
from Core.FllterSignal import *
from Core.PlotGraphs import *
from Core.Analysis import *



class ServisDf(ClassFun):
    def __init__(self):
        super().__init__()

    def ClearDan(self, path, name):
        print(f" очистка базы d каталоге {path} ")
        if self.TestStrDict(name):
            name = {0: name}

        for key,value in name.items():
            print(f"  {value}")
            _danx = DanX(path, value)
            _danx.DeleteBasa()

        exit(-1)

    def FormDan(self, pathOriginal, name, nFFT):
        pathRec = pathOriginal + "\\" + str(nFFT)
        print(f" каталог c исходными данными {pathOriginal} ")
        print(f" каталог для записи данных {pathRec} ")
        if self.TestStrDict(name):
            name = {0: name}

        for key,value in name.items():
            print(f"  {value}")
            _danx = DanX(pathOriginal, value)
            transport = ITransportClass()
            transport.danx = _danx
            transport.myFilter = MyFllter(nFFT)
#            transport.plot = _plot
            _analysis = Analysis(transport)
            _analysis.InicialBasa(pathRec+"\\"+value)
            exit(-2)


    def MaxField(self, pathOriginal, field):
#        for child in [pathlib.PurePosixPath(x).stem for x in os.listdir(pathOriginal) if '.ftr' in str(x).lower()]:
        if self.TestStrList(field):
            field=list([field])

        for child in [pathlib.PurePosixPath(x).name for x in os.listdir(pathOriginal) if '.ftr' in str(x).lower()]:
            _danx = DanX(pathOriginal, child)
            print(child)

            for item in field:
#            s = _danx.df[item].max()

                print(f"   {item}  = {_danx.df[item].max()}")
            kk=1
