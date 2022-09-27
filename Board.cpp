#include <iostream>
#include <vector>
#include "Board.h"
using namespace std;
Board::Board()
{
	board.resize(6);
	for(int i=0;i<6;i++)
	{
		board[i].resize(7);
		for(int j=0;j<7;j++)
		{
			boardArr[i][j]=0;
			board[i][j]=0;
		}
	}
}
Board::Board(vector< vector<int> > arr)
{
	board=arr;
	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
			board[i][j]=arr[i][j];
}
bool Board::drop(int sel, int player)
{
	int cont=0;
	while(cont<6&&board[cont][sel]==0) cont++;
	cont--;
	if(cont==-1) return false;
	else board[cont][sel]=player;
	return true;
}
bool Board::canDrop(int sel)
{
	return board[0][sel]==0;
}
int Board::checkWin()
{
	vector< vector<int> > arr=getWin();
	if(arr[0].size()==0)
		return 0;
	else
		return board[arr[1][0]][arr[0][0]];
}
int Board::getInmWin(int team)
{
	int inmwincont1=0;
	int inmwincont2=0;
	int cont1=0;
	int cont2=0;
	//int disc=0;
	//vertical
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<7;j++)
		{
			if(board[i][j]==1)
			{
				cont1++;
				cont2=0;
			}
			else if(board[i][j]==2)
			{
				cont2++;
				cont1=0;
			}
			else
			{
				//if(disc==0)
				//	disc++;
			//	else if(disc==2)
				{
			//		disc=0;
					cont1=0;
					cont2=0;
				}
			}
			//if(disc==1)
			if(cont1==4)
			{
				cont1=0;
				inmwincont1++;
			}
			else if(cont2==4)
			{
				cont2=0;
				inmwincont2++;
			}
		}
		//disc=0;
		cont1=0;
		cont2=0;
	}
	//horizontal
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(board[j][i]==1)
			{
				cont1++;
				cont2=0;
			}
			else if(board[j][i]==2)
			{
				cont2++;
				cont1=0;
			}
			else
			{
				//if(disc==0)
				//	disc++;
				//else if(disc==2)
				{
				//	disc=0;
					cont1=0;
					cont2=0;
				}
			}
			//if(disc==1)
			if(cont1==4)
			{
				cont1=0;
				inmwincont1++;
			}
			else if(cont2==4)
			{
				cont2=0;
				inmwincont2++;
			}
		}
		//disc=0;
		cont1=0;
		cont2=0;
	}
	//ldia
	for(int i=3;i<9;i++)
	{
		int j=0;
		while(j<6&&i-j<7)
		{
			if(board[j][i-j]==1)
			{
				cont1++;
				cont2=0;
			}
			else if(board[j][i-j]==2)
			{
				cont2++;
				cont1=0;
			}
			else
			{
				//if(disc==0)
				//	disc++;
				//else if(disc==2)
				{
				//	disc=0;
					cont1=0;
					cont2=0;
				}
			}
			//if(disc==1)
			if(cont1==4)
			{
				cont1=0;
				inmwincont1++;
			}
			else if(cont2==4)
			{
				cont2=0;
				inmwincont2++;
			}
			j++;
		}
		//disc=0;
		cont1=0;
		cont2=0;
	}
	//rdia
	for(int i=-2;i<=3;i++)
	{
		int j=0;
		while(i+j<=6&&j<5)
		{
			if(board[j][i+j]==1)
			{
				cont1++;
				cont2=0;
			}
			else if(board[j][i+j]==2)
			{
				cont2++;
				cont1=0;
			}
			else
			{
		//		if(disc==0)
		//			disc++;
		//		else if(disc==2)
				{
		//			disc=0;
					cont1=0;
					cont2=0;
				}
			}
		//	if(disc==1)
			if(cont1==4)
			{
				cont1=0;
				inmwincont1++;
			}
			else if(cont2==4)
			{
				cont2=0;
				inmwincont2++;
			}
			j++;
		}
		//disc=0;
		cont1=0;
		cont2=0;
	}
	if(team==1)
		return (inmwincont1-inmwincont2);
	else
		return (inmwincont2-inmwincont1);
}
//returns 2xn array with win conditions
vector< vector<int> > Board::getWin()
{
	vector< vector<int> > winvec(2,vector<int>(0));
	int cont1=0;
	int cont2=0;
	//vertical
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<7;j++)
		{
			if(board[i][j]==1)
			{
				if(cont2>=4) return winvec;
				winvec[0].push_back(j);
				winvec[1].push_back(i);
				cont1++;
				cont2=0;
			}
			else if(board[i][j]==2)
			{
				if(cont1>=4) return winvec;
				winvec[0].push_back(j);
				winvec[1].push_back(i);
				cont2++;
				cont1=0;
			}
			else
			{
				if(cont1>=4||cont2>=4) return winvec;
				winvec[0].resize(0);
				winvec[1].resize(0);
				cont1=0;
				cont2=0;
			}
		}
		if(cont1>=4||cont2>=4) return winvec;
		winvec[0].resize(0);
		winvec[1].resize(0);
		cont1=0;
		cont2=0;
	}
	//horizontal
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(board[j][i]==1)
			{
				if(cont2>=4) return winvec;
				winvec[0].push_back(i);
				winvec[1].push_back(j);
				cont1++;
				cont2=0;
			}
			else if(board[j][i]==2)
			{
				if(cont1>=4) return winvec;
				winvec[0].push_back(i);
				winvec[1].push_back(j);
				cont2++;
				cont1=0;
			}
			else
			{
				if(cont1>=4||cont2>=4) return winvec;
				winvec[0].resize(0);
				winvec[1].resize(0);
				cont1=0;
				cont2=0;
			}
		}
		if(cont1>=4||cont2>=4) return winvec;
		winvec[0].resize(0);
		winvec[1].resize(0);
		cont1=0;
		cont2=0;
	}
	//ldia
	for(int i=3;i<9;i++)
	{
		int j=0;
		while(j<6&&i-j<7)
		{
			if(board[j][i-j]==1)
			{
				if(cont2>=4) return winvec;
				winvec[0].push_back(i-j);
				winvec[1].push_back(j);
				cont1++;
				cont2=0;
			}
			else if(board[j][i-j]==2)
			{
				if(cont1>=4) return winvec;
				winvec[0].push_back(i-j);
				winvec[1].push_back(j);
				cont2++;
				cont1=0;
			}
			else
			{
				if(cont1>=4||cont2>=4) return winvec;
				winvec[0].resize(0);
				winvec[1].resize(0);
				cont1=0;
				cont2=0;
			}
			j++;
		}
		if(cont1>=4||cont2>=4) return winvec;
		winvec[0].resize(0);
		winvec[1].resize(0);
		cont1=0;
		cont2=0;
	}
	//rdia
	for(int i=-2;i<=3;i++)
	{
		int j=0;
		while(i+j<=6&&j<5)
		{
			if(board[j][i+j]==1)
			{
				if(cont2>=4) return winvec;
				winvec[0].push_back(i+j);
				winvec[1].push_back(j);
				cont1++;
				cont2=0;
			}
			else if(board[j][i+j]==2)
			{
				if(cont1>=4) return winvec;
				winvec[0].push_back(i+j);
				winvec[1].push_back(j);
				cont2++;
				cont1=0;
			}
			else
			{
				if(cont1>=4||cont2>=4) return winvec;
				winvec[0].resize(0);
				winvec[1].resize(0);
				cont1=0;
				cont2=0;
			}
			j++;
		}
		if(cont1>=4||cont2>=4) return winvec;
		winvec[0].resize(0);
		winvec[1].resize(0);
		cont1=0;
		cont2=0;
	}
	return winvec;
}
vector< vector<int> > Board::getBoard()
{
	return board;
}
