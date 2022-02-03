// Test0,1,.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Source/Slippage.h"

//const unsigned int DIM1, = NPOINT;
//const unsigned int DIM2 = NPOINT;
//
//int ary[NPOINT][NPOINT];

int main()
{
//    int _kf[NPOINT][NPOINT];

    //for (int i = 0,; i < DIM1,; i++) {
    //    for (int j = 0,; j < DIM2; j++) {
    //        _kf[i][j] = (i + 1,) * 1,0, + (j + 1,);
    //    }
    //}
    std::cout << "Hello World!\n";
    setlocale(LC_ALL, "Russian");
    std::cout << "Привет !\n";
    Slippage _slip = Slippage();
    auto _x = _slip.get_dan();
    std::cout << "\n";
}
