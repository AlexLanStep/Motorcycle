import glob, os
import pprint

from enum import Enum


class WorkingWay(Enum):
    Home = 1
    Work = 2
    Work64 = 3
    Work128 = 4


class SetParamsStart:
    def __init__(self, path):   # self.__path_work_dab = paths[typeWork]
        self.__path_work_dab = path

    def Run(self):  #        print(self.__path_work_dab)
        os.chdir(self.__path_work_dab)
        z = glob.glob('*.ftr')
        z = {i:z[i] for i in range(len(z))}
        return (z, self.__path_work_dab)


        # match self.typeWork:
        #     case WorkingWay.Work:
        #         print(self.typeWork)
        #         self.__path_work_dab = "E:\ExchangeRateStability\Log"
