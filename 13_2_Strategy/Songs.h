#pragma once
#include <string>
#include <vector>
#include"StyleOfMusic.h"
using namespace std;

// класс контекста
class Songs
{
private:
	// указатель на конкретную стратегию
	StyleOfMusic* pStyle;
	// песни
	vector<string> songs;
public:
	// добавление песен
	void AddSong(string name)
	{
		songs.push_back(name);
	}
	// установка конкретной стратегии 
	void SetConcreteStyle(StyleOfMusic* ptr)
	{
		pStyle = ptr;
	}
	// исполняем песни в конкретном стиле (используя конкретную стратегию)
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
