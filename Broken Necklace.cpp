/*
ID: chen.wu1
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	
	int num;
	
	int w_first = 0;
	int w_second = -1;
	int w_pos = -1;

	bool w_flag = true;
	bool w_flg = false;

	int first;
	int second;
	int index;
	int maxBegin;
	int maxEnd;
	string sequence;
	const char* Seque;
	bool flag = false; //meet the different color 
	bool fg = true;
	
	char cuColor;
	char prev = 'B'; //Blank
	char temp;
	
	int currentMax = 0;
	int Sum=0;
	
	fin>>num;
	fin>>sequence;
	
	Seque = sequence.c_str();
	int i;
	int offset = 0;
	
	for(i=0;i<num+offset;i++)
	{

		cuColor = Seque[i%num];
		
		if(cuColor == 'w')
		{
			if(w_flag)
			{
				w_flag = false;
				w_first = i;
			}
			else if(w_flg)
			{
				w_flg = false;
				w_second = i;
			}
		
			continue;
		}
		
		if(prev == 'B') //first time
		{
//			first = i;
			first = w_first;
			prev = Seque[i%num];
		
			//------
			w_flag = true;
			//------
		}
		
		if(cuColor!=prev&&!flag)
		{
//			second = i;
			second = w_first==-1?i:w_first;
			flag = true;
			w_flg = true;

			temp = cuColor;
		}
		else if(cuColor==prev&&!flag)
		{
			w_first = -1;
			w_second = -1;
			w_flag = true;
		}
		else if(cuColor==temp&&flag)
		{
			w_first = -1;
			w_second = -1;
			w_flag = true;

		}
		else if(cuColor==prev&&flag)
		{
			
			
			flag = false;
			Sum = i-first;
			cout<<"+++++++++++++++"<<endl;
			
			if(fg)
			{
				offset = i;
				fg = !fg;
				cout<<"OFFSET"<<offset<<endl;
			}
			
			cout<<first<<endl;
			cout<<(i-1)%num<<endl;
			
			cout<<Sum<<endl;
			
			
			maxBegin = Sum>currentMax?first:maxBegin;
			maxEnd = Sum>currentMax?i-1:maxEnd;
			currentMax = currentMax>Sum?currentMax:Sum;
			
			prev = temp;
			cout<<prev<<endl;
			
//--------------------------------			
			temp = '?';
			w_flag = true;
//--------------------------------
//			first = second;
			
			if(first == second&&w_first!=-1)
			{
				first = w_first;
			}
			else
			{
			if(w_first!=-1)
				first = w_first>=second?second:w_first;
			else
				first = second;
			}
			
			
			first = w_second==-1?first:w_second;
		
		
		
			
			cout<<"first:"<<first<<endl;
			cout<<"second:"<<second<<endl;
			cout<<"w_first:"<<w_first<<endl;
			cout<<"w_second:"<<w_second<<endl;

		    w_second = -1;

			i--;
		}
		
	}
	
	cout<<"+++++++++++++++"<<endl;
	Sum = i-first;
	cout<<first<<endl;
	cout<<(i-1)%num<<endl;
	
	
	cout<<Sum<<endl;
	
	
	maxBegin = Sum>currentMax?first:maxBegin;
	maxEnd = Sum>currentMax?i-1:maxEnd;
	currentMax = currentMax>Sum?currentMax:Sum;


	{
	fout<<currentMax<<endl;
	}
	
	return 0;
}