#include <iostream>
#include <termios.h>
#include "KeyListener.h"
#define STDIN_FILENO 0
using namespace std;
KeyListener::KeyListener()
{
	// Black magic to prevent Linux from buffering keystrokes.
	struct termios t;
	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag &= ~ICANON;
	tcsetattr(STDIN_FILENO, TCSANOW, &t);
}
int KeyListener::getKey()
{
	int up=1;
	int down=2;
	int left=3;
	int right=4;
	int sel=5;
	int esc=6;
	cin.get(x);
	cout<<clear;
	if(x==27)
	{
		cin.get(x);
		cout<<clear;
		if(x==91)
		{
			cin.get(x);
			cout<<clear;
			if (x==65) {return up;}
			else if (x==66) {return down;}
			else if (x==67) {return right;}
			else if (x==68) {return left;}
			else
				cout<<clear;
		}
		else
				cout<<clear;
	}
	else if (x=='w') {return up;}
	else if (x=='s') {return down;}
	else if (x=='d') {return right;}
	else if (x=='a') {return left;}
	else if (x==127) {return esc;}
	else if(x=='\n')
	{
		cout<<(char)27<<(char)91<<(char)65<<clear;
		return sel;
	}
	else
	{
		cout<<clear;
	}
		return 0;
}
