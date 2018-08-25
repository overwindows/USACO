/*
ID: chen.wu1
PROG: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>

typedef struct bucket_capacity  
{ 
	int used;
    int left;
} BUCKET;

void milk(BUCKET A, BUCKET B, BUCKET C, int* Flag);
void pour(BUCKET& From, BUCKET& To);

void pour(BUCKET& F, BUCKET& T)
{
	int delta = 0;
	if(F.used >= T.left)
		delta = T.left;
	else //F.used < T.left
		delta = F.used;
			
	F.used -= delta;
	F.left += delta;
		
	T.used += delta;
	T.left -= delta;
}

int flag(BUCKET A, BUCKET B, BUCKET C, int* Flag)
{
	int flag = (A.used+10)*10000 + (B.used+10)*100 + (C.used+10);
	if(Flag[flag] > 0 )
		return 0;
	else if(A.used == 0)
		Flag[flag] = 1;
	else
		Flag[flag] = 2;
	//std::cerr<<C.used<<std::endl;
	return 1;
}

void milk(BUCKET _A, BUCKET _B, BUCKET _C, int* Flag)
{
	BUCKET A,B,C;
	
	A = _A;	B = _B;	C = _C;
	
	pour(A,B);
	if(flag(A,B,C,Flag))
		milk(A,B,C,Flag);
	
	A = _A;	B = _B;	C = _C;
	pour(A,C);
	if(flag(A,B,C,Flag))
		milk(A,B,C,Flag);
	
	A = _A;	B = _B;	C = _C;
	pour(B,C);
	if(flag(A,B,C,Flag))
		milk(A,B,C,Flag);
	
	A = _A;	B = _B;	C = _C;
	pour(B,A);
	if(flag(A,B,C,Flag))
		milk(A,B,C,Flag);
	
	A = _A;	B = _B;	C = _C;
	pour(C,A);
	if(flag(A,B,C,Flag))
		milk(A,B,C,Flag);
	
	A = _A;	B = _B;	C = _C;
	pour(C,B);
	if(flag(A,B,C,Flag))
		milk(A,B,C,Flag);
	
	return;
}

int main()
{
	std::ifstream fin("milk3.in");
	std::ofstream fout("milk3.out");
	BUCKET A,B,C;
	
	int a,b,c;
	int* Flag = (int*)malloc(524288 * sizeof(int));
	std::memset(Flag, 0 ,524288 * sizeof(int));
	int Capacity[21] = {0};
	int flag;
	fin>>a>>b>>c;
	
	A.used = 0;
	A.left = a;
	
	B.used = 0;
	B.left = b;
	
	C.used = c;
	C.left = 0;
	
	flag = (A.used+10)*10000 + (B.used+10)*100 + (C.used+10);
	Flag[flag] = 1;
	milk(A,B,C,Flag);
	
	for(int i=101010; i<313131; ++i)
	{
		if(Flag[i] == 1)
			Capacity[(i%100)-10] = 1;
	}
	
	for(int j=0; j<21; ++j)
	{
		if(j == c)
			fout<<j;
		else if(Capacity[j] == 1)
			fout<<j<<" ";
	}
	fout<<std::endl;
	
	free(Flag);
	fin.close();
	fout.close();
}
