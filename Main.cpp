#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include "libs/BoardFrame.h"
#include "libs/SettingsFrame.h"
#include "libs/Frame.h"
#include "libs/Board.h"
#include "libs/KeyListener.h"
#include "libs/TermListener.h"
using namespace std;
Frame *frame;
int lastPressed;
int currPlayer;
bool returnToTerm;
void *keys(void *arg)
{
	KeyListener kl;
	while(true)
	{
		int x=kl.getKey();
		if(x!=0)
		{
			lastPressed=x;
			if(x==6)
				pthread_exit(NULL);
		}
	}
	pthread_exit(NULL);
}
void *term(void *arg)
{
	TermListener tl;
	pair<int,int> size;
	while(true)
	{
		if(size!=tl.getSize())
		{
			size=tl.getSize();
			frame->printFrame(size.first,size.second);
		}
		if(lastPressed!=0)
		{
			if(lastPressed==6)
			{
			//	Frame temp=frame->esc();
			//	frame=&temp;
				returnToTerm=true;
				pthread_exit(NULL);
			}
			else
			{
				frame->move(lastPressed);
			}
			lastPressed=0;
			frame->printFrame(size.first,size.second);
		}
	}
	pthread_exit(NULL);
}
int main()
{
	lastPressed=0;
	currPlayer=1;
	returnToTerm=false;
	Board bp;
	BoardFrame bf("\e[101m","\e[103m","\e[44m","\e[104m","\e[102m","",bp);
	SettingsFrame sf;
	//frame=&bf;
	frame=&sf;
	system("tput civis");
	Frame::newBuffer();
	//frame->printFrame(50,50);
	//system("sleep 5");
	pthread_t key_thread;
	pthread_t term_thread;
	pthread_create(&key_thread,NULL,&keys,NULL);
	pthread_create(&term_thread,NULL,&term,NULL);
	while(!returnToTerm){}
	Frame::delBuffer();
	system("tput cvvis");
}
