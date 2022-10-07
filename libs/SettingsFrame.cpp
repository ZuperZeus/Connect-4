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
	reset="\e[0m";
	framestring="";
	string tmp="";
	in.open("libs/txt/settings.txt",ios::in);
	for(int i=0;i<6;i++)
		options[i]=(int)in.get()-'0';
	in.close();
}
void SettingsFrame::change(int val, int newint)
{
	options[val]=newint;
}
void SettingsFrame::save()
{
	out.open("libs/txt/settings.txt",ios::trunc);
	for(int i=0;i<6;i++) out<<options[i];
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
 * choose selected color [Red, Orange, Yellow, Green, Cyan, Blue, Magenta, White, Gray, Black]
 * choose winner color [Red, Orange, Yellow, Green, Cyan, Blue, Magenta, White, Gray, Black]
 */
void SettingsFrame::updateFrame()
{
	string title;
	if(cols>=70)
	{
		title="\n"+
		center(70)+"\e[48;5;82;30m                                                                      \e[0m\n"+
		center(70)+"\e[48;5;46;30m   #####   #######  #######  #######  ###  #     #   #####    #####   \e[0m\n"+
		center(70)+"\e[48;5;47;30m  #     #  #           #        #      #   ##    #  #     #  #     #  \e[0m\n"+
		center(70)+"\e[48;5;48;30m  #        #           #        #      #   # #   #  #        #        \e[0m\n"+
		center(70)+"\e[48;5;49;30m   #####   #####       #        #      #   #  #  #  #  ####   #####   \e[0m\n"+
		center(70)+"\e[48;5;50;30m        #  #           #        #      #   #   # #  #     #        #  \e[0m\n"+
		center(70)+"\e[48;5;51;30m  #     #  #           #        #      #   #    ##  #     #  #     #  \e[0m\n"+
		center(70)+"\e[48;5;87;30m   #####   #######     #        #     ###  #     #   #####    #####   \e[0m\n"+
		center(70)+"\e[48;5;123;30m                                                                      \e[0m\n";

	}
	else if(cols>=40)
	{
		title="\n"+
		center(40)+"\e[48;5;46;30m  ____       _   _   _                  \e[0m\n"+
		center(40)+"\e[48;5;47;30m / ___|  ___| |_| |_(_)_ __   __ _ ___  \e[0m\n"+
		center(40)+"\e[48;5;48;30m \\___ \\ / _ \\ __| __| | '_ \\ / _` / __| \e[0m\n"+
		center(40)+"\e[48;5;49;30m  ___) |  __/ |_| |_| | | | | (_| \\__ \\ \e[0m\n"+
		center(40)+"\e[48;5;50;30m |____/ \\___|\\__|\\__|_|_| |_|\\__, |___/ \e[0m\n"+
		center(40)+"\e[48;5;51;30m                             |___/      \e[0m\n";
	}
	else if(cols>=20)
	{
		title="\n"+
		center(20)+"\e[48;5;46;30m __                 \e[0m\n"+
		center(20)+"\e[48;5;48;30m(_  __|__|_o._  _  _\e[0m\n"+
		center(20)+"\e[48;5;49;30m__)(/_|_ |_|| |(_|_>\e[0m\n"+
		center(20)+"\e[48;5;51;30m                _|  \e[0m\n";
	}
	else
	{
		title="\n"+
		center(12)+"\e[48;5;46;30m            \e[0m\n"+
		center(12)+"\e[48;5;48;30m  Settings  \e[0m\n"+
		center(12)+"\e[48;5;51;30m            \e[0m\n";
	}
	framestring=title;
}
void SettingsFrame::printFrame(int col, int row)
{
	if(cols!=col||rows!=row)
	{
		cols=col;
		rows=row;
	}
	updateFrame();
	this->clear();
	cout<<framestring;
	//cout<<center()<<"Choose Ai Difficulty"<<endl;
}
