from .SettingsAtStartup import *

class ClassFun:
    def __init__(self):
        pass

        self.works = { WorkingWay.Work: "E:\Motorcycle\Data\Py\\Basa",
                        WorkingWay.Work64: "E:\Motorcycle\Data\Py\\64",
                        WorkingWay.Work128: "E:\Motorcycle\Data\Py\\128",
                        WorkingWay.Home: "E:\!!!!ateStability\Log\DanPy"
                      }

    def GetWorks(self, _works:WorkingWay):
        return self.works[_works]

    def TestStrList(self, name):
        if 'str' in str(type(name)):
            return True
        else:
            return False

    def TestStrDict(self, name):
        if 'str' in str(type(name)):
            return True
        else:
            return False
