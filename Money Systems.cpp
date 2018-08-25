/*
ID: chen.wu1
PROG: money
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int compare( const void *arg1, const void *arg2 )
{
    return  (* ( int* ) arg1)-(* ( int* ) arg2 );
}

int countWaysII(int value,int currentIndex,int* units) //by Zhang Ming
{

	if (currentIndex==0)
	{
		if (value% units[currentIndex]==0)
			return 1;
		else
			return 0;
	}
	int ways=0;
	int round= value/units[currentIndex];
	int _value;
	for(int i=0;i<round+1;i++)
	{
		_value=value-units[currentIndex]*i;
		if(_value==0)
		{
			++ways;
			continue;
		}
		ways+=countWaysII(_value,currentIndex-1,units);
	}
	
	return ways;
	
}


int countWaysI(int value,int* units,int currentIndex) //by Wu Chen
{
	
	int Ways = 0;		
	int _value;
	
	int mod = value%units[currentIndex];
	int quotient  = value/units[currentIndex];
	
	for(int round=0;round<quotient;++round)
	{
		if(mod==0&&round==quotient)
		{
			++Ways;
		}
		else
		{
			if(currentIndex>0)
			{
				_value = value-round*units[currentIndex];
				if(_value==0)
				{
					Ways++;
					continue;
				}
				else if(_value<0)
				{
					continue;
				}
				Ways += countWaysI(_value,units,currentIndex-1);
			}
		}
	}
	
	if(mod==0)
	{
		return ++Ways;
	}
	else
	{
		if(currentIndex>0)
		{
			_value = value-quotient*units[currentIndex];
			if(_value==0)
				return ++Ways;
			else if(_value<0)
				return Ways;
			Ways += countWaysI(_value,units,currentIndex-1);
		}
	}
	
	return Ways; 
	
	
}

void GenerateMatrix(int Value, int Number, int Matrix[][26], int* units)
{
	
	for(int num=0;num<Number;++num)
	{
		
		Matrix[units[num]][units[num]] = 1;
		if(num==0)
			Matrix[units[num]][0]=1;
		else
			Matrix[units[num]][0]+=1;

		for(int val=units[num]+1;val<Value+1;++val)
		{
			Matrix[val][units[num]] = Matrix[val-units[num]][0];
			Matrix[val][0] += Matrix[val][units[num]];
		}
	}
}

int main()
{
	ifstream fin("money.in");
	ofstream fout("money.out");
	
	int V,N;
	int units[25]={0};
	int tmp[10] = {0};
	int ways = 0;
	
	int Matrix[101][26]={0};
	
	fin>>N;
	fin>>V;
	
	for(int i=0;i<N;i++)
	{
		fin>>units[i];
	}
	
	qsort(units, N, sizeof(units[0]), compare);

//	ways = countWaysI(V,units,N-1);
	
//	ways = countWaysII(V,N-1,units);

	GenerateMatrix(V,N,Matrix,units);

	
//	cout<<ways<<endl;
    cout<<Matrix[V][0]<<endl;
	
	return 0;
}
