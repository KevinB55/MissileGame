// Kevin Byrne C00219049
// 21/09/2017
// Time taken : 3 hours
// Text based missile game

#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int selection = 0;
int expLaunchCode = 8403;
int nucLaunchCode = 472467;
int userLaunchCode = 0;

typedef struct Position
{
	int x;
	int y;

	void print()
	{
		cout << x << y << endl;
	}
}Coordinates;

enum WarHead { EXPLOSIVE, NUCLEAR };

typedef struct Enemy {
	Coordinates coordinates;
}Target;

struct Missile {
	WarHead payload;

	Coordinates coordinates;

	Target target;

	bool armed;

	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}

	void update()
	{
		coordinates.x += 1;
		coordinates.y += 2;
	}
};

int main()
{
	srand(time(NULL));

	cout << "1. Select warhead" << endl;
	cout << "2. Acquire target" << endl;
	cout << "3. Input launch code" << endl;
	cout << "4. Launch missile" << endl;
	
	system("PAUSE");
	system("CLS");
	

	cout << "Select a warhead - " << endl;
	cout << "1. Explosive" << endl;
	cout << "2. Nuclear" << endl;
	cin >> selection;

	WarHead payload;

	while (selection < 1 || selection > 2)
	{
		cout << "Select a warhead - " << endl;
		cout << "1. Explosive" << endl;
		cout << "2. Nuclear" << endl;
		cin >> selection;
	}

	if (selection == 1)
	{
		payload = EXPLOSIVE;
		cout << "You have chosen the Explosive warhead" << endl;
	}
	if (selection == 2)
	{
		payload = NUCLEAR;
		cout << "You have chosen the Nuclear warhead" << endl;
	}

	system("PAUSE");
	system("CLS");

	selection = 0;
	cout << "Please choose a target" << endl << endl;
	cout << "1 = Large, slow moving Air-to-air missile" << endl;
	cout << "2 = Small, fast moving Ballistic missile" << endl;
	cin >> selection;

	while (selection < 1 || selection > 2)
	{
		cout << "Please choose a target" << endl << endl;
		cout << "1 = Large, slow moving Air-to-air missile" << endl;
		cout << "2 = Small, fast moving Ballistic missile" << endl;
		cin >> selection;
	}

	if (selection == 1)
	{
		cout << "You have chosen the large, slow target" << endl;
	}
	else if (selection == 2)
	{
		cout << "You have chosen the small, quick target" << endl;
	}

	system("PAUSE");
	system("CLS");

	if (payload == EXPLOSIVE)
	{
		cout << "Launch code = 8403" << endl;
	}
	
	if (payload == NUCLEAR)
	{
		cout << "Launch code = 472467" << endl;
	}

	system("PAUSE");
	system("CLS");

	cout << "Please input launch code" << endl;
	cin >> userLaunchCode;

	if (payload == EXPLOSIVE)
	{
		if (userLaunchCode == expLaunchCode)
		{
			cout << "Access granted!" << endl;
		}
		if (userLaunchCode != expLaunchCode)
		{
			cout << "Access denied! Aborting mission..." << endl;
			system("PAUSE");
			return 1;
		}
	}

	if (payload == NUCLEAR)
	{
		if (userLaunchCode == nucLaunchCode)
		{
			cout << "Access granted!" << endl;
		}
		if (userLaunchCode != nucLaunchCode)
		{
			cout << "Access denied! Aborting mission..." << endl;
			system("PAUSE");
			return 1;
		}
	}

	system("PAUSE");
	system("CLS");
	cout << "Press ENTER to fire missile" << endl;
	system("PAUSE");

	int missileX = rand() % 3 + 1;
	int missileY = 4;

	int enemyX = rand() % 3 + 1;
	int enemyY = 0;

	bool collision = false;
	bool viable = true;

	int timer = 0;
	while (timer < 60 && viable == true)
	{
		timer++;
		if (timer== 60)
		{
			enemyY++;
			missileY--;
			timer = 0;
		}

		if (missileX == enemyX && missileY == enemyY)
		{
			collision = true;
		}

		if (missileY < 0 || collision == true)
		{
			viable = false;
		}
	}
	
	system("CLS");

	if (collision == true)
	{
		cout << "You have succesfully destroyed the missile!" << endl;
	}

	if (collision == false)
	{
		cout << "You missed the missile!" << endl;
	}

	system("PAUSE");

};
