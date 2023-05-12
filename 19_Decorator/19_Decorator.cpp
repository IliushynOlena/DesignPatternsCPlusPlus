#include <iostream>
using namespace std;

class Pizza
{
public:
    string name;
    Pizza()
    {
            
    }
    Pizza(string n)
    {
        name = n;
    }
    virtual int GetCost() = 0;
};

class ItalianPizza :public Pizza
{
public:
    ItalianPizza() : Pizza("Italian pizza")
    { }
    int GetCost()override
    {
        return 10;
    }
};
class BulgerianPizza :public Pizza
{
public:
    BulgerianPizza()
        : Pizza("Boldarian pizza")
    { }
    int GetCost()override
    {
        return 8;
    }
};
class PizzaDecorator :public  Pizza
{
protected:
    Pizza* pizza;

public:
    PizzaDecorator(string n, Pizza* pizza) : Pizza(n)
    {
        this->pizza = pizza;
    }
};

class TomatoPizza : public PizzaDecorator
{
public:
    TomatoPizza(Pizza* p)
        : PizzaDecorator(p->name + ", with tomato", p)
    { }

    int GetCost()override
    {
        return pizza->GetCost() + 3;
    }
};

class CheesePizza :public PizzaDecorator
{
public:
    CheesePizza(Pizza* p)
        : PizzaDecorator(p->name + ", with cheese", p)
    { }

    int GetCost()override
    {
        return pizza->GetCost() + 5;
    }
};

int main()
{
    Pizza *pizza1 = new ItalianPizza();
    cout << "Name: " << pizza1->name <<endl;
    cout << "Price: " << pizza1->GetCost() << endl;
    pizza1 = new TomatoPizza(pizza1); // итальянская пицца с томатами
    cout<< "Name: "<<   pizza1->name << endl;
    cout << "Price: "<< pizza1->GetCost() << endl;

    Pizza *pizza2 = new ItalianPizza();
    cout << "Name: " << pizza2->name << endl;
    cout << "Price: " << pizza2->GetCost() << endl;
    pizza2 = new CheesePizza(pizza2);// итальянская пиццы с сыром
    cout<< "Name: "<<   pizza2->name << endl;
    cout << "Price: "<<pizza2->GetCost() << endl;

    Pizza *pizza3 = new BulgerianPizza();
    cout << "Name: " << pizza3->name << endl;
    cout << "Price: " << pizza3->GetCost() << endl;
    pizza3 = new TomatoPizza(pizza3);
    pizza3 = new CheesePizza(pizza3);// болгарская пиццы с томатами и сыром
    cout << "Name: " << pizza3->name << endl;
    cout << "Price: " << pizza3->GetCost() << endl;

    delete pizza1;
    delete pizza2;
    delete pizza3;
}

