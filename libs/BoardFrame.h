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
		int rows;
		int cols;
		vector< vector<int> > board;		//0=empty; 1=p1; 2=p2; 3=frame; 4=selected; 5=win
		Board boardBackend;	//(7,vector<int>(6,0)); //0=empty; 1=p1; 2=p2
		string player1Color;
		string player2Color;
		string defaultColor;
		string frameColor;
		string selectedColor;
		string winColor;
		string reset;
		int selected;
		bool winbool;
		vector<int>xwin;
		vector<int>ywin;
		void updateFrame();
		string center(int size);
	public:
		int currplay;
		BoardFrame(string p1, string p2, string fcol, string selcol, string wincol, string def, Board bpieces);
		~BoardFrame()=default;
		void move(int x);
		Frame esc();
		void win(vector< vector<int> > winvec);
		void printFrame(int columns, int rows);
};
#endif
