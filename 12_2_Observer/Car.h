#pragma once
#include"Product.h"

// Класс ConcreteSubject
// Класс конкретного продукта
// В нашем случае машины
class Car : public Product
{
public:
	Car(string name, double price) :Product(name, price) {}
};

