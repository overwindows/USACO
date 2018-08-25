/*
ID: chen.wu1
PROG: sprime
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

void superprime(int level,int num,int prime,int* pre_candidate,int* candidate, ofstream& fout);

int main()
{
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");


	int pre_candidate[4] = {2,3,5,7};
	int candidate[4] = {1,3,7,9};
	int num;
	fin>>num;
	superprime(0,num,0,pre_candidate,candidate,fout);
	


	return 0;
}

void superprime(int level,int num,int prime,int* pre_candidate,int* candidate, ofstream& fout)
{
	bool fprime = true;
	int tmpResult;
	if(level==num)
	{	
		fout<<prime<<endl;
		return;
	}

	for(int i=0;i<4;i++)
	{
		
		if(level==0)
		{
			prime = pre_candidate[i];
			superprime(level+1,num,prime,pre_candidate,candidate,fout);
		}
		else
		{
			tmpResult = prime*10+candidate[i];
			for(int k=3;k*k<=tmpResult;k+=2)
			{
				if(tmpResult%k==0)
				{
					fprime= false;
					break;
					
				}
			}
//			cout<<tmpResult<<endl;
			if(fprime)
				superprime(level+1,num,tmpResult,pre_candidate,candidate,fout);
			else
				fprime = true;
			
		}
		
	}
}


