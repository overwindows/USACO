/*
ID: chen.wu1
PROG: combo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>

int main()
{
	std::ifstream fin("combo.in");
	std::ofstream fout("combo.out");
	int max=0;
	int overlap[3]={0,0,0};
	int farmer[3][101];
	for(int n=0;n<3;++n)
		for(int m=0;m<101;++m)
			farmer[n][m] == 0;
	
	int N;
	int l;
	int lock[2];
	int rlock[2];
	int lock_r1;
	int lock_r2;
	
	fin>>N;
	if(N<5)
		max = N*N*N*2;
	else
		max = 250;
	//farmer
	for(int i=0;i<3;++i){
	    fin>>l;
		farmer[i][l]=1;
		//std::cout<<farmer[i][l]<<" "<<i<<"*"<<l<<" ";
		for(int j=0;j<2;j++)
		{
			lock[j] = (++l)%N;
			if(lock[j]==0)
				lock[j]=N;
			farmer[i][lock[j]]=1;
			//std::cout<<farmer[i][lock[j]]<<" "<<i<<"*"<<lock[j]<<" ";
		}
		l-=2;
		for(int k=0;k<2;++k)
		{
			rlock[k] = --l;
			if(rlock[k]<1)
			{	
				if(N==1)
					rlock[k] = 1;
				else
					rlock[k]+=N;
			}
			farmer[i][rlock[k]]=1;
			//std::cout<<farmer[i][rlock[k]]<<" "<<i<<"*"<<rlock[k]<<" ";
		}
		l+=2;
		//std::cout<<std::endl;
	}
	
	//master
	for(int i=0;i<3;++i){
		fin>>l;
		if(farmer[i][l]==1)
		{
			farmer[i][l] = 0;
			//std::cout<<i<<"_"<<l<<std::endl;
			overlap[i]++;
		}
		int j=0;
		for(;j<2;j++)
		{
			lock[j] = (++l)%N;
			if(lock[j]==0)
				lock[j]=N;
			if(farmer[i][lock[j]]==1)
			{
				farmer[i][lock[j]] = 0;
				//std::cout<<i<<"_"<<lock[j]<<std::endl;
				overlap[i]++;
			}
		}
		l-=2;
		for(int k=0;k<2;++k)
		{
			rlock[k] = --l;
			if(rlock[k]<1)
			{	
				if(N==1)
					rlock[k] = 1;
				else
					rlock[k]+=N;
			}
			if(farmer[i][rlock[k]]==1)
			{
				farmer[i][rlock[k]] = 0;
				//std::cout<<i<<"_"<<rlock[k]<<std::endl;
				overlap[i]++;
			}
		}
	
		l+=2;
	}
	
	int overlap_cnt = 1;
	for(int n=0; n<3; ++n)
	{
		//std::cout<<overlap[n]<<" ";
		overlap_cnt*=overlap[n];
	}	
	//std::cout<<std::endl;
	fout<<(max-overlap_cnt)<<std::endl;
	fin.close();
	fout.close();
}
