#ifndef ACTION_LISTENER_H
#define ACTION_LISTENER_H
#include <iostream>
#include <termios.h>
#define STDIN_FILENO 0
using namespace std;
class ActionListener
{
	private:
		// Black magic to prevent Linux from buffering keystrokes.
		struct termios t;
		char x;
		string clear="\r                 \r";
	public:
		ActionListener();
		int getKey();
};
#endif
