#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
using namespace std;
class Board
{
	private:
		int boardArr[6][7];//0=empty; 1=p1; 2=p2
		vector< vector<int> > board;
	public:
		Board();
		Board(vector< vector<int> > arr);
		bool drop(int sel, int player);
		bool checkWin();
		vector< vector<int> > getWin();
		vector< vector<int> > getBoard();
};
#endif
