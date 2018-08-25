/*
ID: chen.wu1
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");
	
	int level;
	int row[1000];
	int pre_row[999];
	int num;
	
	fin>>level;
	for(int i=0;i<level;i++)
	{
		
		for(int j=0;j<=i;j++)
		{
			fin>>num;
		
			if(i==0)
			{
				row[j]=num;
				pre_row[j] = num;
				continue;
			}
			
			if(j==0)
				row[j]= pre_row[j]+num;
			else if(j==i)
				row[j] = pre_row[i-1]+num;
			else
				row[j] = pre_row[j-1]+num>pre_row[j]+num?pre_row[j-1]+num:pre_row[j]+num;
			
//			pre_row[j] = row[j]; 
		}
		for(int m=0;m<=i;m++)
		{
			pre_row[m]=row[m];
//			cout<<pre_row[m]<<" ";
		}
	
		cout<<endl;
	}
	
	int max = row[0];
	
	for(int k=0;k<level;k++)
	{
		max = max>row[k]?max:row[k];
	}
	fout<<max<<endl;
	return 0;
}
