#pragma once
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <vector>

#include "Walsh.h"

#ifndef SLIPPAGE_H_
#define SLIPPAGE_H_

class Slippage
{
public:
		Slippage(std::map<std::string, float> k_norm);
		~Slippage();
		
		// ������ 
		// std::map<std::string, double> *d - ���������� ����� ������� � �������
		// double rotv											- ������
		//  �������� calc - ����� �������� �������
		double calc(std::map<std::string, float> *d, float rotv);			

private:
		std::map<std::string, std::shared_ptr<Walsh>> mCalc;								// ������� � ��������� �����
		std::map<std::string, std::shared_ptr<Walsh>> ::iterator itrmCalc;	// �������� ������� �����
		std::map<std::string, float> _k_norm;															// ������� � �����������
		std::map<std::string, float>  ::iterator itrm_k_norm;							// �������� ����������
		//  ������ EMA 0 - ������ ��������
		float _ema_old;				//  EMA0(t-1)
		float _alfa;						//  ����. �������� �������
		float _alfa_1;					//  ����. � EMA0(t-1) �������
		float _nperiod;				//  ��� ����������� ������� 10 - 100 ���. ������

		//  ������ EMA 1 - ����� ����� �������
		float _ema_old_2;			//  EMA1(t-1)
		float _alfa_2;					//  ����. �������� �������
		float _alfa_1_2;				//  ����. � EMA1(t-1) �������
		float _nperiod_2;			//  ��� ����������� ������� 5 - 50 ���. ������

};
#endif /* SLIPPAGE_H_ */
