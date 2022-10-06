#include <iostream>
#include <vector>
#include <fstream>
#include "SettingsFrame.h"
using namespace std;
/*
 * File Structure:
 * AI difficulty (1-10)
 * player 1 string
 * player 2 string
 * frame string
 * selected frame string
 * winner color string
 */
SettingsFrame::SettingsFrame()
{
	options.resize(6);
	indexedcolors={"\e[101m","\e[48;5;208m","\e[103m","\e[102m","\e[106m","\e[104m","\e[105m","\e[107m","\e[100m","\e[40m"};
	string tmp="";
	in.open("settings.txt",ios::in);
	for(int i=0;i<7;i++)
		options[i]=(int)in.get()-'0';
	in.close();
}
void SettingsFrame::change(int val, int newint)
{
	options[val]=newint;
}
void SettingsFrame::save()
{
	out.open("txt/settings.txt",ios::trunc);
	for(int i=0;i<7;i++) out<<options[i]<<endl;
	out.close();
}
string SettingsFrame::center(int size)
{
	string res="";
	for(int i=0;i<(cols-size)/2;i++) res+=" ";
	return res;
}
void SettingsFrame::move(int x)
{

}
Frame SettingsFrame::esc()
{
	return *this;
}
/*
 * Menu Structure: 
 * SETTINGS
 * choose AI difficulty (x) move with left right arrows
 * choose player 1 color [Red, Orange, Yellow, Green, Cyan, Blue, Magenta, White, Gray, Black]
 * choose player 2 color [Red, Orange, Yellow, Green, Cyan, Blue, Magenta, White, Gray, Black]
 * choose frame color [Red, Orange, Yellow, Green, Cyan, Blue, Magenta, White, Gray, Black]
 * choose winner color [Red, Orange, Yellow, Green, Cyan, Blue, Magenta, White, Gray, Black]
 */
void SettingsFrame::updateFrame()
{

}
void SettingsFrame::printFrame(int col, int row)
{
	Frame::upperLeft;
	cout<<center(col)<<options[3]<<"            \e[0m"<<endl;
	cout<<center(col)<<options[3]<<"\e[30m  Settings   \e[0m"<<endl;
	cout<<center(col)<<options[3]<<"            \e[0m"<<endl;
}
