#pragma once
#include <string>
#include<list>
#include<iostream>

using namespace std;

class Buyer;

// класс Subject
// В нашем случае это класс Product, который описывает абстрактный продукт

class Product
{
private:
	// название 
	string name;
	// цена
	double price;
	list<Buyer*> buyers;
public:
	Product(string, double);
	~Product();

public:
	// добавление конкретного покупателя 
	void Attach(Buyer*);
	// удаление конкретного покупателя
	void Detach(Buyer*);
	// сообщение всем покупателям об изменении состояния
	void Notify();
public:

	string GetName() const
	{
		return name;
	}

	double GetPrice() const
	{
		return price;
	}
	// установка новой цены и информирование покупателей об этом
	void SetPrice(double pPrice)
	{
		if (price != pPrice)
		{
			price = pPrice;
			Notify();
		}
	}
};