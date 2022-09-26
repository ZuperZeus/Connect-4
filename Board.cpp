#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include "Board.h"
using namespace std;
Board::Board()
{
	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
			board[i][j]=0;
}
Board::Board(vector< vector<int> > arr)
{
	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
			board[i][j]=arr[i][j];
}
bool Board::drop(int sel, int player)
{
	int cont=0;
	while(board[cont][sel]==0) cont++;
	cont--;
	if(cont==-1) return false;
	else board[cont][sel]=player;
	return true;
}
bool Board::checkWin()
{
	vector< vector<int> > arr=getBoard();


}
vector< vector<int> > Board::getBoard()
{
	vector< vector<int> > arr(6,vector<int>(7));
	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
			arr[i][j]=board[i][j];
	return arr;
}
