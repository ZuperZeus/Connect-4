#ifndef FRAME_H
#define FRAME_H
#include <iostream>
#include <vector>
using namespace std;
class Frame
{
	private:
		int rows;
		int cols;
		virtual void updateFrame();
		virtual string center(int size);
	public:
		virtual ~Frame();
		virtual void move(int x); //1=up;2=down;3=left;4=right;5=select;6=esc
		virtual void sel();
		//virtual Frame esc();
		virtual void printFrame(int col, int row);
};
#endif
