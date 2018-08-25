/*
ID: chen.wu1
PROG: subset
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>

int count(int M, const int N, int val, int dp[50][1000])
{
	int cnt = 0;
	if(val == 0)
		return 1;
	if(val < M+1)
		return 0;
	for(int n=M+1; n<N+1; ++n)
	{
		if(dp[n][val-n]==0)
			dp[n][val-n] = count(n,N,val-n,dp);	
		cnt += dp[n][val-n];
	}
	return cnt;
}

int main()
{
	std::ifstream fin("subset.in");
	std::ofstream fout("subset.out");
	int N;
	fin>>N;
	int SUM = (1+N)*N/2;	
	int val = 0;
	int cnt = 0;
	int dp[50][1000];
	for(int n=0;n<50;n++)
		for(int m=0;m<1000;m++)
			dp[n][m]=0;
	
	if(SUM%2 == 0)
	{
		val = SUM/2;
		cnt = count(1,N,val-1,dp);	
	}
	fout<<cnt<<std::endl;	
		
	fin.close();
	fout.close();
}
