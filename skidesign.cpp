/*
ID: chen.wu1
PROG: skidesign
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
#include <assert.h>

int main() {
	std::ifstream fin("skidesign.in");
	std::ofstream fout("skidesign.out");

	int N;
	int v;
	int cost = 0;
	int cost1 = 0;
	std::vector<int> ele;
	std::vector<int> ele1;

	fin>>N;
	for(int i=0; i<N; ++i) {
		fin >> v;
		ele.push_back(v);
		ele1.push_back(v);
	}
	std::sort(ele.begin(), ele.end());

	const int s_i = 0;
	const int m_i = ele.size()-1;

	int diff;
	int dlt;
	diff = ele[m_i]-ele[s_i];

	while(diff>17) {
		dlt = diff-17;

		if(dlt%2) {
			ele[m_i] -= (dlt/2+1);
			ele[s_i] += (dlt/2);
		} else {
			ele[m_i] -= (dlt/2);
			ele[s_i] += (dlt/2);
		}
		std::sort(ele.begin(), ele.end());
		diff=ele[m_i]-ele[s_i];		
	}
	
    //std::cout<<ele[s_i]<<"-"<<ele[m_i]<<std::endl;
	//ele[m_i] = 62;
	//ele[s_i] = 45;
	
	for(int j=0; j < ele.size(); ++j) {
		if(ele1[j]-ele[m_i] > 0)
			cost += (ele1[j]-ele[m_i]) * (ele1[j]-ele[m_i]);
		else if (ele1[j]-ele[s_i]< 0)
			cost += (ele1[j]-ele[s_i]) * (ele1[j]-ele[s_i]);
	}

	ele[m_i]++;
	ele[s_i]++;
	for(int j=0; j < ele.size(); ++j) {
		if(ele1[j]-ele[m_i] > 0)
			cost1 += (ele1[j]-ele[m_i]) * (ele1[j]-ele[m_i]);
		else if (ele1[j]-ele[s_i]< 0)
			cost1 += (ele1[j]-ele[s_i]) * (ele1[j]-ele[s_i]);
	}

	fout<<(cost>cost1?cost1:cost)<<std::endl;
	fin.close();
	fout.close();
}
