
#include <iostream>
#include <string>
#include "Source/Slippage.h"
#include "ReadWriteTxt/ReadWriteTXT.h"
#include "Source/ReadWriteTxt/ConvertToSlipp.h"
#include <vector>
#include <map>


int main()
{
    setlocale(LC_ALL, "Russian");

    // коэф. нормировки     
    std::map<std::string, double> _k_norm = map<string, double>(); 
    _k_norm["yaw_acc"] = 380.0;
    _k_norm["yaw_vel"] = 400.0;
    _k_norm["roll_vel"] = 400.0;

    // файл для теста
    // std::string _path = "E:\\Motorcycle\\Data\\Basa\\T5_2021-10-08_10-44.csv";
    std::string _path = "E:\\Motorcycle\\Data\\Basa\\T4_2021-10-08_10-36.csv";

    std::shared_ptr<my_read_write::ConvertToSlipp> _read_convert;
    _read_convert = std::make_shared<my_read_write::ConvertToSlipp>();
    auto _dan = _read_convert->getVector(_path, ';');

    std::cout << "Данные загрузил !\n";

    //  Инициализируем class для расчета энергии спектра
    Slippage _slip = Slippage(_k_norm);

    // class - для записи данных на диск
    my_read_write::VecDan _test_dan = make_shared<vector<my_read_write::SReadDan>>();

    // тестируем модель 
    for (size_t i = 0; i < _dan->size(); i++)
    {
        auto x = _dan->at(i);
        _k_norm["yaw_acc"] = std::get<11>(x);
        _k_norm["yaw_vel"] = std::get<12>(x);
        _k_norm["roll_vel"] = std::get<5>(x);
        // передаем данные            
        auto _x = _slip.calc(&_k_norm, std::get<14>(x));
        // пишем значения в вестор
        _test_dan->push_back(my_read_write::SReadDan(std::get<14>(x), _x));
    }

    // сохраняем данные на диск для построения графика.
    my_read_write::ReadWriteTXT _write_dan = my_read_write::ReadWriteTXT();
    _write_dan.WriteDan(_test_dan, "E:\\test.csv");

    std::cout << "\n";
}

/*
    //std::shared_ptr<my_read_write::ReadWriteTXT> _read_write;
    //_read_write = std::make_shared<my_read_write::ReadWriteTXT>(_path, ";");
    //auto _z = _read_write->ReadDan(_path, ';');

 
            double d0 = stod(iter->at(0));			//0 - Speed;
            double d1 = stod(iter->at(1));			//1 - Fr1.x;
            double d2 = stod(iter->at(2));			//2 - Fr1.y;
            double d3 = stod(iter->at(3));			//3 - Fr1.z;
            double d4 = stod(iter->at(4));			//4 - PitchVel;
            double d5 = stod(iter->at(5));			//5 - RollVel;
            double d6 = stod(iter->at(7));			//7 - TF.vBelt;
            double d7 = stod(iter->at(8));			//8 - TR.Frc.x;
            double d8 = stod(iter->at(9));			//9 - TR.Frc.y;
            double d9 = stod(iter->at(10));		  //10- TR.Frc.z;
            double d10 = stod(iter->at(12));		//12- TR.vBelt;
            double d11 = stod(iter->at(13));		//13- YawAcc;
            double d12 = stod(iter->at(14));		//14- YawVel;
            double d13 = stod(iter->at(15));		//15 - Engine.Trq;
            double d14 = stod(iter->at(16));		//16- Engine.rotv;


*/