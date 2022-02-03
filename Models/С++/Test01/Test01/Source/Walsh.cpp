#include "Walsh.h"

Walsh::Walsh()
{
    _ind = 0;
    for (int i = 0; i < NPOINT; i++)
        _m[i] = 0.0;
}

double Walsh::calc(double d)
{
    double _w[NPOINT];
    for (int i = 0; i < NPOINT; i++)
        _w[i] = 0.0;

    for (int i = NPOINT - 2; i >= 0; i--) 
        _m[i] = _m[i + 1];
    _m[0] = d;

    for (int i = 0; i < NPOINT; i++)
        for (int j = 0; j < NPOINT; j++)
        {
            int _k = _kf[j][i];
            if(_k ==0)
                continue;
            
            _w[i] += _k > 0 ? _m[j] : - _m[j];
        }

    double _sum = 0.0;
    for (int i = 0; i < NPOINT; i++)
        _sum += std::abs(_w[i]);

    return _sum;
}
