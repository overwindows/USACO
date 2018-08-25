/*
ID: chen.wu1
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

static char base[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};

int main()
{
	int B;
	
	int square;
	char StackBase[10]={0};
	char StackPalindromic[10]={0};
	int IndexPalindromic=0;
	int IndexBase=0;
		
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	fin>>B;
	
	int n;
	int m;
	
	int tmp;
	for(int i=1;i<=300;++i)
	{
		square= i*i;
		while(square/B)
		{
			StackPalindromic[IndexPalindromic++] = base[square%B];
			square=square/B;
		}
		StackPalindromic[IndexPalindromic++] = base[square];
		
		
		for(int index=0;index<IndexPalindromic/2;++index)
		{
			if(StackPalindromic[index]!=StackPalindromic[IndexPalindromic-1-index])
				goto out;
		}
		
		tmp=i;

		while(tmp/B)
		{
			StackBase[IndexBase++] = base[tmp%B];
			tmp=tmp/B;
		}
		StackBase[IndexBase++] = base[tmp];

		for(n=0;n<IndexBase;++n)
		{
			fout<<StackBase[IndexBase-1-n];
		}
		
		fout<<" ";

		for(m=0;m<IndexPalindromic;++m)
		{
			fout<<StackPalindromic[IndexPalindromic-1-m];
		}
		
		fout<<endl;
out:
		IndexPalindromic=0;
		IndexBase=0;

	}
	
	
	return 0;
}