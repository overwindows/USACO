/*
ID: chen.wu1
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	
	int NP;
	
	string grpMemberName[10];
	string name;
	
	int initMoney;
	int peopleNum;

	int avarageMoney;
	
	int initialMoney[10] = {0,0,0,0,0,0,0,0,0,0};
	int receivedMoney[10] = {0,0,0,0,0,0,0,0,0,0};

	int n=0;
	int m=0;
	
	fin>>NP;
	
	for(int i=0;i<NP;i++)
	{
		fin>>grpMemberName[i];
	}
	
	for(int j=0;j<NP;j++)
	{
		fin>>name;
		fin>>initMoney;
		fin>>peopleNum;
		
		if(peopleNum!=0)
			avarageMoney = initMoney/peopleNum;
		for(;n<NP;n++)
			if(grpMemberName[n]==name)
				break;
			
		initialMoney[n]=initMoney;
		if(peopleNum!=0)
		receivedMoney[n]+=initMoney%peopleNum;
		n=0;
		
			
		for(int k=0;k<peopleNum;k++)
		{
			fin>>name;
			for(;m<NP;m++)
				if(grpMemberName[m]==name)
					break;
		
			receivedMoney[m]+=avarageMoney;
			m=0;
		}
		
			
	}
	
	
	for(int x=0;x<NP;x++)
	{
		fout<<grpMemberName[x]<<" "<<receivedMoney[x]-initialMoney[x]<<endl;
//		cout<<grpMemberName[x]<<" "<<receivedMoney[x]-initialMoney[x]<<endl;

	}
	
	return 0;
}