/*
ID: chen.wu1
PROG: frac1
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

typedef struct pair
{
	int numerator;
	int denominator;
	float value;
}
Pair;

int cmp(const void *va, const void *vb)
{
	return int(((Pair*)va)->value-((Pair*)vb)->value);
}

int main()
{
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	
	int N;
	int count = 0;

	Pair numberPair[12720];

	fin>>N;
	
	for(int i=1;i<N;i++)
	{
		for(int j=i+1;j<N+1;j++)
		{
			numberPair[count].denominator = j;
			numberPair[count].numerator = i;
			numberPair[count].value = (float)i/(float)j*100000;
//			cout<<numberPair[count].numerator<<"/"<<numberPair[count].denominator<<endl;
			count++;
		}

	}
	
	qsort(numberPair,count,sizeof(numberPair[0]),cmp);

//	cout<<"*************************"<<endl;
	fout<<"0/1"<<endl;

	for(int m=0;m<count;m++)
	{
		if(numberPair[m].value==numberPair[m+1].value)
		{
		   if(numberPair[m].numerator<numberPair[m+1].numerator)
		   {
			   numberPair[m+1].numerator = numberPair[m].numerator;
			   numberPair[m+1].denominator = numberPair[m].denominator;
		   }
		   continue;
		}
			
//		cout<<numberPair[m].value<<endl;
		fout<<numberPair[m].numerator<<"/"<<numberPair[m].denominator<<endl;
	}
	
	fout<<"1/1"<<endl;
	return 0 ; 
}