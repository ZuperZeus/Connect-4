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

#ifndef FRAME_H
#define FRAME_H
#include <iostream>
#include <vector>
using namespace std;
//printf "\e[?1049h\e[;Hhello world"; sleep 1; printf "\e[?1049l"
//         ^enter  ^ go to                               ^exit
//         alt        top                                 alt
//         buffer     left                                buffer
class Frame
{
	private:
		int rows;
		int cols;
		virtual void updateFrame(){};
		virtual string center(int size){return "";};
	public:
		static void newBuffer();
		static void upperLeft();
		static void delBuffer();
		void clear();
		~Frame()=default;
		virtual void move(int x){}; //1=up;2=down;3=left;4=right;5=select;6=esc
		virtual Frame esc(){return *this;};
		virtual void printFrame(int col, int row){cout<<"running this";};
		void printFrame(){printFrame(cols,rows);};
};
#endif
