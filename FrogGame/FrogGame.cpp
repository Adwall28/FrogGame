// FrogGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool GameOver;
bool MenuChoiceMade;
const int width = 40;
const int height = 20;
int x, y, Score, Lives;
int TongueX[100], TongueY[100];
int TongueLength;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;
string FrogTongueTip = "O";
string FrogTongue = "M";
string LivesImage;
string Option;

class Flies { //Made a class for the Flies and junk to be able to make multiple
	public:
		int FlyX;
		int FlyY;
};

class Junk {
	public:
		int JunkX;
		int JunkY;
};

Flies Fly1;
Flies Fly2;
Flies Fly3;
Flies Fly4;
Flies Fly5;

Junk Junk1;
Junk Junk2;

void Start() //This is the first thing shown to the user, which shows a small menu along with the title
{
	cout << R"(        
_____ ____  ____  _____ ________  _
/  __//  __\/  _ \/  __//  __/\  \//
|  __\|  \/|| / \|| |  _| |  _ \  / 
| |   |    /| \_/|| |_//| |_// / /  
\_/   \_/\_\\____/\____\\____\/_/                                   
		)" << '\n';
	Sleep(10);
	cout << "| Start (s) |    | How To Play (h)| " << endl;
	cout << "    Please type an option here... "; 
	cin >> Option;
}

void HowToPlay() //I made a how to play so that the user can learn how to play
{
	cout << "The rules are simple:" << endl;
	cout << "Catch all the flies (%) you can" << endl;
	cout << "But beware of all the junk (@) flying around" << endl;
	cout << "Try and get the highest score possible" << endl;
	cout << "But be careful as junk is poisonous and you only have 3 lives..." << endl;
	cout << "When playing, press x at any time to exit!";
	Sleep(500);
	int main();
}


void Setup()
{
	GameOver = false;
	dir = STOP;
	x = width / 2;
	y = height - 1;

	
	Fly1.FlyX = 1;
	Fly1.FlyY = rand() % height;
	Fly2.FlyX = 1;
	Fly2.FlyY = rand() % height;
	Fly3.FlyX = width-1;
	Fly3.FlyY = rand() % height;
	Fly4.FlyX = width - 1;
	Fly4.FlyY = rand() % height;
	Fly5.FlyX = width - 1;
	Fly5.FlyY = rand() % height;


	Junk1.JunkX = 1;
	Junk1.JunkY = rand() % height;
	Junk2.JunkX = width-1;
	Junk2.JunkY = rand() % height;
	Score = 0;
	Lives = 3;
}

void Draw()
{

	system("cls");

	cout << "                 FROGGY" << endl;
	for (int i = 0; i < width +2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{

			if (j == 0)
			{
				cout << "#";
			}

			if (i == y && j == x)
			{
				cout << FrogTongueTip;
			}
			else if (i==Fly1.FlyY && j == Fly1.FlyX)
			{
				cout << "%";
			}
			else if (i == Fly2.FlyY && j == Fly2.FlyX)
			{
				cout << "%";
			}
			else if (i == Fly3.FlyY && j == Fly3.FlyX)
			{
				cout << "%";
			}
			else if (i == Fly4.FlyY && j == Fly4.FlyX)
			{
				cout << "%";
			}
			else if (i == Fly5.FlyY && j == Fly5.FlyX)
			{
				cout << "%";
			}

			else if (i == Junk1.JunkY && j == Junk1.JunkX)
			{
				cout << "@";
			}

			else if (i == Junk2.JunkY && j == Junk2.JunkX)
			{
				cout << "@";
			}
			else
			{
				bool print = false;
				for (int k = 0; k < TongueLength; k++)
				{	

					if (TongueX[k] == j && TongueY[k] == i)
					{
						cout << FrogTongue;
						print = true;
					}
					
				}
				if (!print)
					cout << " ";
			}

			if (j == width - 1)
			{
				cout << "#";
			}

			if (i == height-1 && j == 20) {
				cout << "";
			}

		}

		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
	{
	cout << "#";
	}
	cout << endl;

/*	cout << R"(
   ###   ###
  # ^ #-# ^ #			   
   ##########			   
   \#<--->#/			   
 #/#########\#    		   
##\####@####/##			   	
 ####v###v#### 			  
  #vv#	 #vv#
)";
*/


	cout << "                   -----" << endl;
	cout << "                ^ / ^  ^ \\^" << endl;
	cout << "                ||   vv   ||" << endl;
	cout << "    Score: " << Score << endl;
	cout << "    Lives: " << LivesImage << endl;
}

void Input()
{
	if (_kbhit())
	{
		switch(_getch())
		{
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				GameOver = true;
				break;
		}
	}
}


void Movement()
{
	Fly1.FlyX++;
	Fly2.FlyX++;
	Fly3.FlyX--;
	Fly4.FlyX--;
	Fly5.FlyX--;
	Junk1.JunkX--;
	Junk2.JunkX++;
}

void Logic() 
{

	int PreviousX = TongueX[0];
	int PreviousY = TongueY[0];
	int Previous2X, Previous2Y;
	TongueX[0] = x;
	TongueY[0] = y;

	for (int i = 1; i < TongueLength; i++)
	{
		Previous2X = TongueX[i];
		Previous2Y = TongueY[i];
		TongueX[i] = PreviousX;
		TongueY[i] = PreviousY;
		PreviousX = Previous2X;
		PreviousY = Previous2Y;
	}

	//This switch allows the player to move the tongue tip.
	// I have added Sleep functions to make it not go as fast.

	switch (dir)
	{
	case LEFT:
		x--;
		Sleep(20);
		if (x < 20) {
			TongueLength++;
		}
		else {
			TongueLength--;
		}
		break;
	case RIGHT:
		x++;
		Sleep(20);
		if (x > 20) {
			TongueLength++;
		}
		else {
			TongueLength--;
		}
		break;
	case UP:
		y--;
		Sleep(40);
		if (y < height-1) {
			TongueLength++;
		}
		else {
			TongueLength--;
		}
		break;
	case DOWN:
		y++;
		Sleep(40);
		if (y > height-1) {
			TongueLength++;
		}
		else {
			TongueLength--;
		}
		break;
	default:
		break;
	}

	// These if statements are there to make sure that when you hit the border of the map,
	// then you will be stopped.

	if (x > width - 1) {
		x = 0; //When the tip reaches touches the right border, it will go back to the left border
	}
	else if (x < 0) {
		x = width - 1; //When the tip touches the left border, it will go back to the right border
	}
	else if (y > height - 1) {
		y = height - 1; //When the tip touches the bottom border, it will stay at the bottom
	}
	else if (y < 0) {
		y = 1 ; //When the tip touches the top border, it will stay at the bottom
		TongueLength = height;
	}

	if (TongueLength < 0) {
		TongueLength = 0;
	}

	if (x == width / 2 && y == height - 1) {
		TongueLength = 0;
	}

	Movement();

	if (Fly1.FlyX == width-1) {
		Fly1.FlyX = 1;
		Fly1.FlyY = rand() % height;
	}
	if (Fly2.FlyX == width-1) {
		Fly2.FlyX = 1;
		Fly2.FlyY = rand() % height;
	}
	if (Fly3.FlyX == 0) {
		Fly3.FlyX= width-1;
		Fly3.FlyY = rand() % height;
	}
	if (Fly4.FlyX == 0) {
		Fly4.FlyX = width-1;
		Fly4.FlyY = rand() % height;
	}

	if (Fly5.FlyX == 0) {
		Fly5.FlyX = width - 1;
		Fly5.FlyY = rand() % height;
	}

	if (Junk1.JunkX == 0) {
		Junk1.JunkX = width-1;
		Junk1.JunkY = rand() % height;
	}

	if (Junk2.JunkX == 0) {
		Junk2.JunkX = 1;
		Junk2.JunkY = rand() % height;
	}

	if (x == Fly1.FlyX && y == Fly1.FlyY)
	{
		Score += 1;
		Fly1.FlyX = 1;
		Fly1.FlyY = rand() % height;
		x = width / 2;
		y = height - 1;	
	}

	if (x == Fly2.FlyX && y == Fly2.FlyY)
	{
		Score += 1;
		Fly2.FlyX = 1;
		Fly2.FlyY = rand() % height;
		x = width / 2;
		y = height - 1;
	}

	if (x == Fly3.FlyX && y == Fly3.FlyY)
	{
		Score += 1;
		Fly3.FlyX = 1;
		Fly3.FlyY = rand() % height;
		x = width / 2;
		y = height - 1;
	}

	if (x == Fly4.FlyX && y == Fly4.FlyY)
	{
		Score += 1;
		Fly4.FlyX = 1;
		Fly4.FlyY = rand() % height;
		x = width / 2;
		y = height - 1;
	}

	if (x == Fly5.FlyX && y == Fly5.FlyY)
	{
		Score += 1;
		Fly5.FlyX = 1;
		Fly5.FlyY = rand() % height;
		x = width / 2;
		y = height - 1;
	}

	if (x == Junk1.JunkX && y == Junk1.JunkY)
	{
		Lives = Lives - 1;
		Junk1.JunkX = width - 1;
		Junk1.JunkY = rand() % height;
		x = width / 2;
		y = height - 1;
	}

	if (x == Junk2.JunkX && y == Junk2.JunkY)
		{
		Lives = Lives - 1;
		Junk2.JunkX = 1;
		Junk2.JunkY = rand() % height;
		x = width / 2;
		y = height - 1;
	}

	if (Lives == 3) {
		LivesImage = "***";
	}
	else if (Lives == 2) {
		LivesImage = "**";

	}
	else if (Lives == 1) {
		LivesImage = "*";
	}
	else if (Lives == 0)
	{
		LivesImage = " ";
		GameOver = true;
	}
}

int main()
{
	HANDLE console_color;
	console_color = GetStdHandle(
		STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(
		console_color, 2);

	MenuChoiceMade = false;

	while (MenuChoiceMade == false) {
		Start();
		if (Option == "s") {

			HANDLE console_color;
			console_color = GetStdHandle(
				STD_OUTPUT_HANDLE);

			SetConsoleTextAttribute(
				console_color, 32);

			MenuChoiceMade = true;
			Setup();
			while (!GameOver)
			{
				Draw();
				Input();
				Logic();
				Sleep(5);
			}
		}
		else if (Option == "h") {
			MenuChoiceMade = false;
			HowToPlay();
		}
		else {
			cout << "Please type that again!";
			MenuChoiceMade = false;
		}
	}
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
