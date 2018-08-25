/*
ID: chen.wu1
PROG: clocks
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int Stat[4][4][4][4][4][4][4][4][4] = {0};
string Table[10] = {"", "ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};

int main()
{	
	queue<string> steps;	
	queue<char*> tables;
	int clock;
	string tmp;
	int k;
	char* tmp_pos;
	char* cur_pos;

	unsigned move;
	char* pos = new char[9];
	ifstream infile("clocks.in");
	ofstream outfile("clocks.out");

	for(int ix=0; ix<9; ++ix)
	{
		infile >> k;	
		pos[ix] = (k/3)%4;
	}

	Stat[pos[0]][pos[1]][pos[2]][pos[3]][pos[4]][pos[5]][pos[6]][pos[7]][pos[8]] = 1;

	for(int n=1; n<10; ++n)
	{
		string tmpStr = tmp;
		steps.push(tmpStr.append(1,'0'+n));		
		tables.push(pos);			
	}
	cur_pos = pos;

	while(!steps.empty())
	{
		tmp = steps.front();

		if(tables.front() != cur_pos)
		{
			delete[] cur_pos;		
			cur_pos = tables.front();		
		}

		move = tmp[tmp.length()-1]-'0';
		steps.pop();
		tables.pop();

		tmp_pos = new char[9];		
		for(int i=0; i<9; ++i)
			tmp_pos[i] = cur_pos[i];	

		int j=0;		
		while((clock = Table[move][j])!='\0')
		{
			clock -='A';
			tmp_pos[clock] = (tmp_pos[clock]+1)%4;
			++j;
		}

		bool flag = true;
		for(int ix=0;ix<9;++ix)
		{
			if(tmp_pos[ix]==0)
				continue;
			else
			{
				flag = false;
				break;
			}
		}

		// Find Solution
		if(flag)
		{
			for(int ix=0;ix<tmp.length();ix++)
			{
				outfile << tmp[ix];
				if(ix < (tmp.length() - 1))
					outfile<<" ";
			}
			outfile<<endl;
			break;
		}

		if(Stat[tmp_pos[0]][tmp_pos[1]][tmp_pos[2]][tmp_pos[3]][tmp_pos[4]][tmp_pos[5]][tmp_pos[6]][tmp_pos[7]][tmp_pos[8]] == 0)
		{
			Stat[tmp_pos[0]][tmp_pos[1]][tmp_pos[2]][tmp_pos[3]][tmp_pos[4]][tmp_pos[5]][tmp_pos[6]][tmp_pos[7]][tmp_pos[8]] = 1;
		}
		else
		{
			delete[] tmp_pos;
			continue;
		}

		for(int n=move; n<10; ++n)
		{
			string tmpStr = tmp;
			steps.push(tmpStr.append(1,'0'+n));			
			tables.push(tmp_pos);
		}
	}

	return 0;
}

