#include <iostream>
using namespace std;

// Уже существующий класс температурного датчика окружающей среды
class FahrenheitSensor
{
public:
	// Получить показания температуры в градусах Фаренгейта
	float GetFahrenheitTemp()
	{
		float t = 48.0;
		// ... какой то код
		return t;
	}
};

// Interface
class Sensor
{
public:
	virtual ~Sensor() {}
	virtual float GetTemperature() = 0;
};

class Adapter : public Sensor
{
private:
	FahrenheitSensor* p_fsensor;
public:
	Adapter(FahrenheitSensor* p) : p_fsensor(p) { }

	float GetTemperature() override
	{
		return (p_fsensor->GetFahrenheitTemp() - 32.0) * 5.0 / 9.0;
	}
};

class ControlSystem
{
public:
	void Normilize(Sensor* sensor)
	{
		cout << "Celsius temperature = " << sensor->GetTemperature() << endl;
		// func
		// ........
	}
};


int main()
{
	FahrenheitSensor* fahrenheitSensor = new FahrenheitSensor();
	ControlSystem system;

	//system.Normilize(&fahrenheitSensor);
		

	//system.Normilize(&fahrenheitSensor);

	Adapter ad(fahrenheitSensor);
	system.Normilize(&ad);
	system.Normilize(new Adapter(fahrenheitSensor));

	delete fahrenheitSensor;
	return 0;
}


//class ClassicCar
//{
//public:
//	void PushGasPedal()
//	{
//		cout << "Gas pedal was pushed. Driving start...";
//	}
//	void PushBreak();
//	//...
//	void TurnLightOn();
//	//...
//};
//
//class Joystick
//{
//public:
//	void ClickArrowUp();
//	void ClickArrowLeft();
//	//...
//	void ClickA();
//	void ClickB();
//	//...
//};
//
//class Driver
//{
//public:
//	virtual void Drive(ClassicCar& j)
//	{
//		j.PushBreak();
//		j.PushGasPedal();
//		//...
//	}
//};
//
//// Adapter. Adapt ClassicCar Interface to Joystick Methods
//
//void main()
//{
//	Driver driver;
//	ClassicCar j;
//	driver.Drive(j);
//	Joystick car;
//
//	driver.Drive(car); // error: required adapter
//}