/*
ID: chen.wu1
PROG: milk
LANG: C++
*/

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int (*PA)[2];
	
	int N;
	int M;
	int swpTmp1;
	int swpTmp2;

	int greed = 0;

	fin>>N;
	fin>>M;

	PA = new int[M][2];

	for(int i=0;i<M;i++)
	{
		fin>>PA[i][0];
		fin>>PA[i][1];
	}

	for(int j=0;j<M-1;j++)
		for(int k=0;k<M-1-j;k++)
		{
			if(PA[k][0]>PA[k+1][0])
			{
				swpTmp1 = PA[k][0];
				swpTmp2 = PA[k][1];
				PA[k][0] = PA[k+1][0];
				PA[k][1] = PA[k+1][1];

				PA[k+1][0] = swpTmp1;
				PA[k+1][1] = swpTmp2;
			}
		}

//	cout<<N<<endl;
//	cout<<M<<endl;

	
	
		
	for(int x=0;x<M;x++)
	{
//		cout<<PA[x][0]<<"  "<<PA[x][1]<<endl; 
		if(PA[x][1]>=N)
		{
			greed+=PA[x][0]*N;
			fout<<greed<<endl;
			break;
		}
		else
		{
			greed+=PA[x][0]*PA[x][1];
			N-=PA[x][1];
//			cout<<greed<<endl;
		}
	}
	
	if(M==0)
		fout<<"0"<<endl;
	
	return 0;
}