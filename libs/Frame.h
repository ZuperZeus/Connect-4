#ifndef FRAME_H
#define FRAME_H
#include <iostream>
#include <vector>
using namespace std;
//printf "\e[?1049h\e[;Hhello world"; sleep 1; printf "\e[?1049l"
//         ^enter  ^ go to                               ^exit
//         alt        top                                 alt
//         buffer     left                                buffer
class Frame
{
	private:
		int rows;
		int cols;
		virtual void updateFrame(){};
		virtual string center(int size){return "";};
	public:
		static void newBuffer();
		static void upperLeft();
		static void delBuffer();
		void clear();
		~Frame()=default;
		virtual void move(int x){}; //1=up;2=down;3=left;4=right;5=select;6=esc
		virtual Frame esc(){return *this;};
		virtual void printFrame(int col, int row){cout<<"running this";};
		void printFrame(){printFrame(cols,rows);};
};
#endif
