#include <iostream>
#include <vector>
#include "libs/Board.h"
using namespace std;
void print(Board x)
{
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<7;j++)
		{
			int t=x.getBoard()[i][j];
			if(t==0)
				cout<<"\e[104m - \e[0m";
			else if(t==1)
				cout<<"\e[101m - \e[0m";
			else if(t==2)
				cout<<"\e[103m - \e[0m";
		}
		cout<<endl;
	}
	cout<<"-------------\n";
}
int mmh(Board b, int x, int ai, bool y, int depth)
{
	Board temp=b;
	if(y) temp.drop(x,ai);
	else temp.drop(x,3-ai);
	int e=temp.eval(ai);
	int win=temp.checkWin();
	if(win==ai||win==3-ai)
		return e;
	if(depth<=0)
		return e;
	else
	{
		int sum=0;
		for(int i=0;i<7;i++) if(temp.canDrop(i)) sum+=mmh(temp,i,ai,!y,depth-1);
		return sum;
	}
	return 0;
}
int minmax(Board b, int ai,int depth)
{
	int x=0;
	int s=3;
	for(int i=0;i<7;i++)
	{
		int y=mmh(b,i,ai,true,depth);
		if(y>x)
		{
			x=y;
			s=i;
		}
	}
	return s;
}
int main()
{
	Board a;
	while(a.checkWin()==0)
	{
		int x;
		int mm=minmax(a,1,4);
		a.drop(mm,1);
		if(a.checkWin()==0)
		{
			cout<<"Enter a number (1-7), this is the board: \n";
			print(a);
			cout<<"Evaluation function for current game: "<<a.eval(1)<<endl;
			cin>>x;
			a.drop(x-1,2);
		}

	}
	print(a);
	cout<<3-a.checkWin()<<" WON!!!\n";
}

