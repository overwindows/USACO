/*
ID: chen.wu1
PROG: barn1
LANG: C++
*/

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

typedef struct Value
{
	int value;
	int head;
	int tail;
}value;

int cmp(const void *va, const void *vb)
{
	return ((value*)va)->value-((value*)vb)->value;
}

int CMP(const void *va, const void *vb)
{
	return *(int*)va-*(int*)vb;
}


int main()
{
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	
	int M,S,C;
	int stalls[300];
	value value[100];
	int groups[100];
	int tmpData[300];
	int stallIndex;
	int group = 1;
	int n = 0;
	int c=0;
	int tempIndex;
	int leftNum;
	
	fin>>M>>S>>C;
	
	//pre---
	
	for(int l=0;l<C;l++)
	{
		fin>>tmpData[l];
	}
	
	qsort(tmpData,C,sizeof(tmpData[0]),CMP);
	


	for(int i=0; i<C; i++,++c)
	{
//		fin>>stallIndex;
		stallIndex = tmpData[i];
		if(0==i)
		{
			stalls[stallIndex] = group;
			tempIndex = stallIndex;
		}
		else
		{
			if(stalls[stallIndex-1]<=0)
			{
				groups[group] = c;
				c=0;
				++group;
				value[n].value = stallIndex-tempIndex-1;
				value[n].head = tempIndex;
				value[n].tail = stallIndex;
				n++;
			}
			stalls[stallIndex] = group;
			tempIndex = stallIndex;
		}
	}
	groups[group] = c;
	
	//---
	qsort(value,group-1,sizeof(value[0]),cmp);
	
	
	if(M<group)
	{
		leftNum = group;
//		cout<<group<<endl;
		while(leftNum>M)
		{
			groups[stalls[value[0].head]] += value[0].tail+groups[stalls[value[0].tail]]-(value[0].head+1);
			groups[stalls[value[0].tail]]= 0;
			for(int r=value[0].head+1;r<value[0].tail+groups[stalls[value[0].tail]];r++)
				stalls[r] = stalls[value[0].head];
				
			value[0].value =100;

			qsort(value,group-1,sizeof(value[0]),cmp);

			leftNum--;
		}
	}
	else
	{
		
	}
	
//		for(int j=0;j<S;j++)
//		{
//			cout<<j<<"  "<<stalls[j]<<endl;
//		}
	

	int sum = 0;
	for(int u=1;u<group+1;u++)
	{
		sum += groups[u];
	}
	
	fout<<sum<<endl;
	return 0;
}