#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
/*
 * File Structure:
 * AI difficulty (1-10)
 * player 1 string
 * player 2 string
 * frame string
 * selected frame string
 * winner color string
 * default
 */
		Settings()
		{
			options.resize(7);
			optionstr.resize(7);
			indexedcolors={"\e[101m","\e[48;5;208m","\e[103m",="\e[102m","\e[106m","\e[104m","\e[105m","\e[107m","\e[100m","\e[40m"};
			in.open("settings",ios::in);
			for(int i=0;i<7;i++) getline(in,options[i]);
			in.close();
			optionstr[0]=options[0]+1;
			for(int i=1;i<7;i++) optionstr=indexedcolors[options[i]]+" \e[0m";
		}
		void change(int val, int newint)
		{
			options[val]=newint;
		}
		void save()
		{
			out.open("settings",ios::trunc);
			for(int i=0;i<7;i++) out<<options[i]<<endl;
		}
		void center(int cols, string text)
		{
			for(int i=0;i<(cols-text.length())/2;i++) cout<<" ";
			cout<<text<<endl;
		}
		/*
		 * Menu Structure: 
		 * SETTINGS
		 * choose AI difficulty (x) move with left right arrows
		 * choose player 1 color [Red, Orange, Yellow, Green, Cyan, Blue, Magenta, White, Gray, Black]
		 * choose player 2 color [Red, Orange, Yellow, Green, Cyan, Blue, Magenta, White, Gray, Black]
		 * choose frame color [Red, Orange, Yellow, Green, Cyan, Blue, Magenta, White, Gray, Black]
		 * choose winner color [Red, Orange, Yellow, Green, Cyan, Blue, Magenta, White, Gray, Black]
		 * choose default color [Red, Orange, Yellow, Green, Cyan, Blue, Magenta, White, Gray, Black]
		 */
		void printFrame(int col, int row)
		{
			cout<<endl<<endl;
			center(127,"\e[5;107;30m            \e[0m");
			center(127,"\e[5;107;30m  SETTINGS  \e[0m");
			center(127,"\e[5;107;30m            \e[0m");

		}
};
int main()
{
	Settings s;
	s.printSelectionScreen(2);
}

