#pragma once
#include <string>
#include <vector>
#include"StyleOfMusic.h"
using namespace std;

// ����� ���������
class Songs
{
private:
	// ��������� �� ���������� ���������
	StyleOfMusic* pStyle;
	// �����
	vector<string> songs;
public:
	// ���������� �����
	void AddSong(string name)
	{
		songs.push_back(name);
	}
	// ��������� ���������� ��������� 
	void SetConcreteStyle(StyleOfMusic* ptr)
	{
		pStyle = ptr;
	}
	// ��������� ����� � ���������� ����� (��������� ���������� ���������)
	void SingSongs()
	{
		cout << "\n\nLet's sing\n\n";
		for (int i = 0; i < songs.size(); i++)
		{
			pStyle->SingSong(songs[i]);
		}
		cout << "\n\nThe end\n\n";
	}
};
