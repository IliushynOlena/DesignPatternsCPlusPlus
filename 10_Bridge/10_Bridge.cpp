#include <iostream>
using namespace std;

// abstract
class WallCreator
{
public:
	virtual void BuildWall() = 0;
	virtual void BuildWallWithDoor() = 0;
	virtual void BuildWallWithWindow() = 0;
	virtual void BuildGrage() = 0;
};

// abstract
class Company
{
protected:
	WallCreator* _wallCreator; // imp
public:
	/*Company(WallCreator* wallCreator)
	{
		_wallCreator = wallCreator;
	}*/
	void SetWallCreator(WallCreator* wallCreator)
	{
		_wallCreator = wallCreator;
	}
	virtual void BuildFoundation() = 0;
	virtual void BuildRoom() = 0;
	virtual void BuildRoof() = 0;
};

class BuldingCompany : public Company
{
public:
	void BuildFoundation()
	{
		cout << "Foundation is built.\n";
	}
	void BuildRoom()
	{
		_wallCreator->BuildWallWithDoor();
		_wallCreator->BuildWall();
		_wallCreator->BuildWallWithWindow();
		_wallCreator->BuildWall();

		cout << "Room finished.\n";
		//WallCreator.BuildGrage();

	}
	void BuildRoof()
	{
		cout << "Roof is done.\n";
	}
};

class BrickWallCreator : public WallCreator
{
public:
	void BuildGrage() override
	{
		cout << "Brick garage created!\n";
	}

	void BuildWall()override
	{
		cout << "Brick wall created!\n";
	}

	void BuildWallWithDoor()override
	{
		cout << "Brick wall with door created!\n";
	}

	void BuildWallWithWindow()override
	{
		cout << "Brick wall with window created!\n";
	}
};

class ConcreteSlabWallCreator : public WallCreator
{
public:
	void BuildGrage()override
	{
		cout << "Concrete garage created!\n";
	}

	void BuildWall()override
	{
		cout << "Concrete wall created!\n";
	}

	void BuildWallWithDoor()override
	{
		cout << "Concrete wall with door created!\n";
	}

	void BuildWallWithWindow()override
	{
		cout << "Concrete wall with window created!\n";
	}
};

class WoodenWallCreator : public WallCreator
{
public:
	void BuildGrage()
	{
		cout << "Wooden garage created!\n";
	}

	void BuildWall()
	{
		cout << "Wooden wall created!\n";
	}

	void BuildWallWithDoor()
	{
		cout << "Wooden wall with door created!\n";
	}

	void BuildWallWithWindow()
	{
		cout << "Wooden wall with window created!\n";
	}
};

void main()
{
	BuldingCompany buildingCompany = BuldingCompany();
	buildingCompany.BuildFoundation();
	buildingCompany.SetWallCreator(new BrickWallCreator());
	buildingCompany.BuildRoom();
	buildingCompany.SetWallCreator(new ConcreteSlabWallCreator());
	buildingCompany.BuildRoom();
	buildingCompany.SetWallCreator(new WoodenWallCreator());
	buildingCompany.BuildRoom();
	buildingCompany.BuildRoof();

	system("pause");
}