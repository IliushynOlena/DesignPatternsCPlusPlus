#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Graphical
{
public:
    virtual void Draw() = 0;
    virtual void Add(Graphical * g) {};
    virtual void Remove(Graphical* g) {};
    virtual Graphical* GetChild(int index) { return nullptr; };
    virtual ~Graphical() {};
};
//Leaf
class Line : public Graphical
{
public:
    void Draw() override
    {
        cout << "Draw line" << endl;
    };
};
//Leaf
class Rectangle : public Graphical
{
public:
    void Draw() override
    {
        cout << "Draw Rectangle" << endl;
    };
};
//Leaf
class Circle : public Graphical
{
public:
    void Draw() override
    {
        cout << "Draw Cycle" << endl;
    };
};
//Leaf
class Text : public Graphical
{
public:
    void Draw() override
    {
        cout << "Draw Text" << endl;
    };
};

//Graphical composite: Leaf, others compositions etc
class Composition : public Graphical
{
private:
    vector<Graphical*> children;
public:
    void Draw()override
    {
        for (auto c : children)
        {
            c->Draw();
        }
    };
    void Add(Graphical* g)override
    {
        children.push_back(g);
    };
    void Remove(Graphical* g)override
    {
        auto f = find(children.begin(), children.end(), g);
        if (f != children.end())
        {
            children.erase(f);
        }
    };
    Graphical* GetChild(int index)override
    { 
        return children[index]; 
    };
    
};

int main()
{
    Composition root;
    Line one_line, two_line;
    Text text;
    Circle circle;
    Rectangle rectangle;

    Composition embededComposition;
    //Line another_one_line, another_two_line;//1-2
    Text another_text;//3
    Circle another_circle;//4
    //Rectangle another_rectangle;//5
    //embededComposition.Add(&another_one_line);
    //embededComposition.Add(&another_two_line);
    embededComposition.Add(&another_text);
    embededComposition.Add(&another_circle);
    //embededComposition.Add(&another_rectangle);

    root.Add(&one_line);//0
    root.Add(&embededComposition);//1
    root.Add(&two_line);//2
    root.Add(&text);//3
    root.Add(&circle);//4
    root.Add(&rectangle);//5

    root.Draw();
    
    //delete Text embededComposition
    root.GetChild(1)->Remove(root.GetChild(1)->GetChild(0));
    cout << "* * * * * * * * * **  * *" << endl;
    root.Draw();
}

