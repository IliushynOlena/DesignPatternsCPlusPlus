#include<iostream>
#include "Songs.h"
using namespace std;

int main()
{
	// ������� ������ ������ ���������
	// � ��� �� ������ �����
	Songs songs;

	// �������� �����
	songs.AddSong("Yesterday");
	songs.AddSong("Problem");
	songs.AddSong("Happy New Year");

	// ���������� ��������� ��� ���������� �����
	PopStyleOfMusic* pop = new PopStyleOfMusic();
	RapStyleOfMusic* rap = new RapStyleOfMusic();
	RockStyleOfMusic* rock = new RockStyleOfMusic();

	// ������������� ���������� ����� � ����
	songs.SetConcreteStyle(pop);
	songs.SingSongs();

	songs.SetConcreteStyle(rap);
	songs.SingSongs();

	songs.SetConcreteStyle(rock);
	songs.SingSongs();


	delete pop;
	delete rap;
	delete rock;

	system("pause");
	return 0;
}