#include <iostream>
using namespace std;

enum handle_types{normal, conflicts, danger, war, espionage};

class Component
{
public :
    virtual void handle(handle_types t) = 0;
};

class Chain : public Component
{
private :
    Chain * next_chain;
public:
    Chain(Chain * n):next_chain(n) {}
    void handle(handle_types t) override
    {
        if (next_chain)
        {
            next_chain->handle(t);
        }
    }
    Chain* AddNext(Chain* n)
    {
        if (next_chain)
        {
            AddNext(n);
        }
        else
            next_chain = n;
        return next_chain;
    }
};
class Archer :public Chain
{
public:
    Archer(Chain* n = nullptr):Chain(n) {}
    void handle(handle_types t) override
    {
        if (t == normal)
        {
            cout << "Archers are raised!!!" << endl;
        }
        else
        {
            if (t == war)
            {
                cout << "Archers are raised!!!" << endl;
                Chain::handle(t);
            }
            else
            {
                Chain::handle(t);
            }
        }
           
    }
};

class Horsman :public Chain
{
public:
    Horsman(Chain* n = nullptr) :Chain(n) {}
    void handle(handle_types t) override
    {
        if (t == conflicts)
        {
            cout << "Horsman are raised!!!" << endl;
        }
        else
        {
            if (t == war)
            {
                cout << "Horsman are raised!!!" << endl;
                Chain::handle(t);
            }
            else
            {
                Chain::handle(t);
            }
        }

    }
};
class Infanmen :public Chain//pixota
{
public:
    Infanmen(Chain* n = nullptr) :Chain(n) {}
    void handle(handle_types t) override
    {
        if (t == danger)
        {
            cout << "Infanmen are raised!!!" << endl;
        }
        else
        {
            if (t == war)
            {
                cout << "Infanmen are raised!!!" << endl;
                Chain::handle(t);
            }
            else
            {
                Chain::handle(t);
            }
        }

    }
};
int main()
{
    Archer archers;
    Horsman horsmans;
    Infanmen infanmens;

    archers.AddNext(&horsmans)->AddNext(&infanmens);

    archers.handle(war);
    cout << "-------------------------" << endl;
    archers.handle(normal);
    cout << "-------------------------" << endl;
    archers.handle(danger);
    cout << "-------------------------" << endl;
    archers.handle(conflicts);
    cout << "-------------------------" << endl;
}

