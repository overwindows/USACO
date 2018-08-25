/*
ID: chen.wu1
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int N;
	int S;
	
	int StackPalindromic[30]={0};
	int IndexPalindromic=0;
	int Palindromic;
	int j;
	int flag = 0;
	
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	
	fin>>N;
	fin>>S;
	
	++S;
	
	for(int i=0; i<N ; ++i)
	{
		for(j=2; j<11; ++j)
		{
			IndexPalindromic=0;
			Palindromic = S;

			while(Palindromic/j)
			{
				StackPalindromic[IndexPalindromic++] = Palindromic%j;
				Palindromic=Palindromic/j;
			}
			StackPalindromic[IndexPalindromic++] = Palindromic;
			
			for(int index=0;index<IndexPalindromic/2;++index)
			{
				if(StackPalindromic[index]!=StackPalindromic[IndexPalindromic-1-index])
					goto out;
			}
			flag++;	
			if(flag==2)
				break;
out:
			continue;
		}
		

	
		if(flag==2)
		{
			fout<<S<<endl;
			++S;	
			
		}
		else
		{
			
			++S;
			--i;
		}
			flag = 0;
	}
	
	
	return 0;
}