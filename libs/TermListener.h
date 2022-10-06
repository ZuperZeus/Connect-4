#ifndef TERM_LISTENER_H
#define TERM_LISTENER_H
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;
class TermListener
{
	private:
		struct winsize size;
		pair<int,int> sizepair;
	public:
		TermListener();
		pair<int,int> getSize();
};
#endif
