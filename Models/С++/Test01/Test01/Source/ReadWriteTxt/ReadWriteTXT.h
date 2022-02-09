#pragma once
// #include <io.h>
#include <iostream>     // std::cout
#include <fstream>
#include <sstream> 
#include <string>
#include <vector>
#include <memory>

#ifndef ReadWriteTXT_H_
#define ReadWriteTXT_H_

using namespace std;

namespace my_read_write
{
	struct SReadDan
	{
		double x, y;
		SReadDan(double x, double y) 
		{ 
				this->x = x; this->y = y; 
		}

		SReadDan(vector<string> &v) 
		{
			x = std::stod(v[0]);
			y = std::stod(v[1]);
		}

	};

	typedef  shared_ptr<vector<SReadDan>> VecDan;
	typedef  shared_ptr<vector<vector<string>>> VecStrStr;

	class ReadWriteTXT
	{
	public:
		ReadWriteTXT(string s_read_path = "", string s_write_path = "");
		void SetPath(string s_read_path, string s_write_path);
		VecDan ReadDan(string s_read_path = "");
		VecStrStr ReadDan(string s_read_path, char delimiter=';');
		void WriteDan(VecDan dan1, string s_write_path = "");
		void WriteDan(VecDan dan1, VecDan dan2, string s_write_path = "");
	
	protected:		
		string s_read_path, s_write_path;

		inline std::vector<std::string> split(const std::string& s, char delimiter);
	};

}
#endif /* ReadWriteTXT_H_ */

