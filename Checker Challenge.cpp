/*
ID: chen.wu1
PROG: checker
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

void Trail(int* check,int* column,int* diagonals1,int* diagonals2,int Result[][14], int row);

int main()
{
	ifstream fin("checker.in");
	ofstream fout("checker.out");
	
	int num;
	fin>>num;
	int check[14];

	int column[15] ={0};
	int diagonals1[25] = {0};
	int diagonals2[25] = {0};

	int Result[5][14];
	int line = 0;
	
	check[0]=num;

	Trail(check,column,diagonals1,diagonals2,Result,1);
	
	int sum = column[0];
	
	while(line!=3){
		for(int k=1;k<num+1;k++)
		{
			fout<<Result[line][k];
			if(k!=num)
				fout<<" ";
		}
		fout<<endl;
		line++;
	}
	fout<<sum<<endl;
	
	return 0;
}

void Trail(int* check, int* column,int* diagonals1,int* diagonals2,int Result[][14],int row)
{
	int i;
	int k;
	
	if(row==check[0])
	{
		for(i=1;i<=check[0];++i)
		{
			if(column[i]==0&&diagonals1[check[0]+(row-i)]==0&&diagonals2[row+i]==0)
			{  
				check[row] = i;
				break;
			}
		}
		
		if(i>check[0])
		{
			return;
		}
		
		if(column[0]<4)
		{
			for(k=1;k<check[0]+1;k++)
			{
			
				Result[column[0]][k] = check[k];
			}
		}
	
		column[0]++;
		return; 
	}
	
	for(i=1;i<=check[0];++i)
	{
		if(row==1&&i>check[0]/2&&check[0]>6)
			break;
			
		if(column[i]!=0||diagonals1[check[0]+(row-i)]!=0||diagonals2[row+i]!=0)
			continue;
	
		if(column[0]<5)
			check[row] = i;
		
		column[i]++;
		diagonals1[check[0]+(row-i)]++;
		diagonals2[row+i]++;
		
		Trail(check,column,diagonals1,diagonals2,Result,row+1);
		
		column[i]--;
		diagonals1[check[0]+(row-i)]--;
		diagonals2[row+i]--;
	
	}
	
	if(row==1&&check[0]>6)
			column[0] *=2;
	
	if(row==1&&check[0]%2)
	{
		i=check[0]/2+1;
		
	
		if(column[0]<3)
			check[row] = i;
		
		column[i]++;
		diagonals1[check[0]+(row-i)]++;
		diagonals2[row+i]++;
		
		Trail(check,column,diagonals1,diagonals2,Result,row+1);
		
		column[i]--;
		diagonals1[check[0]+(row-i)]--;
		diagonals2[row+i]--;
		
	}
}