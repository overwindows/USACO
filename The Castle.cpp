/*
ID: chen.wu1
PROG: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct optimalWall
{
	int max;
	int row;
	int column;
	char direction;
}OptimalWall;

int Floodfill(int floorplan[50][50],int floodfill[50][50], int n, int m, int roomNum,int M, int N, int flag);

int main()
{
	int M,N;
	int Count;
	int floodfill[50][50] = {{0,0}};
	int floorplan[50][50] = {{0,0}}; 
	int Ewall[50][50] = {{0,0}};
	int Nwall[50][50] = {{0,0}};
	int Room[5000]={0};
	int Ewall_Max=0;
	int r,c,r1,c1;
	int n;
	int Nwall_Max=0;
	int MaxCount=0;
	int roomNum=0;
	OptimalWall optimalwall_E[2500];
	OptimalWall optimalwall_N[2500];
	int indexE=0;
	int indexN=0;
	

	ifstream fin("castle.in");
	ofstream fout("castle.out");
	
	fin>>M;
	fin>>N;
	
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			fin>>floorplan[i][j];
		}
	}
	
	for(n=0;n<N;++n)
	{
		for(int m=0;m<M;++m)
		{
			if(floodfill[n][m]==0)
			{
				roomNum++;
				Count = Floodfill(floorplan,floodfill,n,m,roomNum,M,N,0);				
				Room[roomNum] = Count;
				MaxCount = MaxCount>Count?MaxCount:Count;
			}
			else
			{
				continue;
			}
		}
		
	}
	
	int currentRoom;
	
	for(int o=0;o<N;++o)
	{
		currentRoom = floodfill[o][0];
		for(int p=0;p<M;++p)
		{ 
			if(floodfill[o][p]!=currentRoom)
			{
				if(Room[currentRoom]+Room[floodfill[o][p]]>Ewall_Max)
				{
					Ewall_Max = Room[currentRoom]+Room[floodfill[o][p]];
					r = o+1;
					c = p;
					//-------------------------------------
					indexE=0;
					optimalwall_E[indexE].max = Room[currentRoom]+Room[floodfill[o][p]];
					optimalwall_E[indexE].row = o+1;
					optimalwall_E[indexE].column = p;
					optimalwall_E[indexE].direction = 'E';
					//-------------------------------------
				}
				else if(Room[currentRoom]+Room[floodfill[o][p]]==Ewall_Max)
				{
					if(p<c)
					{
						r = o+1;
						c = p;
					}
					//-------------------------------------
					indexE++;
					optimalwall_E[indexE].max = Room[currentRoom]+Room[floodfill[o][p]];
					optimalwall_E[indexE].row = o+1;
					optimalwall_E[indexE].column = p;
					optimalwall_E[indexE].direction = 'E';
					//-------------------------------------
					
				}
				else
				{
				}
				currentRoom = floodfill[o][p];
			}
		}
	}
	
	for(int s=0;s<M;++s)
	{
		currentRoom = floodfill[0][s];
		for(int t=0;t<N;++t)
		{
			if(floodfill[t][s]!=currentRoom)
			{
				if(Room[currentRoom]+Room[floodfill[t][s]]>Nwall_Max)
				{
					Nwall_Max = Room[currentRoom]+Room[floodfill[t][s]];
					r1 = t+1;
					c1 = s+1;
					//-----------------
					indexN=0;
					optimalwall_N[indexN].max = Room[currentRoom]+Room[floodfill[t][s]];
					optimalwall_N[indexN].row = t+1;
					optimalwall_N[indexN].column = s+1;
					optimalwall_N[indexN].direction = 'N';
					//-----------------
				}
				else if(Room[currentRoom]+Room[floodfill[t][s]]==Nwall_Max)
				{
					indexN++;
					optimalwall_N[indexN].max = Room[currentRoom]+Room[floodfill[t][s]];
					optimalwall_N[indexN].row = t+1;
					optimalwall_N[indexN].column = s+1;
					optimalwall_N[indexN].direction = 'N';
					//---------------------
				}
				else
				{

				}
				currentRoom = floodfill[t][s];
			}
		}
	}

	
	for(int a=0; a<indexE+1;++a)
	{
		if(a==0)
		{
			Ewall_Max = optimalwall_E[a].max;
			r = optimalwall_E[a].row;
			c = optimalwall_E[a].column;
			continue;
		}
		
		if(optimalwall_E[a].row>=r&&optimalwall_E[a].column<=c)
		{
			Ewall_Max = optimalwall_E[a].max;
			r = optimalwall_E[a].row;
			c = optimalwall_E[a].column;

		}
	}

	for(int b=0; b<indexN+1;++b)
	{
		if(b==0)
		{
			Nwall_Max = optimalwall_N[b].max;
			r1 = optimalwall_N[b].row;
			c1 = optimalwall_N[b].column;
			continue;
		}

		if(optimalwall_N[b].row>=r1&&optimalwall_N[b].column<=c1)
		{
			Nwall_Max = optimalwall_N[b].max;
			r1 = optimalwall_N[b].row;
			c1 = optimalwall_N[b].column;
		}

	}
	

		
	fout<<roomNum<<endl;
	fout<<MaxCount<<endl;

	//--------------output--------------------------
	if(Ewall_Max==Nwall_Max)
	{
		if(c1==c)
		{
			fout<<Nwall_Max<<endl;
			fout<<r1<<" "<<c1<<" "<<"N"<<endl;
		}
		else
		{
			fout<<Ewall_Max<<endl;
			fout<<r<<" "<<c<<" "<<"E"<<endl;
		}
	}
	else if(Ewall_Max<Nwall_Max)
	{
		fout<<Nwall_Max<<endl;
		fout<<r1<<" "<<c1<<" "<<"N"<<endl;
	}
	else if(Ewall_Max>Nwall_Max)
	{
		fout<<Ewall_Max<<endl;
		fout<<r<<" "<<c<<" "<<"E"<<endl;
	}
	
	return 0;
}

int Floodfill(int floorplan[50][50],int floodfill[50][50], int n, int m, int roomNum,int M, int N, int flag)
{
	int count = 0;	
	if(floodfill[n][m]==roomNum)
		return 0;
	floodfill[n][m]=roomNum;
	count++;
	if((floorplan[n][m]&4)==0&&m!=M-1&&flag!=1)
	{
		count+=Floodfill(floorplan, floodfill, n,m+1,roomNum, M,N,4);
	}
	if((floorplan[n][m]&1)==0&&m!=0&&flag!=4)
	{
		count+=Floodfill(floorplan, floodfill, n,m-1,roomNum,M,N,1);
	}
	if((floorplan[n][m]&2)==0&&n!=0&&flag!=8)
	{
		count+=Floodfill(floorplan, floodfill, n-1, m, roomNum,M,N,2);
	}
	if((floorplan[n][m]&8)==0&&n!=N-1&&flag!=2)
	{
		count+=Floodfill(floorplan,floodfill, n+1,m,roomNum,M,N,8);
	}
	
	return count;
}    