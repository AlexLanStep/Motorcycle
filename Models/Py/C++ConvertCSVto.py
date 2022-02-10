import csv
import matplotlib.pyplot as plt


if __name__ == '__main__':
    print("convert to C++")
    _path_sourse = "E:\\Motorcycle\\Data\\Basa\\T4_2021-10-08_10-36.csv"
    _path_sourse_to = "E:\\Motorcycle\\Data\\Basa\\T4_2021-10-08_10-36_c++.csv"

    i=-1
    ls=[]
    with open(_path_sourse, newline='') as File:
        reader = csv.reader(File, delimiter=";")
        for row in reader:
            i=i+1
            if i==0:
                s0 = '; '.join(row)
                ls+=[s0]
                continue
            s = f"{float(row[0]):.8f}; "
            s = s + f"{float(row[1]):.8f}; "
            s = s + f"{float(row[2]):.8f}; "
            s = s + f"{float(row[3]):.8f}; "
            s = s + f"{float(row[4]):.8f}; "
            s = s + f"{float(row[5]):.8f}; "
            s = s + f"{float(row[6]):.8f}; "
            s = s + f"{float(row[7]):.8f}; "
            s = s + f"{float(row[8]):.8f}; "
            s = s + f"{float(row[9]):.8f}; "
            s = s + f"{float(row[10]):.8f}; "
            s = s + f"{float(row[11]):.8f}; "
            s = s + f"{float(row[12]):.8f}; "
            s = s + f"{float(row[13]):.8f}; "
            s = s + f"{float(row[14]):.8f}; "
            s = s + f"{float(row[15]):.8f}; "
            s = s + f"{float(row[16]):.8f}; "
            s = s + f"{float(row[17]):.8f}"
            s = s.replace('.',",")
            print(f"{i} --> {s}")
            ls+=[s]

            # a+=[float(row[0].replace(',',"."))]
            # b+=[float(row[1].replace(',',"."))]
#            print(f"{i}   {row}")
            kk=1

#    with open(_path_sourse_to, "w") as file:
#        print(ls, file=file)

    with open(_path_sourse_to, "w") as file:
        for it in ls:
            file.write(it)
            file.write("\n")

