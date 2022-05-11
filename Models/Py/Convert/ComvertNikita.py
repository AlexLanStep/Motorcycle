import numpy as np
import pandas as pd
import scipy.io as sio
import os
import shutil

import sys
import matplotlib

#configurations.yaml

# pip install pyinstaller -F ComvertNikita.py

if __name__ == '__main__':
    # <----- !!!!!!!!!!  ЭТО  ЗНАК  КОМЕНТА !!!!!!!!!!

    # имя файла с расширением csv - исходники
    name_file_csv = "NAMILog1_test"

    # имя файла для MatLab  потом сформирует файл с расширением mat
    name_file_matlab = "NAMILog1_test_CONVERT___01"

    # название переменной в MatLAb
    name_matlab = "nikita_xxx"

    # путь к папке для файлов с исходниками csv
    path_sourse_csv = r"\\10.102.1.88\data\02_Users_Folders\Mizin\4_IPG\1_MotorcycleMaker\2_LOGS\1_LOGS_RAW"

    # путь к папке для с конвертированных файлов с расширением mat
    path_matlab = r"\\10.102.1.88\data\02_Users_Folders\Mizin\4_IPG\1_MotorcycleMaker\2_LOGS\2_LOGS_MATLAB"

    if os.path.exists(path_sourse_csv):
        print(path_sourse_csv)
    else:
        print(" !!!!!  ERROR  direct sourse !!! ")
        exit(-1)

    if os.path.exists(path_matlab):
        print(path_matlab)
    else:
        print(" !!!!!  ERROR  direct CONVERT !!! ")
        exit(-1)

    path_csv = path_sourse_csv+r'/'+ name_file_csv + ".csv"
    if os.path.exists(path_csv):
        print(path_csv)
    else:
        print(" !!!!!  ERROR  file sourse !!! ")
        exit(-1)

    _loc_mat = name_file_matlab + ".mat"
    path_matlab = path_matlab +'\\'+  name_file_matlab + ".mat"
    df = pd.read_csv(path_csv, delimiter=",", skiprows=[1, 2])
    cols = list(df.columns)
    df.drop(columns = [cols[-1]],axis = 1, inplace=True)
    cols1 = cols[1:len(cols)]

    d = {}
    for i in range(len(cols1)-1, -1, -1):
        print(f"{cols[i]} -->  {cols1[i]}")
        d[cols[i]]= cols1[i]
    df.rename(columns = d, inplace = True)

    print(df.head(10))
    ls = df.columns
    dx = {}
    _dd = df.to_dict()
    for it in ls:
        x = _dd[it]  # np.array()
        _x = [val for key, val in x.items()]
        it1 = it.replace('.', '_')
        print(it1)
        dx[it1] = np.array(_x)

    sio.savemat(f"{path_matlab}", {name_matlab: dx})
    #shutil.move(path_matlab, "E:\\"+_loc_mat)
    # shutil.move(_loc_mat, path_matlab)

    print("==-- END !!! --== ")
