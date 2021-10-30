class ConvertPy:
    def __init__(self, *pathPy):
        self._pathBasa = pathPy[0]
        self._dan_py = pathPy[1]

    def Run(self, file):
        self._file_name = file
        _path_file_sourse = self._pathBasa + "\\" + self._file_name + ".csv"
        f = open(_path_file_sourse, 'r')
        l = [line for line in f]
        _n0 = str(l[0]).index('"')
        _s0 = str(l[0])[_n0:]
        _s0 = _s0.replace('"', "")
        _s0 = _s0.replace('MC.Con.v', "Speed")
        _s0 = _s0.replace("MC.", "") \
            .replace(".a_0", "") \
            .replace("PT.", "")
        l[0] = _s0
        del l[1]
        del l[1]
        __file_save_csv = self._dan_py + "\\" + self._file_name + ".csv"
        print(f"  \DanPy\{__file_save_csv} ")
        with open(__file_save_csv, "w") as outfile:
            outfile.write("".join(l))

        print(f" для pandas  \DanPy\{self._file_name + '.ftr'} ")
        import pandas as pd
        df = pd.read_csv(__file_save_csv, sep=';')
        df.to_feather(self._dan_py + "\\" + self._file_name + ".ftr")

        import os
        os.remove(__file_save_csv)
        print(f" удалили  \DanPy\{__file_save_csv} ")
