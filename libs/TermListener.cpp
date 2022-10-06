#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include "TermListener.h"
using namespace std;
TermListener::TermListener()
{
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
}
pair<int,int> TermListener::getSize()
{
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	if(sizepair.first!=size.ws_col||sizepair.second!=size.ws_row)
	{
		sizepair.first=size.ws_col;
		sizepair.second=size.ws_row;
	}
	return sizepair;
}
