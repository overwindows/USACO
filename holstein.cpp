/*
ID: chen.wu1
PROG: holstein
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
	std::ifstream fin("holstein.in");
	std::ofstream fout("holstein.out");
	
	char key[2] = {0};
	int V,G;
	int tmp;

	std::vector<int> vec_tmp;
	std::vector<int> vec_v;
	std::vector<std::vector<int> > vvec_g;
	std::map<std::string, std::vector<int> > map_g;
	
	fin >> V;
	for(int i=0; i<V; ++i)
	{
		fin >> tmp;		
		vec_v.push_back(tmp);
	}
	fin >> G;
	for(int i=0; i<G; ++i)
	{
		vec_tmp.clear();
		for(int j=0; j<V; j++)
		{
			fin>>tmp;
			vec_tmp.push_back(tmp);
		}
		vvec_g.push_back(vec_tmp);
		key[0] = i+'A';
		std::string str_key(key);
		map_g[str_key] = vec_tmp;
	}
	
	bool find = false;
	int MIN_SUM = 3750000;
	std::string MIN_KEY;
	
	int MIN_SCOOPS = 0;
	int i=0;
	for(; i < G; ++i)
	{		
		for(std::map<std::string, std::vector<int> >::iterator it = map_g.begin(); it!=map_g.end(); ++it)
		{			
			int sum = 0;
			//Candidate
			int n=0;			
			for(; n<V ; ++n)
			{				
				if((it->second)[n] < vec_v[n])
					break;
				sum += (it->second)[n];
			}			
			if(n<V)
			{
				continue;
			}
			else
			{
				find = true;
				if(sum < MIN_SUM)
				{
					MIN_SUM = sum;
					MIN_KEY = it->first;
				}
			}				
		}
		
		if(!find)
		{
			std::map<std::string, std::vector<int> > map_g_new;
			for(std::map<std::string, std::vector<int> >::iterator it = map_g.begin(); it!=map_g.end(); ++it)
			{
				for(int i=0; i<G; i++)
				{
					char ch = 'A'+i;
					//if((it->first).find(ch) !=  std::string::npos)
					if(it->first[(it->first).size()-1] >= ch)
						continue;
					vec_tmp.clear();
					for(int n=0; n<V; ++n)
					{						
						vec_tmp.push_back((it->second)[n] + vvec_g[i][n]);
					}
					key[0] = 'A'+i;
					std::string new_key = (it->first)+std::string(key);
					map_g_new[new_key] = vec_tmp;
				}				
			}
			map_g = map_g_new;
		}
		else
		{
			MIN_SCOOPS = i+1;
			break;
		}
	}	
	
	if(MIN_SCOOPS > 0)
	{		
		fout<<MIN_SCOOPS<<" ";
		const char* min_key = MIN_KEY.c_str();
		for(int i=0; i<MIN_KEY.size()-1; ++i)
		{
			fout<<min_key[i]-'A'+1<<" ";
		}	
		fout<<(min_key[MIN_KEY.size()-1]-'A'+1)<<std::endl;
	}
	
	fin.close();
	fout.close();
}
