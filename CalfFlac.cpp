/*
ID: chen.wu1
PROG: calfflac
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

#define LENGTH 20000
using namespace std;

int main() {
	
	ifstream fin("calfflac.in");
	ofstream fout("calfflac.out");
	
	char inputPali[LENGTH];
	int inputPaliPos[LENGTH] = {0};
	char postPali[LENGTH];

	memset(inputPali,0, sizeof inputPali);
	char* largestPali = (char *)0; 
	
	fin.getline(inputPali,LENGTH,'\0');
	
	int index = 0;
	int count = 0;
	int ixPos1,ixPos2,ix1,ix2;
	int maxLength1 = 0;	
	int maxLength2 = 0;

	//Prepare Input;
	while (inputPali[count])
	{
		if(isalpha(inputPali[count]))
		{
			postPali[index] = inputPali[count]>90?inputPali[count]:(inputPali[count]+32);
			inputPaliPos[index++] = count;
		}
		count++;
	}
	
	postPali[index] = '\0';

	int len = strlen(postPali);
	
	char* ptrCur = postPali;
	char* ptrOrig = postPali;
	char* ptrPali = (char *)0;


	while ((*ptrCur)!='\0') {
		
			//re-initialization
			ptrPali = ptrCur;
			
			//Scinarios
			ixPos1 = ptrCur - ptrOrig;
										
			//case 1:
			int length1=0;
			while (ixPos1) {
				if(*(ptrPali-length1-1)==*(ptrPali+length1+1)) {
						ixPos1--;
						length1++;
								
				}
				else
					break;
			
			}

			if(maxLength1<length1)
			{
				maxLength1 = length1;
				ix1 = ixPos1;
			}
	
			
			//re-initialization
			ptrPali = ptrCur;
			int length2=0;
			ixPos2 = ptrCur - ptrOrig+1;
		

			//case 2:
			while((ixPos2)) {
				if(*(ptrPali-length2)==*(ptrPali+length2+1)) {
						ixPos2--;
						length2++;
						
				}
				else
					break;
			} 

			if(maxLength2<length2)
			{
				maxLength2 = length2;
				ix2 = ixPos2;
			}
	
			++ptrCur;
	}	
	
	int MaxLength,ixStart,ixEnd;
	
	if(maxLength2<=maxLength1)
	{
		MaxLength = 2*maxLength1+1;
		ixStart = ix1;
		ixEnd = ixStart+MaxLength-1;
	}
	else
	{
		MaxLength = maxLength2*2;
		ixStart = ix2;
		ixEnd = ixStart+MaxLength-1;
	}
	fout<<MaxLength<<endl;
	for(int ix=inputPaliPos[ixStart];ix<=inputPaliPos[ixEnd];ix++)
		fout<<inputPali[ix];
	fout<<endl;

	return 0;
}
