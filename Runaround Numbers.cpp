/*
ID: chen.wu1
PROG: runround
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

char* myItoa(int number,char* Number)
{
	int offset = '0'-0;

	if(number/10==0)
	{
		*Number=number%10+offset;
		return ++Number;
	}
	else
	{
		Number = myItoa(number/10,Number);	
		*Number = number%10+offset;
		return ++Number;
	}
}

bool chkZeroAndDuplicate(char* Number, int length)
{
	int offset='0'-0;
	char count[10] = {0};
	for(int i=0;i<length;i++)
	{
		if(Number[i]-offset==0||count[Number[i]-offset]==1)
			return false;
		else
			count[Number[i]-offset]++;
	}
	return true;
}

int main()
{
	ifstream fin("runround.in");
	ofstream fout("runround.out");
	
	string strNumber;
	char Number[10];
	char* ptrNumber;
	
	int result[10] = {0};
	int original[10] = {0};
	
	int length;

	int offset = '0'-0;

	fin>>strNumber;

	length = strNumber.length();
	
	int number;
	int index;
	int count;

	bool duplicate = false;

	bool flag = true;

	number = atoi(strNumber.c_str());

	while(flag)
	{
		number++;

		duplicate = false;
		
		for(int k=0;k<10;k++)
		{
			result[k]=0;
			original[k]=0;
		}

		//itoa(number,Number,10); this function is not supported by online judge system
		ptrNumber = Number;
		ptrNumber = myItoa(number,ptrNumber);
		*ptrNumber = '\0';

		length = strlen(Number);

		if(!chkZeroAndDuplicate(Number,length))
			continue;
		
		for(int i=0;i<length;i++)
		{
			result[i] = (((Number[i]-offset)%length)+i)%length;
		}
		
		index=0;
		count=0;
		
		while(count<length)
		{
			if(original[index]==1)
			{
				duplicate = true;
				break;
			}
			original[index]=1;
			index = result[index];
			count++;
		}
		
		if(!duplicate&&index==0)
		{
			fout<<number<<endl;
			flag = false;
		}

	}

	return 0;
}
