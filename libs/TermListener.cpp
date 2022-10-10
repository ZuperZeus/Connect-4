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
