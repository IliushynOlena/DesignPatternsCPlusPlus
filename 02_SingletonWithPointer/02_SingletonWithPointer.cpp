#include <iostream>
#include <string>
using namespace std;

// Singleton
class Singleton
{
private:
	
     static Singleton* p_instance;
	// Конструктори і оператор присвоювання недоступні клієнтам	
	Singleton() {};
	Singleton(const Singleton&) = delete;
	Singleton& operator=(Singleton&) = delete;
public:

	static Singleton* GetInstance()
	{
		if (p_instance == nullptr) // !p_instance
			p_instance = new Singleton();
		return p_instance;
	}
	~Singleton()
	{
		/*if (p_instance != nullptr)
			delete p_instance;*/
		p_instance = nullptr;
		cout << "deleted!!!\n";
	}
	void Log(string msg)
	{
		cout << "Msg: " << msg << endl;
	}

};
Singleton* Singleton::p_instance = nullptr;
int main()
{

	
	Singleton* single = Singleton::GetInstance();
	cout << single << endl;

	single->Log("Hello!");
	Singleton* single1 = Singleton::GetInstance();
	single1->Log("World!");
	Singleton::GetInstance()->Log("nlkdbnsdkb");
	Singleton::GetInstance()->Log("Insert new user at 19:57PM");
	Singleton::GetInstance()->Log("faerga");
	Singleton::GetInstance()->Log("earg");
	Singleton::GetInstance();
	Singleton::GetInstance()->GetInstance()->GetInstance()->GetInstance();
	
	 
	delete Singleton::GetInstance();
	Singleton* single2 = Singleton::GetInstance();
	single2->Log("single2");
	delete Singleton::GetInstance();
	//delete single;
	//delete single1;
	system("pause");
	return 0;
}