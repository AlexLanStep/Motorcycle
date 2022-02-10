#include "Walsh.h"

Walsh::Walsh()
{
    _ind = 0;
    for (int i = 0; i < NPOINT; i++)    // �������� ����� ��� ����� ������ ������� ������
        _m[i] = 0.0;
}

double Walsh::calc(double d)
{
    double _w[NPOINT];                          // ������ � �����������
    for (int i = 0; i < NPOINT; i++)
        _w[i] = 0.0;

    for (int i = NPOINT - 2; i >= 0; i--)       // ��������� ������ � ������ �������
        _m[i+1] = _m[i];                      // �������� ������ �� ���� ������

    _m[0] = d;

    for (int i = 0; i < NPOINT; i++)            // ������� ����. �������� � �������
        for (int j = 0; j < NPOINT; j++)        //   i - �������, j-������
        {
            int _k = _kf[j][i];                 // ���� _k==0 ����������
            if(_k ==0)                          //  ����� ������������ 
                continue;                       //  ����� ��������� ����������
            
            _w[i] += _k > 0 ? _m[j] : - _m[j];  // �������� ������ ��� ��������
        }

    double _sum = 0.0;

    for (int i = 1; i < NPOINT; i++)            // ������� ���������: ������������ � ������ ����� � ���� 
        _w[i] = _w[i] * _w[i];

    int i = 1;
    while (i < NPOINT - 2)
    {
        _sum += std::sqrt(_w[i] + _w[i + 1]);
        i = i + 2;
    }

    return _sum;                                // �������
}
