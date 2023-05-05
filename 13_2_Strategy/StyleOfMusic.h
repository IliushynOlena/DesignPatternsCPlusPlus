#pragma once
#include <iostream>
using namespace std;

// ������� ����� ��������� 
class StyleOfMusic
{
public:
	virtual void SingSong(string name) = 0;
};
// ���������� ����� ���������. ��� ���������� �����
class RapStyleOfMusic :public StyleOfMusic
{
public:
	void SingSong(string name)
	{
		cout << "\nRap version of " << name.c_str() << " \n";
	}
};
// ���������� ����� ���������. ��� ���������� �����
class RockStyleOfMusic : public StyleOfMusic
{
public:
	void SingSong(string name)
	{
		cout << "\nRock version of " << name.c_str() << " \n";
	}
};
// ���������� ����� ���������. ��� ���������� �����
class PopStyleOfMusic : public StyleOfMusic
{
public:
	void SingSong(string name)
	{
		cout << "\nPop version of " << name.c_str() << " \n";
	}
};
