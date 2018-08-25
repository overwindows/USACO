/*
ID: chen.wu1
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	
	string comet;
	string group;

	const char* cometCh;
	const char* groupCh;

	long cometMulti;
	long groupMulti;

	fin>>comet;
	fin>>group;
	
	cometMulti = 1;
	groupMulti = 1;

	cometCh = comet.c_str();
	groupCh = group.c_str();



	for(int i=0; i<comet.length(); i++)
	{
		cometMulti *= (int)cometCh[i]-64;
	}
	
	for(int j=0; j<group.length(); j++)
	{
		groupMulti *= (int)groupCh[j]-64;
	}


	if(groupMulti%47==cometMulti%47)
		fout<<"GO"<<endl;
	else
		fout<<"STAY"<<endl;


	return 0;


}
