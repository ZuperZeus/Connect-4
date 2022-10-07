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
	indexedcolors={"\e[101m","\e[48;5;208m","\e[103m","\e[102m","\e[48;5;49m","\e[106m","\e[104m","\e[105m","\e[48;5;128m","\e[100m"};
	reset="\e[0m";
	framestring="";
	string tmp="";
	selY=-1;
	selX=-1;
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
	//1=up;2=down;3=left;4=right;5=select
	if(x==1)
	{
		if(selY<=0) selY=5;
		else selY--;
		selX=options[selY];
	}
	if(x==2)
	{
		if(selY==5||selY==-1) selY=0;
		else selY++;
		selX=options[selY];
	}
	if(x==3)
	{
		if(selX==0) selX=9;
		else selX--;
	}
	if(x==4)
	{
		if(selX==9) selX=0;
		else selX++;
	}
	if(x==5)
	{
		options[selY]=selX;
	}
	printFrame(cols,rows);
}
Frame SettingsFrame::esc()
{
	save();
	return *this;
}
/*
 * Menu Structure: 
 * SETTINGS
 * choose AI difficulty (x) move with left right arrows
 * choose player 1 color [Red, Orange, Yellow, Green, Aquamarine, Cyan, Blue, Magenta, Purple, Gray]
 * choose player 2 color [Red, Orange, Yellow, Green, Aquamarine, Cyan, Blue, Magenta, Purple, Gray]
 * choose frame color [Red, Orange, Yellow, Green, Aquamarine, Cyan, Blue, Magenta, Purple, Gray]
 * choose selected color [Red, Orange, Yellow, Green, Aquamarine, Cyan, Blue, Magenta, Purple, Gray]
 * choose winner color [Red, Orange, Yellow, Green, Aquamarine, Cyan, Blue, Magenta, Purple, Gray]
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
	int height=(rows-21)/6;
	int width=(cols*2/3)/10;
	string sel="\e[30;5m";
	string nsel="\e[97m";
	string aidiff="AI DIFFICULTY";
	aidiff=center(aidiff.length())+"\e[97m"+aidiff+"\e[0m\n";
	string aicolors[]={"\e[48;5;51m","\e[48;5;49m","\e[48;5;46m","\e[48;5;154m","\e[48;5;226m","\e[48;5;220m","\e[48;5;214m","\e[48;5;208m","\e[48;5;202m","\e[48;5;196m"};
	for(int i=0;i<height;i++)
	{
		aidiff+=center(width*10);
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<width;k++)
			{
				aidiff+=aicolors[j];
				if(selY==0) aidiff+=sel;
				else aidiff+=nsel;
				if(selY==0&&selX==j) aidiff+="▒";
				else if(options[0]==j&&selY!=0) aidiff+="▒";
				else aidiff+=" ";
				aidiff+="\e[0m";
			}
		}
		aidiff+="\n";
	}
	string colormenu="";
	string menutitle[]={"PLAYER ONE'S COLOR","PLAYER TWO'S COLOR","BOARD COLOR","COLUMN SELECTED COLOR","WINNER COLOR"};
	for(int a=1;a<6;a++)
	{
		colormenu+=center(menutitle[a-1].length())+"\e[97m"+menutitle[a-1]+"\e[0m\n";
		for(int i=0;i<height;i++)
		{
			colormenu+=center(width*10);
			for(int j=0;j<10;j++)
			{
				for(int k=0;k<width;k++)
				{
					colormenu+=indexedcolors[j];
					if(selY==a) colormenu+=sel;
					else colormenu+=nsel;
					if(selY==a&&selX==j) colormenu+="▒";
					else if(options[a]==j&&selY!=a) colormenu+="▒";
					else colormenu+=" ";
					colormenu+="\e[0m";
				}
			}
			colormenu+="\n";
		}
		colormenu+="\n";
	}
	framestring=title+aidiff+colormenu;
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
