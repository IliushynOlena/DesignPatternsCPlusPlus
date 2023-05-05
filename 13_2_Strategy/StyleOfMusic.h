#pragma once
#include <iostream>
using namespace std;

// базовый класс стратеги€ 
class StyleOfMusic
{
public:
	virtual void SingSong(string name) = 0;
};
// конкретный класс стратегии. –эп исполнение песни
class RapStyleOfMusic :public StyleOfMusic
{
public:
	void SingSong(string name)
	{
		cout << "\nRap version of " << name.c_str() << " \n";
	}
};
// конкретный класс стратегии. –ок исполнение песни
class RockStyleOfMusic : public StyleOfMusic
{
public:
	void SingSong(string name)
	{
		cout << "\nRock version of " << name.c_str() << " \n";
	}
};
// конкретный класс стратегии. ѕоп исполнение песни
class PopStyleOfMusic : public StyleOfMusic
{
public:
	void SingSong(string name)
	{
		cout << "\nPop version of " << name.c_str() << " \n";
	}
};
