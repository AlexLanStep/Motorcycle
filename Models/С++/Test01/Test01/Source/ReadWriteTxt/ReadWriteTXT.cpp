#include "ReadWriteTXT.h"


namespace my_read_write
{
	
	ReadWriteTXT::ReadWriteTXT(string s_read_path, string s_write_path)
	{
		SetPath(s_read_path, s_write_path);
	}

	void ReadWriteTXT::SetPath(string s_read_path, string s_write_path) 
	{
		this->s_read_path = s_read_path;
		this->s_write_path = s_write_path;
	}

	VecDan  ReadWriteTXT::ReadDan(string s_read_path)
	{
		VecDan _vecdan = nullptr;
		string s; // сюда будем класть считанные строки

		if (s_read_path != "") {
			this->s_read_path = s_read_path;
		}
		else 
		{
			if(this->s_read_path =="")
				this->s_read_path = "E:\\MatLab\\TAU\\Sigmoid\\SigmoidC++\\SigmoidC++\\FileDan.txt";
		}
		std::ifstream file(this->s_read_path);
		
		bool isTitle = true;

		_vecdan = make_shared<vector<SReadDan>>();

		while (getline(file, s) ) { // пока не достигнут конец файла класть очередную строку в переменную (s)
//			cout << s << endl; // выводим на экран
			if (isTitle)
			{
				isTitle = false;
				continue;
			}

			auto _x = split(s, ',');
			_vecdan->push_back(SReadDan(_x));
		}
		file.close(); // обязательно закрываем файл что бы не повредить его
		return _vecdan;
	}

	VecStrStr  ReadWriteTXT::ReadDan(string s_read_path, char delimiter)
	{
//			auto _vecdan = nullptr;
			string s; // сюда будем класть считанные строки

			if (s_read_path != "") {
					this->s_read_path = s_read_path;
			}
			else
			{
					if (this->s_read_path == "")
							return nullptr;
			}
			std::ifstream file(this->s_read_path);

			bool isTitle = true;

			VecStrStr _vecdan = make_shared<vector<vector<string>>>();

			while (getline(file, s)) { // пока не достигнут конец файла класть очередную строку в переменную (s)
	//			cout << s << endl; // выводим на экран
					if (isTitle)
					{
							isTitle = false;
							continue;
					}

					auto z = split(s, delimiter);
					_vecdan->push_back(z);
			}
			file.close(); // обязательно закрываем файл что бы не повредить его
			return _vecdan;
	}



	std::vector<std::string>  ReadWriteTXT::split(const std::string& s, char delimiter)
	{
		std::vector<std::string> tokens;
		std::string token;

		std::istringstream tokenStream(s);
		while (std::getline(tokenStream, token, delimiter))
			tokens.push_back(token);
		return tokens;
	}

	void  ReadWriteTXT::WriteDan(VecDan dan1, string s_write_path)
	{
		if (dan1->size() <= 0)
			return;

		if (s_write_path != "") {
			this->s_write_path = s_write_path;
		}
		else
		{
			if (this->s_write_path == "")
				this->s_write_path = "E:\\MatLab\\TAU\\Sigmoid\\SigmoidC++\\SigmoidC++\\SaveDan.txt";
		}


		std::ofstream file(this->s_write_path);
		for(auto it : *dan1)
		{
//			string s = std::to_string(it.x) + " " + std::to_string(it.y)+ "\n";
			file <<  std::to_string(it.x) + "; " + std::to_string(it.y) + "\n";
			
		}
		file.close();
	}

	void  ReadWriteTXT::WriteDan(VecDan dan1, VecDan dan2, string s_write_path) 
	{
	}

	shared_ptr<vector<vector<string>>> ReadDan(string s_read_path, char delimiter)
	{
			return shared_ptr<vector<vector<string>>>();
	}


}