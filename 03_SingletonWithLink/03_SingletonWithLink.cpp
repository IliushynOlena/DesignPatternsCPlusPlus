#include <iostream>
#include <string>
using namespace std;

// Singleton with destructor
class Singleton
{
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(Singleton&) = delete;
public:
	static Singleton& GetInstance() {
		static Singleton instance;
		return instance;
	}

	void Log(string msg)
	{
		cout << "Msg: " << msg << endl;
	}
};

int main()
{
	Singleton& single = Singleton::GetInstance();
	single.Log("Hello");
	Singleton::GetInstance().Log("Insert new user at 19:57PM");
	Singleton::GetInstance().Log("faerga");
	Singleton::GetInstance().Log("earg");

	system("pause");
	return 0;
}