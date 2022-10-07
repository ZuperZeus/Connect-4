#include <iostream>
#include "Frame.h"
using namespace std;
void Frame::newBuffer()
{
	cout<<"\e[?1049h";
}
void Frame::upperLeft()
{
	cout<<"\e[;H";    
}
void Frame::delBuffer()
{
	cout<<"\e[?1049l";
}
void Frame::clear()
{
	upperLeft();
	cout<<"\r";
	for(int i=0;i<rows*cols;i++)
		cout<<" ";
	upperLeft();
}
