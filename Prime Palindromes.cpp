/*
ID: chen.wu1
PROG: pprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

long GeneratePrimePalindromes(long* queue,long que_index,int deep,int* loop_deep,bool flag, int depth,bool first);
bool primeCheck(long number);

int main()
{
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	
	long begin;
	long end;
	
	long queue[3000];
	long init_index = 0;
	long num;
	
	int prev_depth=-1;
	
	int rvalue_begin;
	int rvalue_end;
	
	long Count = 0;
	
	
	
	fin>>begin;
	fin>>end;
	
	
	
	rvalue_begin = log10(begin);
	rvalue_end = log10(end);
	
	
	
	bool flag = true;  //odd,assign true;even,assign false;
	
	for(int i=rvalue_begin;i<=rvalue_end;i++)
	{
		int depth = (i+1)/2;
		if((i+1)%2&&i>0)
		{
			depth++;
		}
		if(depth==prev_depth)
		{
			continue;
		}
		else
		{
			prev_depth = depth;
			int loop_deep[5]; //index 0 is not in use
			flag = (i+1)%2?true:false;
			num = GeneratePrimePalindromes(queue,init_index,depth,loop_deep,flag,depth,true);
			init_index += num;
			Count += num;
		}
	}
	
		for(int k = 0; k < Count; k++)
		{
			if(queue[k]>=begin&&queue[k]<=end)
			{
				fout<<queue[k]<<endl;
			}
		}
	

	return 0;
}


long GeneratePrimePalindromes(long* queue,long que_index,int deep,int* loop_deep,bool flag, int depth,bool first)
{
	int count = 0;
	int num = 0;
	
	if(first&&deep==0)  //......
	{
		for(int d5=2;d5<10;d5++)
		{
			if(primeCheck(d5))
			{
				queue[que_index++] = d5;
				num++;
			}
		}
		return num;
	}
	if(first&&deep!=1)
	{
		for (int d3 = 1; d3 <= 9; d3+=2) 
		{
			loop_deep[deep] = d3;
			count = GeneratePrimePalindromes(queue,que_index,deep-1,loop_deep,flag,depth,false);
			que_index += count;
			num += count;
		}
		return num;
	}
	else if(first&&depth==1)
	{
		int palindrome = 0;
		for (int d4 = 1;d4 <= 9;d4+=2)
		{
			loop_deep[deep] = d4;
			int tmp_depth = depth;
			for(int m=depth*2;m>depth;m--,tmp_depth--)
			{
				palindrome += loop_deep[tmp_depth]*pow(10,m-1)+loop_deep[tmp_depth]*pow(10,depth*2-m);
			}

			if(primeCheck(palindrome))
			{
				queue[que_index++] = palindrome;
				num++;
			}
			palindrome = 0;
			//----------------------------------------------------------
			
		}
		return num;
	}
	else if(deep == 1)  //last
	{
		long palindrome = 0;
		if(flag)  //odd number
		{
			for (int d1 = 0; d1 <= 9; d1++)
			{
				//palindrome = 10000*d3 + 1000*d2 +100*d1 + 10*d2 + d3;
				//... deal with palindrome ...
				loop_deep[deep] = d1;
				int tmp_depth = depth;
				for(int m=depth*2-1;m>depth;m--,tmp_depth--)
					palindrome += loop_deep[tmp_depth]*pow(10,m-1)+loop_deep[tmp_depth]*pow(10,depth*2-1-m);
				palindrome += loop_deep[tmp_depth]*pow(10,depth-1);
				//----------------------------------------------------------
				if(palindrome<100000000&&primeCheck(palindrome))
				{
					queue[que_index++] = palindrome;
					num++;
				}
				
				palindrome = 0;
				
				//----------------------------------------------------------
				
			}
			return num;
		}
		else  //even number
		{
			for (int d1 = 0; d1 <= 9; d1++)
			{
				loop_deep[deep] = d1;
				int tmp_depth = depth;
				for(int m=depth*2;m>depth;m--,tmp_depth--)
				{
					palindrome += loop_deep[tmp_depth]*pow(10,m-1)+loop_deep[tmp_depth]*pow(10,depth*2-m);
				}
				if(palindrome<100000000&&primeCheck(palindrome))
				{
					queue[que_index++] = palindrome;
					num++;
				}
					palindrome = 0;
				
			}
			return num;
		}
	}
	
	for (int d2 = 0; d2<=9; d2++)
	{
		loop_deep[deep] = d2;
		count = GeneratePrimePalindromes(queue,que_index,deep-1,loop_deep,flag, depth,false);
		que_index += count;
		num += count;
	}
	
	return num;
}

bool primeCheck(long number)
{
	int range = sqrt(number);
	for(int x=2;x<=range;x++)
	{
		if((number%x)==0)
		{
			return false;
		}
	}
	return true;
}


