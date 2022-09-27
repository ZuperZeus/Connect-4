#include <iostream>
#include <vector>
#include "Board.h"
using namespace std;
void print(Board x)
{
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<7;j++)
		{
			cout<<x.getBoard()[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"-------------\n";
}
int mmh(Board b, int x, int ai, bool y, int depth, int cont)
{
	Board temp=b;
	if(y) temp.drop(x,ai);
	else temp.drop(x,3-ai);
	print(temp);
	int win=temp.getInmWin(ai);
	if(win>=1)
		return win;
	if(cont<=depth)
		return win;
	else
	{
		int sum=0;
		for(int i=0;i<7;i++) if(temp.canDrop(i)) sum+=mmh(temp,i,ai,!y,depth,cont+1);
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
		int y=mmh(b,i,ai,true,depth,0);
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
	a.drop(3,1);
	a.drop(1,2);
	a.drop(2,2);
	a.drop(4,2);
	a.drop(4,1);
	a.drop(0,2);
	a.drop(3,1);
	print(a);
	//for(int i=1;i<=1024;i*=2)
		cout<<"Best move with "<<8<<" precision: "<<endl<<minmax(a,1,8)<<endl;
}

