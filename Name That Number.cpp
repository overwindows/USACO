/*
ID: chen.wu1
PROG: namenum
LANG: C++
*/

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

bool checkName(const char* name, const char* givenName, const char Letters[8][3], int index, int length);


int main()
{
	ifstream fin("namenum.in");
	ifstream fdict("dict.txt");
	ofstream fout("namenum.out");
	string Num;
	string Name;
	string givenName;
	int length = 0;
	int sum=0;

	const char* name;


	fin>>Num;
	length = Num.length();
	name = Num.c_str();
	
	const char Letters[8][3] = {{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
	
	while(!fdict.eof())
	{
		fdict>>givenName;
			
//		if(givenName=="GREG")
//		{
//			cout<<"===="<<endl;
//		}

		if(givenName.length()==length&&checkName(name,givenName.c_str(),Letters,0,length))
		{
			fout<<givenName<<endl;
			sum++;
			
		}
		
		
	}

	if(sum==0)
	{
		fout<<"NONE"<<endl;
	}
	return 0;
}

bool checkName(const char* name, const char* givenName, const char Letters[8][3], int index, int length)
{
	if(length==0)
		return true;



	for(int i=0;i<3;i++)
	{
		if(givenName[index] == Letters[name[index]-'1'-1][i]&&checkName(name,givenName,Letters,++index,length-1))
		{
			return true;
		}
	
	}
	return false; 
}