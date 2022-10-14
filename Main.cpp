/*
 *  Connect-4, a terminal GUI with a min-max AI for the classic board game of the same name.
 *  Copyright (C) 2022 ZuperZeus
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>
#include "libs/BoardFrame.h"
#include "libs/SettingsFrame.h"
#include "libs/StartFrame.h"
#include "libs/SavedFrame.h"
#include "libs/PauseFrame.h"
#include "libs/Frame.h"
#include "libs/Board.h"
#include "libs/KeyListener.h"
#include "libs/TermListener.h"
#include "libs/ExitException.h"
using namespace std;
Frame *frame;
int lastPressed;
bool returnToTerm;
void *keys(void *arg)
{
	KeyListener kl;
	while(true)
	{
		int x=kl.getKey();
		if(x!=0)
			lastPressed=x;
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
			try
			{
				if(lastPressed==6) frame=frame->esc();
				else if(lastPressed==5) frame=frame->select();
				else frame->move(lastPressed);
			}
			catch(ExitException e)
			{
				remove("libs/txt/curr.txt");
				returnToTerm=true;
				pthread_exit(NULL);
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
	returnToTerm=false;
	StartFrame st=StartFrame();
	frame = &st;
	system("tput civis");
	Frame::newBuffer();
	pthread_t key_thread;
	pthread_t term_thread;
	pthread_create(&key_thread,NULL,&keys,NULL);
	pthread_create(&term_thread,NULL,&term,NULL);
	while(!returnToTerm);
	Frame::delBuffer();
	system("tput cvvis");
}
