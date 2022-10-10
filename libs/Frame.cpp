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
#include "Frame.h"
using namespace std;
void Frame::newBuffer()
{
	cout<<"\e[?1049h";
}
void Frame::upperLeft()
{
	cout<<"\e[;H";    
}
void Frame::delBuffer()
{
	cout<<"\e[?1049l";
}
void Frame::clear()
{
	upperLeft();
	cout<<"\e[2J";
}
