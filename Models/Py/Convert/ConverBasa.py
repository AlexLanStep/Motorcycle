import pathlib
from .MyMatrix import *
from .ConvertPy import *
import os


class ConverBasa:
    def __init__(self, pathCsv):
        self._pathBasa = pathCsv
        print(f"  dir convert -> {self._pathBasa} ")
        self._path_py = self._pathBasa + "\\DanPy"
        self._mat = Matrix(self._pathBasa)
        self._convertPy = ConvertPy(self._pathBasa, self._path_py)

    def Run(self):
        for child in [pathlib.PurePosixPath(x).stem for x in os.listdir(self._pathBasa) if '.csv' in str(x).lower()]:
            print(child)
            # self._mat.ReadFile(child)
            # self._mat.form_dan()
            self._convertPy.Run(child)
            os.remove(self._pathBasa + "\\" + child + ".csv")
