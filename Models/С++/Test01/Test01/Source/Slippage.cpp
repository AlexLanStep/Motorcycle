#include "Slippage.h"

Slippage::Slippage(std::map<std::string, double> k_norm)
{
    _k_norm = k_norm;               // ������� � ����������� �������

    _ema_old = 0.0;                 // ���������� ��������  EMA0
    _nperiod = 10.0;                // ������ ����������� 
    _alfa = 2.0/(_nperiod+1.0);     // ���� ��� EMA0
    _alfa_1 = 1.0 - _alfa;          // ���� ��� EMA0

    _ema_old_2 = 0.0;               // ���������� �������� EMA1
    _nperiod_2 = 5.0;               // ������ ����������� 
    _alfa_2 = 2.0/(_nperiod_2+1.0); // ���� ��� EMA1
    _alfa_1_2 = 1.0 - _alfa_2;      // ���� ��� EMA1

    // ������������� ������� � �������� �������
    for (itrm_k_norm = _k_norm.begin(); itrm_k_norm != _k_norm.end(); ++itrm_k_norm)
        mCalc.insert(std::pair<std::string, std::unique_ptr<Walsh>>(itrm_k_norm->first, std::make_unique<Walsh>()));
}

Slippage::~Slippage()
{
}

double Slippage::calc(std::map<std::string, double>* d, double rotv)
{
    double _max_d = 0.0;    //
    // ������ ������� ������� �� ������� �������, �����������, �������� ���������� �������� ������� �� ���� ��������
    for (itrmCalc = mCalc.begin(); itrmCalc != mCalc.end(); ++itrmCalc)
        _max_d = std::max(_max_d, itrmCalc->second->calc(d->at(itrmCalc->first)) / _k_norm[itrmCalc->first]);
    
    // _max_d - ������������ 1.0 � �����������
    _max_d =1.0- std::min(_max_d, 1.0);

    //    EMA = ((CLOSE(i) - (CLOSE(i - 1)) * P + EMA[i - 1];
    // EMA0 - ������ 1 �������
    _ema_old = _alfa * _max_d + _alfa_1 * _ema_old;
    // EMA1 - �������� ������ 2-�� �������
    _ema_old_2 = _alfa_2 * _ema_old + _alfa_1_2 * _ema_old_2;
    return _ema_old_2 *rotv;

}

