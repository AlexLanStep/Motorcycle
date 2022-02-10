#include "ConvertToSlipp.h"


namespace my_read_write
{
		VecDouble ConvertToSlipp::getVector(string s_read_path, char delimiter)
		{
				VecDouble _vecDouble = make_shared<vector<tuple<double, double, double, double, double,
																												double, double, double, double, double,
																												double, double, double, double, double, 
																												double, double>>>();
				//	vector<vector<double>> ::iterator itrmVecDouble;

				VecStrStr _dan = ReadDan(s_read_path, ';');
				//for (itrmCalc = mCalc.begin(); itrmCalc != mCalc.end(); ++itrmCalc)
				for (auto iter = _dan->begin(); iter != _dan->end(); ++iter)
				{
						auto _zm = iter;
						double d0 = stod(iter->at(0));			//0 - Speed;
						double d1 = stod(iter->at(1));			//1 - Fr1.x; 
						double d2 = stod(iter->at(2));			//2 - Fr1.y;
						double d3 = stod(iter->at(3));			//3 - Fr1.z;
						double d4 = stod(iter->at(4));			//4 - PitchVel;
						double d5 = stod(iter->at(5));			//5 - RollVel;
						double d6 = stod(iter->at(6));			//TF.muRoad
						double d7 = stod(iter->at(7));			//7 - TF.vBelt;
						double d8 = stod(iter->at(8));			//8 - TR.Frc.x;
						double d9 = stod(iter->at(9));			//9 - TR.Frc.y;
						double d10 = stod(iter->at(10));	  //10- TR.Frc.z;
						double d11 = stod(iter->at(11));	  //11-  TR.muRoad;
						double d12 = stod(iter->at(12));		//12- TR.vBelt;
						double d13 = stod(iter->at(13));		//13- YawAcc;
						double d14 = stod(iter->at(14));		//14- YawVel;
						double d15 = stod(iter->at(15));		//15 - Engine.Trq;
						double d16 = stod(iter->at(16));		//16- Engine.rotv;

						//atof(s.c_str());
						_vecDouble->push_back(make_tuple(d0, d1, d2, d3, d4, d5, d6, d7, 
																d8, d9, d10, d11, d12, d13, d14, d15, d16));
				}

				return _vecDouble;
		}

}


/*
0 - Speed;
1 - Fr1.x;
2 - Fr1.y;
3 - Fr1.z;
4 - PitchVel;
5 - RollVel;
6 - TF.muRoad;
7 - TF.vBelt;
8 - TR.Frc.x;
9 - TR.Frc.y;
10- TR.Frc.z;
11- TR.muRoad;
12- TR.vBelt;
13- YawAcc;
14- YawVel;
15- Engine.Trq;
16- Engine.rotv;
17- Time

*/