#pragma once
#include <iostream>
#include <string>
#include <map>
#include <memory>

#include "Walsh.h"

#ifndef SLIPPAGE_H_
#define SLIPPAGE_H_

class Slippage
{
public:


		Slippage();
		~Slippage();
		int get_dan();
    //void DanCan

private:
		std::map<std::string, std::shared_ptr<Walsh>> mCalc;
		std::map<std::string, std::shared_ptr<Walsh>> ::iterator itrmCalc;
};
#endif /* SLIPPAGE_H_ */
