#include "Slippage.h"

Slippage::Slippage()
{

    //Walsh _walsh = Walsh();
    mCalc.insert(std::pair<std::string, std::shared_ptr<Walsh>>("yacc", std::make_shared<Walsh>()));
    mCalc.insert(std::pair<std::string, std::unique_ptr<Walsh>>("xacc", std::make_unique<Walsh>()));
    mCalc.insert(std::pair<std::string, std::unique_ptr<Walsh>>("zacc", std::make_unique<Walsh>()));

//    itrmCalc
    for (itrmCalc = mCalc.begin(); itrmCalc != mCalc.end(); ++itrmCalc)
    {
        std::cout << '\t' << itrmCalc->first << '\t' << itrmCalc->second->calc(1.1) << '\n';
    }


}

Slippage::~Slippage()
{
}

int Slippage::get_dan()
{
		return 0;
}


/*
 
  for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;

*/
