#include <iostream>
#include <vector>
#include "BoardFrame.h"
#include "SettingsFrame.h"
#include "Board.h"
using namespace std;
BoardFrame::BoardFrame(string p1, string p2, string fcol, string selcol, string wincol, string def, Board bpieces)
{
	rows=0;
	cols=0;
	player1Color=p1;
	player2Color=p2;
	defaultColor=def;
	frameColor=fcol;
	selectedColor=selcol;
	winColor=wincol;
	reset="\e[0m";
	boardBackend=bpieces;
	selected=-1;
	winbool=false;
	currplay=1;
}
void BoardFrame::move(int x)
{
	//TODO: add animation
	if(x==3)
	{
		if(selected<=0)
			selected=6;
		else
			selected--;
	}
	else if(x==4)
	{
		if(selected>=6)
			selected=0;
		else
			selected ++;
	}
	else if(x==5||x==2)
	{
		if(selected!=-1)
		{
			boardBackend.drop(selected,currplay);
			currplay=3-currplay;
			selected=-1;
		}
	}
}
Frame BoardFrame::esc()
{
	SettingsFrame sf;
	return sf;
}
void BoardFrame::updateFrame()
{
	vector< vector<int> > boardPieces=boardBackend.getBoard();
	int columnLength=cols-2-(cols-2)%7;
	int rowLength=rows-1-(rows-1)%6;
	columnLength-=columnLength%2;
	if(columnLength>2*rowLength)
		columnLength=((rowLength/6))*14;
	else
		rowLength=((columnLength/14))*6;
	board.resize(rowLength+1);
	for(int i=0;i<=rowLength;i++)
		board[i].resize(columnLength+2);

	for(int i=0;i<=7;i++)
		for(int j=0;j<=rowLength;j++)
		{
			board[j][i*columnLength/7]=3;
			board[j][i*columnLength/7+1]=3;
		}

	for(int i=0;i<=6;i++)
		for(int j=0;j<=columnLength;j++)
			board[i*rowLength/6][j]=3;

	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
			for(int a=i*rowLength/6+1;a<(i+1)*rowLength/6;a++)
				for(int b=j*columnLength/7+2;b<(j+1)*columnLength/7;b++)
					board[a][b]=boardPieces[j][i];
	if(winbool)
	{
		for(int a=0;a<xwin.size();a++)
		{
			for(int i=xwin[a]*columnLength/7;i<(xwin[a]+1)*columnLength/7+2;i++)
			{
				board[ywin[a]*rowLength/6][i]=5;
				board[ywin[a]*rowLength/6+rowLength/6][i]=5;
			}
			for(int i=ywin[a]*rowLength/6;i<(ywin[a]+1)*rowLength/6+1;i++)
			{
				board[i][xwin[a]*rowLength/3]=5;
				board[i][xwin[a]*rowLength/3+1]=5;
				board[i][xwin[a]*rowLength/3+2*rowLength/6]=5;
				board[i][xwin[a]*rowLength/3+2*rowLength/6+1]=5;
			}
		}
	}
	else if(selected!=-1)
	{
		for(int i=0;i<rowLength+1;i++)
		{
			board[i][selected*columnLength/7]=4;
			board[i][selected*columnLength/7+1]=4;
			board[i][(selected+1)*columnLength/7]=4;
			board[i][(selected+1)*columnLength/7+1]=4;
		}
		for(int i=selected*columnLength/7;i<(selected+1)*columnLength/7;i++)
			for(int j=0;j<=6;j++)
				board[j*rowLength/6][i]=4;
	}
}
string BoardFrame::center(int size)
{
	string res="";
	for(int i=0;i<(cols-size)/2;i++) res+=" ";
	return res;
}
void BoardFrame::win(vector< vector<int> > winvec)
{
	winbool=true;
	xwin=winvec[0];
	ywin=winvec[1];
}
void BoardFrame::printFrame(int col, int row)
{
	vector< vector<int> > boardPieces=boardBackend.getBoard();
	if(cols!=col||rows!=row)
	{
		cols=col;
		rows=row;
	}
	this->clear();
	updateFrame();
	string cen=center(board[0].size());
	for(int i=0;i<board.size();i++)
	{
		cout<<cen;
		for(int j=0;j<board[i].size();j++)
		{
			Frame::upperLeft;
			if(board[i][j]==0) cout<<defaultColor<<" "<<reset;
			else if(board[i][j]==1) cout<<player1Color<<" "<<reset;
			else if(board[i][j]==2) cout<<player2Color<<" "<<reset;
			else if(board[i][j]==3) cout<<frameColor<<" "<<reset;
			else if(board[i][j]==4) cout<<selectedColor<<" "<<reset;
			else if(board[i][j]==5) cout<<winColor<<" "<<reset;
		}
		cout<<endl;
	}
}
