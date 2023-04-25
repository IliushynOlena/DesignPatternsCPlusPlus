#include <iostream>
#include <string>
#include<fstream>
#include <chrono> 
#include <ctime> 
#include<exception>
#include<iomanip>
#include<conio.h>
using namespace std;

class Singleton
{
private:
	Singleton() {} //ctor
	Singleton(const Singleton&) = delete; //ctro copy
	Singleton& operator = (Singleton&) = delete;

public:
	static Singleton& GetInstance() {
		static Singleton instance;
		return instance;
	}

	void Log(string msg, const string& fileName) {
		time_t now = time(0);
		struct tm timeinfo;

		localtime_s(&timeinfo, &now);
		int hour = timeinfo.tm_hour;
		int minute = timeinfo.tm_min;

		ofstream file(fileName, std::ios::app);

		if (!file.is_open()) {
			throw runtime_error("Error when opening the file");
		}
		else file << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "") << minute << " " << msg << endl;

	}

};

void menu()
{
	cout << "1. Add text to file" << endl;
	cout << "2. read from the recording file" << endl;
}
int main()
{
	string text;
	int choice;
	ifstream file;
	file.open("singleton_.txt", std::ios::app);
	try {
		while (true)
		{
			menu();
			cout << "\nEnter your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "Enter text to add: ";
				cin.ignore();
				getline(cin, text);
				Singleton::GetInstance().Log(text, "singleton_.txt");
				break;

			case 2:

				file.clear();
				file.seekg(0, ios::beg);
				while (getline(file, text)) {
					cout << setw(3) << "";
					cout << text << endl;
				}

			default:
				break;
			}

			cout << "\n\nDo you want to continue? y/n";
			choice = _getch();

			system("cls");
		}
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
	}

	file.close();


}
