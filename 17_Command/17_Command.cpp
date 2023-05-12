#include <iostream>
#include <stack>
using namespace std;

enum actions { Home = -1, On, Off, Fvd, Bck, Lft, Rgh, Act, Ext };

actions user_input()
{
    cout << "Enter command (0: On, 1: Off, 2: Fvd, 3: Bck, 4: Lft, 5: Rgh, 6: Act, 7: Extra, Home: -1):\n";
    int answer;
    cin >> answer;
    cout << '\n';
    return (actions)answer;
}

class IRobot   // Interface - abstarct
{
public:
    void power_on() { cout << "Activated!\n"; }
    void power_off() { cout << "Deactivated!\n"; }
    virtual void move_forvard() = 0;
    virtual void move_back() = 0;
    virtual void move_left() = 0;
    virtual void move_right() = 0;

    virtual void main_action() = 0;

    virtual ~IRobot() {}
};

class SapperRobot : public IRobot
{
public:
    virtual void move_forvard() override { std::cout << "Move forvard.\n"; }
    virtual void move_back() override { std::cout << "Move back.\n"; }
    virtual void move_left() override { std::cout << "Move left.\n"; }
    virtual void move_right() override { std::cout << "Move right.\n"; }

    virtual void main_action() override { std::cout << "Main action: deactivate the bomb!\n"; }
};

class TransporterRobot : public IRobot
{
public:
    virtual void move_forvard() override { std::cout << "Move forvard.\n"; }
    virtual void move_back() override { std::cout << "Move back.\n"; }
    virtual void move_left() override { std::cout << "Move left.\n"; }
    virtual void move_right() override { std::cout << "Move right.\n"; }

    virtual void main_action() override { std::cout << "Transporting the bomb outside the area!\n"; }
};


class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

// Concrete commands:

class Power_On_Command : public Command
{
private:
    IRobot* robot = nullptr;
public:
    Power_On_Command(IRobot* r) : robot(r) {}
    void execute() override
    {
        robot->power_on();
    }
};

class Power_Off_Command : public Command
{
private:
    IRobot* robot;
public:
    Power_Off_Command(IRobot* r) : robot(r) {}
    void execute() override
    {
        robot->power_off();
    }
};

class Move_Forfard_Command : public Command
{
private:
    IRobot* robot;
public:
    Move_Forfard_Command(IRobot* r) : robot(r) {}
    void execute() override
    {
        robot->move_forvard();
    }
};

class Move_Back_Command : public Command
{
private:
    IRobot* robot;
public:
    Move_Back_Command(IRobot* r) : robot(r) {}
    void execute() override
    {
        robot->move_back();
    }
};

class Move_Left_Command : public Command
{
private:
    IRobot* robot;
public:
    Move_Left_Command(IRobot* r) : robot(r) {}
    void execute() override
    {
        robot->move_left();
    }
};

class Move_Right_Command : public Command
{
private:
    IRobot* robot;
public:
    Move_Right_Command(IRobot* r) : robot(r) {}
    void execute() override
    {
        robot->move_right();
    }
};


class Main_Action_Command : public Command
{
private:
    IRobot* robot;
public:
    Main_Action_Command(IRobot* r) : robot(r) {}
    void execute() override
    {
        robot->main_action();
    }
};


// Invoker

class CommandCenter
{
private:
    Command* on;
    Command* off;
    Command* forvard;
    Command* back;
    Command* left;
    Command* right;
    Command* action;
    Command* extra;

    stack<Command*> history;

    void clear()
    {
        delete on;
        delete off;
        delete forvard;
        delete back;
        delete left;
        delete right;
        delete action;
        history = stack<Command*>{};
    }

public:
    CommandCenter(Command* o_n, Command* o_f_f, Command* f_t, Command* b_k, Command* l_t, Command* r_t, Command* act, Command* extr = nullptr) :
        on(o_n), off(o_f_f), forvard(f_t), back(b_k), left(l_t), right(r_t), action(act), extra(extr) {}

    void setCommands(Command* o_n, Command* o_f_f, Command* f_t, Command* b_k, Command* l_t, Command* r_t, Command* act)
    {
        clear();
        on = o_n;
        off = o_f_f;
        forvard = f_t;
        back = b_k;
        left = l_t;
        right = r_t;
        action = act;
    }

    bool handleInput()
    {
        // enum actions{Home, On, Off, Fvd, Bck, Lft, Rgh, Act, Ext};

        switch (user_input())
        {
        case On: on->execute(); history.push(on); return true;
        case Off: off->execute(); history.push(off); return true;
        case Fvd: forvard->execute(); history.push(forvard); return true;
        case Bck: back->execute(); history.push(back); return true;
        case Lft: left->execute(); history.push(left); return true;
        case Rgh: right->execute(); history.push(right); return true;
        case Act: action->execute(); return true;
        case Ext: if (extra) extra->execute(); return true;
        case Home: back_home(); return true;
        }
        return false;
    }

    void back_home()  // inverting commands from stack
    {
        while (!history.empty())
        {
            if (history.top() == on) off->execute();
            if (history.top() == off) on->execute();
            if (history.top() == forvard) back->execute();
            if (history.top() == back) forvard->execute();
            if (history.top() == left) right->execute();
            if (history.top() == right) left->execute();
            history.pop();
        }
    }

    ~CommandCenter() { clear(); }
};


int main()
{
    SapperRobot sapper_robot;
    TransporterRobot transport_robot;

    CommandCenter center(new Power_On_Command(&sapper_robot),
        new  Power_Off_Command(&sapper_robot),
        new Move_Forfard_Command(&sapper_robot),
        new Move_Back_Command(&sapper_robot),
        new Move_Left_Command(&sapper_robot),
        new Move_Right_Command(&sapper_robot),
        new Main_Action_Command(&sapper_robot));

    while (center.handleInput())
    {
        std::cout << ".............MINNER.ROBOT...........\n";
    }

    center.setCommands(new Power_On_Command(&transport_robot),
        new Power_Off_Command(&transport_robot),
        new Move_Forfard_Command(&transport_robot),
        new Move_Back_Command(&transport_robot),
        new Move_Left_Command(&transport_robot),
        new Move_Right_Command(&transport_robot),
        new Main_Action_Command(&transport_robot));

    while (center.handleInput())
    {
        std::cout << "...........TRANSPORT.ROBOT...........\n";
    }



    return 0;
}














