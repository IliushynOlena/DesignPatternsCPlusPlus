#include <iostream>
#include<string>
using namespace std;
class Particle
{
    pair<double, double> vector;
    double speed;
    int* sprite;
    int color;
public:
    int x;
    int y;
    Particle()
    {
        sprite = new int[5300];
        for (int i = 0; i < 5300; i++)
        {
            sprite[i] = 123;
        }
    }
    ~Particle()
    {
        delete[]sprite;
    }
};

int main()
{
    Particle* particle = new Particle[100000];
    particle[0].x = 100;
    particle[0].y = 100;

    delete[]particle;
}

/*
#include <iostream>
#include<string>
using namespace std;

class Particle
{
    int* sprite;
public:
    int color = 0;
    Particle()
    {
        sprite = new int[5300];

    }
    ~Particle()
    {
        delete[]sprite;
    }
};
class MovingParticle
{
public:
    Particle* particle;
    pair<double, double> vector;
    double speed;
    int x;
    int y;

};


int main()
{
    Particle* particle = new Particle[16];
    MovingParticle* movingParticle = new MovingParticle[100000];
    for (size_t i = 0; i < 100000; i++)
    {
        movingParticle->particle[3];
    }
    system("pause");
    delete[]particle;
    delete[]movingParticle;

}

*/
