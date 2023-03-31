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
		
		// расчет 
		// std::map<std::string, double> *d - передается адрес словаря с данными
		// double rotv											- момент
		//  Значения calc - Новое значения момента
		double calc(std::map<std::string, float> *d, float rotv);			

private:
		std::map<std::string, std::shared_ptr<Walsh>> mCalc;								// словарь с функциями Уолша
		std::map<std::string, std::shared_ptr<Walsh>> ::iterator itrmCalc;	// итератор словаря Уолша
		std::map<std::string, float> _k_norm;															// словарь с нормировкой
		std::map<std::string, float>  ::iterator itrm_k_norm;							// итератор нормировки
		//  первая EMA 0 - первая медлення
		float _ema_old;				//  EMA0(t-1)
		float _alfa;						//  коэф. текущего расчета
		float _alfa_1;					//  коэф. к EMA0(t-1) расчета
		float _nperiod;				//  шаг сглаживания заложил 10 - 100 мил. секунд

		//  первая EMA 1 - вторя более быстрая
		float _ema_old_2;			//  EMA1(t-1)
		float _alfa_2;					//  коэф. текущего расчета
		float _alfa_1_2;				//  коэф. к EMA1(t-1) расчета
		float _nperiod_2;			//  шаг сглаживания заложил 5 - 50 мил. секунд

};
#endif /* SLIPPAGE_H_ */
