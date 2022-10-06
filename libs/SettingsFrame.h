#ifndef SETTINGS_FRAME_H
#define SETTINGS_FRAME_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Frame.h"
using namespace std;
class SettingsFrame : Frame
{
	private:
		int rows;
		int cols;
		vector<int> options;
		ifstream in;
		ofstream out;
		vector<string> indexedcolors;
		void updateFrame();
		string center(int size);
		void save();
		void change(int val, int newint);
	public:
		SettingsFrame();
		~SettingsFrame()=default;
		void move(int x);
		void sel();
		Frame esc();
		void printFrame(int col, int row);
};
#endif
