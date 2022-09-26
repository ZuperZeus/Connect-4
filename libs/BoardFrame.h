#ifndef BOARD_FRAME_H
#define BOARD_FRAME_H
#include <iostream>
#include <vector>
#include "Frame.h"
using namespace std;
class BoardFrame : Frame
{
	private:
		int rows;
		int cols;
		vector< vector<int> > board;		//0=empty; 1=p1; 2=p2; 3=frame; 4=selected; 5=win
		vector< vector<int> > boardPieces;	//(7,vector<int>(6,0)); //0=empty; 1=p1; 2=p2
		string player1Color;
		string player2Color;
		string defaultColor;
		string frameColor;
		string selectedColor;
		string winColor;
		int selected;
		bool winbool;
		vector<int>xwin;
		vector<int>ywin;
		void updateFrame(int columns, int rows);
		string center(int columns, int size);
	public:
		BoardFrame(string p1, string p2, string fcol, string selcol, string wincol, string def, vector< vector<int> > bpieces);
		void move(int x);
		void sel();
		Frame esc();
		void win(vector<int> xwinvec, vector<int> ywinvec);
		void printFrame(int columns, int rows);
};
#endif
