#include <iostream>
using namespace std;

class Subject
{
public:
    virtual void Print()
    {
        cout << "this is a print\n";
    }
};

class SubjectProxy : public Subject
{
public:
    void Print() override
    {
        cout << "Before calling Subject::Print()\n";
        Subject::Print();
        cout << "After calling Subject::Print()\n";
    }
};

class Helper
{
public:
    static Subject* GetSubject()
    {
        return new SubjectProxy();
    }
};
void Test(Subject* subject)
{
    subject->Print();
}
//class Helper
//{
//public:
//    static Subject* GetSubject()
//    {
//        return new SubjectProxy();
//    }
//};
void main()
{
    Subject* subject = Helper::GetSubject();
    SubjectProxy p;
    subject->Print(); // would use the proxied method
    p.Print();
    cout << "****************" << endl;
    Test(subject);
    Test(&p);
    delete subject;
}