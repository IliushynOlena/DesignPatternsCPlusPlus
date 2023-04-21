#include <iostream>
#include <string>
using namespace std;

// Prototype Interface
template<class T>
class Prototype
{
public:
	virtual T Clone() const = 0;
};

struct Date
{
	int year, month, day;

	string ToString() const
	{
		return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
	}
};

class Member : public Prototype<Member>
{
private:
	string name;
	int age;
public:
	
	Member() : name("no name"), age(0) { }
	Member(string name, int age) : name(name), age(age) {  }

	Member Clone() const
	{
		return *this;//00xgh562ff
	}

	string ToString() const
	{
		return name + to_string(age);
	}
};

class Event : public Prototype<Event>
{
private:
	string name;//Independency day    Independency day
	Date date;//24/08/2023            24/08/2023
	string address;//Soborna          Soborna
	Member* members;//0x00ghtr56      0x000123
	int membersCount;//10             10
public:  

	Event() : name("no name"), date(Date{ 0, 0, 0 }), address("no address") { }
	Event(string name, Date date, string address) : name(name), date(date), address(address) { }

	void AddTestMembers()
	{
		membersCount = 2;
		members = new Member[membersCount];

		members[0] = Member("Bob", 30);
		members[1] = Member("Vova", 44);
	}
	Event Clone() const override
	{
		Event clone = *this;//поверхнева копія
		clone.members = new Member[membersCount];//глибоке копіювання
		for (int i = 0; i < membersCount; i++)
		{
			clone.members[i] = this->members[i].Clone();
		}
		return clone;
	}
	/*~Event()
	{
		if (members != nullptr)
			delete[]members;
	}*/

	string ToString() const
	{
		string res = name + " : " + date.ToString() + "\n" + address;
		for (int i = 0; i < membersCount; i++)
		{
			res += "\n\tMember[" + to_string(i + 1) + "] - " + members[i].ToString();
		}
		return res;
	}


};


void main()
{
	

	// testing...
	Event event1("Independence Day", Date{ 2023, 8, 24 }, "Kyiv, Ukraine");
	// initializing...
	event1.AddTestMembers();

	cout << event1.ToString() << endl;

	Event cloneEvent = event1.Clone();

	cout << cloneEvent.ToString() << endl;
}








//int sum(int a, int b)
//{
//	return a + b;
//}
//
//constexpr int new_sum(int a, int b)
//{
//	return a + b;
//}

//void func()
//{
//	int a, b;
//	cin >>a>>b;
//	constexpr int a1 = new_sum(5, 12); // ОК: constexpr-переменная
//	const int a2 = new_sum(5, 12); // ОК: constexpr-переменная
//	//constexpr int a1 = new_sum(a, b); // ОК: constexpr-переменная
//	//constexpr int a2 = sum(5, 12); // ошибка: функция sum не является constexp-выражением
//	int a3 = new_sum(5, 12); // ОК: функция будет вызвана на этапе компиляции
//	int a4 = sum(5, 12); // ОК
//}