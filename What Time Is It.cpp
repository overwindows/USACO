/*
ID: chen.wu1
PROG: clock
LANG: C++
*/

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream fin("clock.in");
	ofstream fout("clock.out");
	
	string Clock[23] = {"None","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen",
		"fourteen","fifteen","sixteen","seventeen","eighteen","ninteen","twenty","thirty","forty"};
	
	string clock;
	string Hour;
	string Minute;
	string timeInEnglish;
	string tmpTime;
	int hour;
	int minute;
	int i;
	
	fin>>clock;
	
	for(i=0;i<clock.length();i++)
	{
		if(clock[i]==':')
			break;
		Hour += clock[i];
		
	}
	
	Minute = clock.substr(i+1,clock.length());
	
	hour = atoi(Hour.c_str());
	minute = atoi(Minute.c_str());
	
	//	cout<<hour<<endl;
	//	cout<<minute<<endl;
	
	if(minute%15)
	{
		if(minute>45)
		{
			timeInEnglish = Clock[60-minute]+" to "+Clock[(hour+1)%12];
		}
		else 
		{
			if(minute/10>1)
			{
				tmpTime = Clock[minute/10+18];
				tmpTime += minute%10?"-"+Clock[minute%10]:"";
//				cout<<tmpTime<<endl;
			}
			else
			{
				tmpTime = Clock[minute];
			}
			timeInEnglish = Clock[hour]+" "+tmpTime;
		}
	}
	else
	{
		switch(minute)
		{
		case 0: timeInEnglish = Clock[hour]+" o'clock"; break;
		case 15: timeInEnglish = "quarter past " + Clock[hour];break;
		case 30: timeInEnglish = Clock[hour]+" thirty"; break;
		case 45: timeInEnglish = "quarter to " + Clock[(hour+1)%12];break;
		}
	}
	
	timeInEnglish[0] = timeInEnglish[0]+'A'-'a';
	fout<<timeInEnglish<<endl;
	return 0;
}
