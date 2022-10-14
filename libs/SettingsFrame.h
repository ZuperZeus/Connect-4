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

#ifndef SETTINGS_FRAME_H
#define SETTINGS_FRAME_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Frame.h"
#include "BoardFrame.h"
using namespace std;
class SettingsFrame : public Frame
{
	private:
		//int rows;
		//int cols;
		vector<int> options;
		vector<string> indexedcolors;
		//int selX;
		//int selY;
		ifstream in;
		ofstream out;
		string reset;
		string framestring;
		void updateFrame();
	//	string center(int size);
	//	void change(int val, int newint);
	public:
		SettingsFrame();
		~SettingsFrame()=default;
	//	void move(int x);
		void save();
		Frame * select();
		Frame * esc();
		static BoardFrame * getCurrentBoardFrame();
		static void deleteCurrentBoardFrame();
		static BoardFrame * getTempBoardFrame();
		void printFrame();
};
#endif
