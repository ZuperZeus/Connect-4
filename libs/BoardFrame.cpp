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
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include "BoardFrame.h"
#include "SettingsFrame.h"
#include "PauseFrame.h"
#include "Board.h"
using namespace std;
BoardFrame::BoardFrame(string p1, string p2, string fcol, string selcol, string wincol, Board bpieces, bool ai, int cplay, int diff)
{
	xSize=2;
	ySize=7;
	player1Color=p1;
	player2Color=p2;
	defaultColor="";
	frameColor=fcol;
	selectedColor=selcol;
	winColor=wincol;
	reset="\e[0m";
	boardBackend=bpieces;
	winbool=false;
	currplay=cplay;
	aiActive=ai;
	aidiff=diff;
	moves="";
}
void BoardFrame::saveGameToTemp()
{
	ofstream out;
	out.open("libs/txt/temp.txt",ios::trunc);
	out<<1<<endl;
	out<<aiActive<<endl;
	out<<currplay<<endl;
	out<<moves<<endl;
	out.close();
}
Frame * BoardFrame::esc()
{
	saveGameToTemp();
	Frame *pf=new PauseFrame();
	return pf;
}
Frame * BoardFrame::select()
{
	if(boardBackend.checkWin()==0)
	{
		if(sel.first>=0)
		{
			int column=sel.first;
			sel.first=-1;
			vector< vector<int> > bp=boardBackend.getBoard();
			for(int i=0;i<6;i++)
			{
				if(bp[column][i+1]==0)
				{
					int decsec=10000;
					bp[column][i]=3-currplay;
					getFrame(bp);
					printAnimationFrame();
					usleep((7-i)*(7-i)*decsec);
					bp[column][i]=0;
				}
			}
			currplay=3-currplay;
			boardBackend.drop(column,currplay);
			moves=moves+(char)(column+'1');
			saveGameToTemp();
			printFrame();
			/*if(boardBackend.checkWin()==0)
			if(aiActive)
			{
				//int column=boardBackend.eval(aidiff,moves);
				int column=boardBackend.eval(6,moves);
				//srand(time(NULL));
				//int column=rand()%7;
				vector< vector<int> > bp=boardBackend.getBoard();
				for(int i=0;i<6;i++)
				{
					if(bp[column][i+1]==0)
					{
						int decsec=10000;
						bp[column][i]=3-currplay;
						getFrame(bp);
						printAnimationFrame();
						usleep((7-i)*(7-i)*decsec);
						bp[column][i]=0;
					}
				}
				currplay=3-currplay;
				boardBackend.drop(column,currplay);
				moves=moves+(char)(column+'1');
				saveGameToTemp();
				printFrame();
			}*/
		}
	}
	else
	{
		remove("libs/txt/curr.cpp");
		remove("libs/txt/temp.cpp");
	}
	sel.second=0;
	return this;
}
void BoardFrame::getFrame(vector< vector<int> > boardPieces)
{
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
	else if(sel.first!=-1)
	{
		for(int i=0;i<rowLength+1;i++)
		{
			board[i][sel.first*columnLength/7]=4;
			board[i][sel.first*columnLength/7+1]=4;
			board[i][(sel.first+1)*columnLength/7]=4;
			board[i][(sel.first+1)*columnLength/7+1]=4;
		}
		for(int i=sel.first*columnLength/7;i<(sel.first+1)*columnLength/7;i++)
			for(int j=0;j<=6;j++)
				board[j*rowLength/6][i]=4;
	}
}
void BoardFrame::updateFrame()
{
	if(sel.second==1)
		select();
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
	else if(sel.first!=-1)
	{
		for(int i=0;i<rowLength+1;i++)
		{
			board[i][sel.first*columnLength/7]=4;
			board[i][sel.first*columnLength/7+1]=4;
			board[i][(sel.first+1)*columnLength/7]=4;
			board[i][(sel.first+1)*columnLength/7+1]=4;
		}
		for(int i=sel.first*columnLength/7;i<(sel.first+1)*columnLength/7;i++)
			for(int j=0;j<=6;j++)
				board[j*rowLength/6][i]=4;
	}
}
void BoardFrame::win(vector< vector<int> > winvec)
{
	winbool=true;
	xwin=winvec[0];
	ywin=winvec[1];
}
void BoardFrame::printFrame()
{
	if(boardBackend.checkWin()!=0)
		win(boardBackend.getWin());
	updateFrame();
	this->clear();
	string cen=center("",board[0].size());
	for(int i=0;i<board.size();i++)
	{
		cout<<cen;
		for(int j=0;j<board[i].size();j++)
		{
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
void BoardFrame::printAnimationFrame()
{
	this->clear();
	string cen=center("",board[0].size());
	for(int i=0;i<board.size();i++)
	{
		cout<<cen;
		for(int j=0;j<board[i].size();j++)
		{
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
