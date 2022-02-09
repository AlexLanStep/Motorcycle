#pragma once

#include <string>
#include <vector>
#include <memory>

#include "ReadWriteTXT.h"


#ifndef CONVERTTOSLIPP_H_
#define CONVERTTOSLIPP_H_

typedef  shared_ptr<vector<tuple<double, double, double, double, double, 
																double, double, double, double, double,
																double, double, double, double, double
		>>> VecDouble;

namespace my_read_write
{

		class ConvertToSlipp : public ReadWriteTXT 
		{
		public:
				ConvertToSlipp(string s_read_path = "") : ReadWriteTXT(s_read_path, "")
				{
				}

				VecDouble getVector(string s_read_path, char delimiter);
		};


}

#endif /* CONVERTTOSLIPP_H_ */
