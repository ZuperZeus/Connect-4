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

#ifndef BOARD_FRAME_H
#define BOARD_FRAME_H
#include <iostream>
#include <vector>
#include "Frame.h"
#include "Board.h"
using namespace std;
class BoardFrame : public Frame
{
	private:
		vector< vector<int> > board;		//0=empty; 1=p1; 2=p2; 3=frame; 4=selected; 5=win
		string player1Color;
		string player2Color;
		string defaultColor;
		string frameColor;
		string selectedColor;
		string winColor;
		string reset;
		bool winbool;
		bool aiActive;
		int aidiff;
		vector<int>xwin;
		vector<int>ywin;
		void updateFrame();
		void getFrame(vector< vector<int> > boardPieces);
		void saveGameToTemp();
		void printAnimationFrame();
	public:
		string moves;
		Board boardBackend;	//(7,vector<int>(6,0)); //0=empty; 1=p1; 2=p2
		int currplay;
		BoardFrame(string p1, string p2, string fcol, string selcol, string wincol, Board bpieces, bool ai, int cplay, int diff, string mv);
		~BoardFrame()=default;
		void move(int x);
		Frame * esc();
		Frame * select();
		void win(vector< vector<int> > winvec);
		void printFrame();
};
#endif
