/*
ID: chen.wu1
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>

int bit_calc(int N)
{
	int cnt=0;
	while(N)
	{
		cnt++;
		N=N&(N-1);
	}
	return cnt;
}

int find(std::vector<int>& codewords, int N, const int D, const double upper_bound, std::map<int,int>& tbl)
{
	int ret = 0;
	if(N == 1)
	{
		return 1;
	}
	
	int n=codewords.back()+1;
	for(; n<upper_bound; ++n)
	{
		// Check Distance!
		int m=0;
		int size = codewords.size();
		for(; m<size; ++m)
		{
			//std::cerr<<tbl[codewords[m]^n]<<std::endl;
			if( tbl[codewords[m]^n] < D )
				break;
		}
		if(m == size)
		{			
			codewords.push_back(n);	
			ret = find(codewords,N-1,D,upper_bound,tbl);
			if(ret)
				return ret;
			else
				codewords.pop_back();
		}		
	}
	
	if( n== upper_bound)
		return 0;
}

int main()
{
	std::ifstream fin("hamming.in");
	std::ofstream fout("hamming.out");
	
	int N,B,D;
	fin>>N>>B>>D;
	
	std::map<int,int> tbl;
	double upper_bound = std::pow(2.0,B);
	for(int i=0; i<upper_bound; ++i)
		tbl[i]=bit_calc(i);
		
	std::vector<int> codewords;
	int ret = 0;
	for(int n=0; n<upper_bound; ++n)
	{
		codewords.clear();
		codewords.push_back(n);
		ret = find(codewords,N,D,upper_bound,tbl);
		if(ret)
		{
			for(int i=0; i<codewords.size(); i++)
			{
				fout<<codewords[i];
				if((i+1)%10 == 0 || i == (codewords.size()-1))
					fout<<std::endl;
				else
					fout<<" ";
			}
			break;
		}
	}
		
	fin.close();
	fout.close();
}
