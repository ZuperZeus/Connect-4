#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include "VisualBoard.h"
using namespace std;
int main()
{
	vector< vector<int> > pieces{{0,0,0,0,0,0},{0,0,0,0,1,2},{0,0,0,0,0,0},{1,1,1,1,1,1},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
	VisualBoard vb("\e[101m \e[0m","\e[103m \e[0m"," ","\e[44m \e[0m","\e[104m \e[0m","\e[102m \e[0m",pieces);
	vb.printBoard(200,200);
	vb.select(1);
	system("sleep 0.5");
	vb.printBoard(200,200);
}

