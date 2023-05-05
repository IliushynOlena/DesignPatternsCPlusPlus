#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

class GameState
{
public:
	// private:
	double Health;
	int KilledMonsters;
	string SaveTime;

	GameState() { }
	GameState(double health, int killedMonsters)
	{
		Health = health;
		KilledMonsters = killedMonsters;
		SaveTime = "04.09.2020";
	}

	void Show()
	{
		cout << "Health: " << Health << "\nKilled Monsters: "
			<< KilledMonsters << "\nST " << SaveTime << endl;
		cout << "-----------------------\n";
	}
};

class GameMemento
{
private:
	GameState _state;

public:
	GameMemento(GameState state)
	{
		_state = state;
	}

	GameState GetState()
	{
		return _state;
	}

	void Show()
	{
		cout << "From Memento - ";
		_state.Show();
	}
};

class GameOriginator
{
private:
	GameState _state; //Health & Killed Monsters

public:
	GameOriginator()
	{
		_state = GameState(100, 0);
	}
	void Play()
	{
		//During this Play method game's state is continuously changed	
		_state = GameState((int)(_state.Health * 0.9), _state.KilledMonsters + 2);
		cout << "Palying...\n";
		_state.Show();
	}

	GameMemento GameSave()
	{
		_state.Show();
		return GameMemento(_state);
	}

	void LoadGame(GameMemento memento)
	{
		_state = memento.GetState();
		_state.Show();
	}
};

class Caretaker
{
private:
	GameOriginator _game;
	vector<GameMemento> _quickSaves;

public:
	void Shoot()
	{
		_game.Play();
	}

	void F5()
	{
		if (_quickSaves.size() >= 3) cout << "No available saves!\n";
		else _quickSaves.push_back(_game.GameSave());
	}

	void F9()
	{
		if (_quickSaves.size() > 0)
		{
			_game.LoadGame(_quickSaves.back());
			_quickSaves.pop_back();
		}
	}
};

void main()
{
	Caretaker caretaker = Caretaker();
	//caretaker.F5();
	//caretaker.Shoot();
	//Sleep(2000);
	//caretaker.F5();
	//Sleep(2000);
	//caretaker.F5();
	//Sleep(2000);
	//cout << "\n*************\n";
	//caretaker.Shoot();
	//caretaker.F5();
	//Sleep(2000);
	//caretaker.Shoot();
	//caretaker.Shoot();
	//cout << "\n*************\n";
	//caretaker.F9();
	//cout << "\n*************\n";
	//caretaker.Shoot();
	//caretaker.Shoot();
	//caretaker.F9();
	//caretaker.F9();
	//cout << "\n*************\n";
	//caretaker.F9();
	//caretaker.F9();		
	//caretaker.Shoot();

	cout << "0 - exit\n1 - Shoot\n2 - Save Game\n3 - Load Game\n----------------------------\n";
	int input = 0;
	do
	{
		cin >> input;

		switch (input)
		{
		case 1: caretaker.Shoot();	break;
		case 2: caretaker.F5();		break;
		case 3: caretaker.F9();		break;
		}

	} while (input != 0);

	//caretaker.Shoot();		  cin.get();
	//caretaker.F5();			  cin.get();
	//caretaker.Shoot();		  cin.get();
	//caretaker.F9();			  cin.get();
	//caretaker.Shoot();		  cin.get();
	//caretaker.Shoot();		  cin.get();
	//caretaker.Shoot();		  cin.get();
	//caretaker.F5();			  cin.get();
	//caretaker.Shoot();		  cin.get();
	//caretaker.Shoot();		  cin.get();
	//caretaker.F9();			  cin.get();
	//caretaker.F9();			  cin.get();

	system("pause");
}