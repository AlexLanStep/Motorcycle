#include "Walsh.h"

Walsh::Walsh()
{
    _ind = 0;
    for (int i = 0; i < NPOINT; i++)    // обнуляем масси где будем копить входные данные
        _m[i] = 0.0;
}

double Walsh::calc(double d)
{
    double _w[NPOINT];                          // массив с гармониками
    for (int i = 0; i < NPOINT; i++)
        _w[i] = 0.0;

    for (int i = NPOINT - 2; i >= 0; i--)       // сохраняем данные в начеле массива
        _m[i] = _m[i + 1];                      // сдвигаем данные на один индекс
    _m[0] = d;

    for (int i = 0; i < NPOINT; i++)            // перебор коэф. значения в матрице
        for (int j = 0; j < NPOINT; j++)        //   i - столбец, j-строки
        {
            int _k = _kf[j][i];                 // если _k==0 пропускаем
            if(_k ==0)                          //  можно регулировать 
                continue;                       //  какие гармоники пропускаем
            
            _w[i] += _k > 0 ? _m[j] : - _m[j];  // собираем данные для гармоник
        }

    double _sum = 0.0;
    for (int i = 0; i < NPOINT; i++)            // считаем "квази энергию спектра"
        _sum += std::abs(_w[i]);

    return _sum;                                // энергия
}
