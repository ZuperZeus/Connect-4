#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include "libs/BoardFrame.h"
#include "libs/SettingsFrame.h"
#include "libs/Frame.h"
#include "libs/Board.h"
#include "libs/ActionListener.h"
using namespace std;
int main()
{
	system("tput civis");
	Board bp;
	BoardFrame b("\e[101m","\e[103m","\e[44m","\e[104m","\e[102m","",bp);
	Frame::newBuffer();
	Frame::upperLeft();
	b.printFrame(56,133);
	system("sleep 1");
	Frame::delBuffer();
	system("tput cvvis");
}

