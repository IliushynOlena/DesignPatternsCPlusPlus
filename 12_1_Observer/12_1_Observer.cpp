#include <iostream>
#include <vector>
using namespace std;

class Observer//abstract
{
	int denom;
public:
	Observer(int div)
	{
		denom = div;
	}
	virtual void update(int value) = 0;

protected:
	int getDivisor()
	{
		return denom;
	}
};

class Subject
{
	vector<Observer*> views;
	int value;

public:
	void attach(Observer* obs)
	{
		views.push_back(obs);
	}
	void detach(Observer* obs)
	{
		for (auto i = views.begin(); i != views.end(); i++)
		{
			if (*i == obs)
			{
				views.erase(i);
				break;
			}
		}
	}
	void setVal(int val)
	{
		value = val;
		notify();
	}

	void notify()
	{
		// notify all subscribers
		for (auto o : views)
			o->update(value);
	}
};

class DivObserver : public Observer
{
public:
	DivObserver(int div) : Observer(div) {}
	void update(int value)
	{
		int v = value, d = getDivisor();
		cout << v << " div " << d << " is " << v / d << '\n';
	}
};

class ModObserver : public Observer
{
public:
	ModObserver(int div) : Observer(div) {}
	void update(int value)
	{
		int v = value, d = getDivisor();
		cout << v << " mod " << d << " is " << v % d << '\n';
	}
};

int main()
{
	Subject subj;

	DivObserver divObs1(4);
	DivObserver divObs2(3);
	ModObserver modObs3(3);

	// subscribe
	subj.attach(&divObs1);
	subj.attach(&divObs2);
	subj.attach(&modObs3);

	int n = 0;
	do
	{
		cout << "Number: "; cin >> n;
		subj.setVal(n);

	} while (n != 0);

	subj.detach(&divObs2);
	do
	{
		cout << "Number: "; cin >> n;
		subj.setVal(n);

	} while (n != 0);

	system("pause");
}