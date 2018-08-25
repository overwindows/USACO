/*
ID: chen.wu1
PROG: sort3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>

int main()
{
	std::ifstream fin("sort3.in");
	std::ofstream fout("sort3.out");
	int N,n;
	fin>>N;
	
	std::vector<int> raw_array;
	std::vector<int> sorted_array;	
	for(int i=0; i < N; i++)
	{
		fin >> n;
		raw_array.push_back(n);
		sorted_array.push_back(n);
	}	
	std::sort(sorted_array.begin(), sorted_array.end());
	
	std::vector<int> mismatch;
	int key;
	for(int j=0; j<N; ++j)
	{
		key = raw_array[j]*10+sorted_array[j];
		mismatch.push_back(key);
		//std::cerr<<key<<std::endl;		
	}
	
	int op = 0;
	bool flag = true;
	while(flag)
	{
		//Step 1
		for(int i=0; i<N; ++i)
		{
			if(mismatch[i]%10 == mismatch[i]/10)
				continue;
				
			for(int j=i+1; j<N; ++j)
			{
				if(mismatch[j]%10 == mismatch[j]/10)
					continue;
				
				if( ((mismatch[i]%10)*10+mismatch[i]/10) == mismatch[j] )
				{
					mismatch[i] = (mismatch[i]%10)*10+(mismatch[i]%10);
					mismatch[j] = (mismatch[j]%10)*10+(mismatch[j]%10);
					op++;
					break;
				}
				else
				{
					continue;
				}
			}
		}
		/*
		for(int x=0; x<N; x++)
		{	
			std::cerr<<mismatch[x]<<std::endl;
		}
		*/
		//Step 2
		for(int i=0; i<N; ++i)
		{
			if(mismatch[i]%10 == mismatch[i]/10)
				continue;
			for(int j=i+1; j<N; ++j)
			{
				if(mismatch[j]%10 == mismatch[j]/10)
					continue;
				
				if( mismatch[i]%10 == mismatch[j]/10 )
				{
					mismatch[j] = (mismatch[i]/10)*10+(mismatch[j]%10);
					mismatch[i] = (mismatch[i]%10)*10+(mismatch[i]%10);
					op++;
					break;
				}
				else
				{
					continue;
				}
			}
		}
		/*
		for(int x=0; x<N; x++)
		{	
			std::cerr<<mismatch[x]<<std::endl;
		}
		*/
		int i;
		for(i=0; i<N; ++i)
			if(mismatch[i]%10 != mismatch[i]/10)
				break;
		
		if(i == N)
			flag = false;
	}
		
	fout << op <<std::endl;
	fin.close();
	fout.close();
}
