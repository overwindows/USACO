/*
ID: chen.wu1
PROG: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>

typedef struct progressions 
{
    long start;
    long delta;
}PROGR;

bool my_sort(PROGR a, PROGR b)
{
        if(a.delta < b.delta) 
			return true;
		else if(a.delta == b.delta)
		{
			if(a.start < b.start )
				return true;
			else
				return false;
		}
		else
			return false;
}

int main()
{
	std::ifstream fin("ariprog.in");
	std::ofstream fout("ariprog.out");
	
	std::vector<PROGR> vec_progressions;
	
	int N,M;
	long* bisqures_flag;
		
	long max_value;
	long max_cnt;
	
	fin>>N>>M;
	max_value = M*M*2;
		
	bisqures_flag = (long*)malloc(max_value * sizeof(long));
	std::memset(bisqures_flag,0,max_value * sizeof(long));
		
	for(int p=0; p <=M ;++p){
		for(int q=0; q<=M; ++q){
			bisqures_flag[p*p+q*q] = 1;
		}
	}
	
	/*
	for(int j=0; j<=max_value; ++j)
	{
		if(bisqures_flag[j]==1)
			std::cerr<<j<<" ";
	}
	std::cerr<<std::endl;
	*/
	
	for(int ix = 0; ix <=max_value; ++ix)
	{	
		//Skip Zero
		while(bisqures_flag[ix]==0) ix++;
		long start_ix = ix;
		long delta = 1;
		
		while(1)
		{
			while(start_ix + delta <= max_value && bisqures_flag[start_ix + delta] != 1) delta++;			
			if(start_ix + delta > max_value) goto NEXT;
			
			//Check
			int i=2;
			for(; i<N; ++i)
			{
				if(start_ix + i*delta > max_value) goto NEXT;
				if(bisqures_flag[start_ix+i*delta] != 1)
					break;
			}		
			
			if(i == N)
			{	
				//std::cerr<<start_ix<<" "<<delta<<std::endl;
				PROGR progression;
				progression.start = start_ix;				
				progression.delta = delta;
				vec_progressions.push_back(progression);
			}			
			delta++;			
		}
		
		NEXT:
		continue;		
	}
	if(vec_progressions.empty())
	{
		fout<<"NONE"<<std::endl;
	}
	else
	{
		std::sort(vec_progressions.begin(), vec_progressions.end(), my_sort);
			
		for(std::vector<PROGR>::iterator it=vec_progressions.begin(); it!=vec_progressions.end(); ++it)
			fout<<it->start<<" "<<it->delta<<std::endl;
	}
	fin.close();
	fout.close();
}
