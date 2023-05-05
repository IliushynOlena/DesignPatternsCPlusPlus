#include<iostream>
#include "Songs.h"
using namespace std;

int main()
{
	// создаем объект класса контекста
	// в нем мы храним песни
	Songs songs;

	// добавили песни
	songs.AddSong("Yesterday");
	songs.AddSong("Problem");
	songs.AddSong("Happy New Year");

	// конкретные стратегии для исполнения песен
	PopStyleOfMusic* pop = new PopStyleOfMusic();
	RapStyleOfMusic* rap = new RapStyleOfMusic();
	RockStyleOfMusic* rock = new RockStyleOfMusic();

	// устанавливаем конкретный стиль и поем
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