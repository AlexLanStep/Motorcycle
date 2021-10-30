import os

import scipy.io as sio
import numpy as np


class Matrix:
    def __init__(self, workDir):
        self._workdir = workDir
        os.chdir(self._workdir)
        self._workdir_matlab = self._workdir + "\\MatLab"

        print("  --- class MyMatrix --")
        self.Shapka = {"MC.Con.v":-1,
                       "MC.Fr1.a_0.x":-1, "MC.Fr1.a_0.y":-1, "MC.Fr1.a_0.z":-1,
                       "MC.PitchVel":-1, "MC.RollVel":-1,
                       "MC.TF.muRoad":-1, "MC.TR.muRoad":-1,
                       "MC.TF.vBelt":-1, "MC.TR.vBelt":-1,
                       "MC.YawAcc":-1, "MC.YawVel":-1,
                       "PT.Engine.Trq":-1, "PT.Engine.rotv":-1,
                       "Time":-1,
                       "MC.TR.Frc.x":-1, "MC.TR.Frc.y":-1, "MC.TR.Frc.z":-1
                       }
#        self._readFile()

    def ReadFile(self, namefile ):
        os.chdir(self._workdir)

        self.__namefile = namefile
        self._save_files = self._workdir_matlab+"\\"+ self.__namefile
        self.__xnum = {}
        self.__indexEnd = 0
        self.danx = {}

        _path = self.__namefile+".csv"
        print(_path)
        f = open(_path, 'r')
        l = [line.replace('"',"").replace('\n',"").split(";") for line in f]
        del l[1]

        shapka = l[0:2]
        del shapka[0][0]
        del shapka[1][0]
        l1=shapka[0]
        for i in range(len(l1)):
            __s = l1[i]
            print(f"№ {i}  {__s} ")
            if __s in self.Shapka:
                self.Shapka[__s]=i

        self.__xnum = np.asarray(l[2:]).astype(np.float64)

        _speed = self.__xnum[:,0]
        self.__indexEnd = int(np.min(np.where(_speed == 0.)))+2

    def get(self, i):
        return self.__xnum[0:self.__indexEnd, i]

    def save(self, name, danx):
        sio.savemat(self.__namefile+".mat", {name:danx})

    def form_dan(self):
        if (self.Shapka["MC.Fr1.a_0.x"] >-1) \
                & (self.Shapka["MC.Fr1.a_0.y"] >-1) \
                & (self.Shapka["MC.Fr1.a_0.z"]>-1):
                XYZ = {'X': self.get(self.Shapka["MC.Fr1.a_0.x"]),
                       'Y': self.get(self.Shapka["MC.Fr1.a_0.y"]),
                       'Z': self.get(self.Shapka["MC.Fr1.a_0.z"]) }
#                self.danx={'XYZ': XYZ}
                self.danx['XYZ']= XYZ

        if (self.Shapka["MC.PitchVel"]>-1) \
                & (self.Shapka["MC.RollVel"]>-1) \
                & (self.Shapka["MC.YawAcc"]>-1)\
                & (self.Shapka["MC.YawVel"]>-1):
                XYZg = {'PitchVel': self.get(self.Shapka["MC.PitchVel"]),
                       'RollVel': self.get(self.Shapka["MC.RollVel"]),
                       'YawAcc': self.get(self.Shapka["MC.YawAcc"]),
                       'YawVel': self.get(self.Shapka["MC.YawVel"])
                        }
                self.danx['XYZg']= XYZg

        if (self.Shapka["MC.TF.muRoad"]>-1) \
                & (self.Shapka["MC.TR.muRoad"]>-1):
                muRoad = {'F': self.get(self.Shapka["MC.TF.muRoad"]),
                       'R': self.get(self.Shapka["MC.TR.muRoad"]) }
                self.danx['muRoad']=muRoad

        if (self.Shapka["MC.TF.vBelt"]>-1) \
                & (self.Shapka["MC.TR.vBelt"]>-1):
                vBelt = {'F': self.get(self.Shapka["MC.TF.vBelt"]),
                       'R': self.get(self.Shapka["MC.TR.vBelt"]) }
                self.danx['vBelt']=vBelt

        if (self.Shapka["MC.TF.vBelt"]>-1) \
                & (self.Shapka["MC.TR.vBelt"]>-1):
                vBelt = {'F': self.get(self.Shapka["MC.TF.vBelt"]),
                       'R': self.get(self.Shapka["MC.TR.vBelt"]) }
                self.danx['vBelt']=vBelt

                self.danx['XYZ']= XYZ
                self.danx['XYZg']= XYZg
                self.danx['muRoad']=muRoad
                self.danx['vBelt']=vBelt
                self.danx['vBelt']=vBelt

        if (self.Shapka["PT.Engine.Trq"]>-1) \
                & (self.Shapka["PT.Engine.rotv"]>-1):
                Engine = {'Trq': self.get(self.Shapka["PT.Engine.Trq"]),
                       'Rotv': self.get(self.Shapka["PT.Engine.rotv"]) }
                self.danx['Engine']=Engine

        if (self.Shapka["MC.Con.v"]>-1):
                speed = self.get(self.Shapka["MC.Con.v"])
                self.danx['speed']= speed

        if (self.Shapka["Time"]>-1):
                time = self.get(self.Shapka["Time"])
                self.danx['Time']= time

        if (self.Shapka["MC.TR.Frc.x"] >-1) \
                & (self.Shapka["MC.TR.Frc.y"] >-1) \
                & (self.Shapka["MC.TR.Frc.z"]>-1):
                Frc = {'X': self.get(self.Shapka["MC.TR.Frc.x"]),
                       'Y': self.get(self.Shapka["MC.TR.Frc.y"]),
                       'Z': self.get(self.Shapka["MC.TR.Frc.z"]) }
                self.danx['Frc']= Frc

        os.chdir(self._workdir_matlab)

        self.save(self.__namefile,  self.danx)
        kkk=1
