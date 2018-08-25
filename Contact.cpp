/*
ID: chen.wu1
PROG: contact
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

typedef struct pattrens
{
	string pattern;
	int count;
}Patterns;

void check(const string& subStr, int from,int to, Patterns* patterns, int* hashTable,int& count);
long checkSum(const char* str,int length);

int cmp(const void *va, const void *vb)
{
	return int(((Patterns*)vb)->count-((Patterns*)va)->count);
}

int cmp_plus(const void *va, const void *vb)
{
	const char* strTmp1;
	const char* strTmp2;

	strTmp1 = ((string*)va)->c_str();
	strTmp2 = ((string*)vb)->c_str();
	
	if(strlen(strTmp1)>strlen(strTmp2))
		return 1;
	else if(strlen(strTmp1)<strlen(strTmp2))
		return -1;
	else
	{
		return strcmp(strTmp1,strTmp2);
	}
	
}

int main()
{
	ifstream fin("contact.in");
	ofstream fout("contact.out");
	
	int A,B,N;
	string strTmp;
	string Sequence; 
	string subStr;
	int count=0;
	
	int coutSequence = 0;
	int currentCount = 0;
	
//	Patterns patterns[5000];
	Patterns* patterns = new Patterns[7000];
//	int hashTable[98307] = {0};
	int* hashTable = new int[98307];
	string strPattern[1000];
	int index;
	
	for(int x=0;x<98307;x++)
	{
		hashTable[x] = 0;
	}

	fin>>A;
	fin>>B;
	fin>>N;
	
	while(!fin.eof())
	{
		fin>>strTmp;
		Sequence += strTmp;
		strTmp="";
	}
	
	coutSequence = Sequence.size();
	
	/*cout<<Sequence<<endl;*/
	
	for(int i=0;i<coutSequence-A+1;i++)
	{
		if(i+B-1<coutSequence)
		{
			subStr = Sequence.substr(i,B);	
			check(subStr,A,B,patterns,hashTable,count);
		}
		else
		{
			subStr = Sequence.substr(i,coutSequence-i);
			check(subStr,A,coutSequence-i,patterns,hashTable,count);
		}
	}
	
	qsort(patterns,count,sizeof(patterns[0]),cmp);
	
	//Output Result
	for(int x=0;x<count;x++) 
	{
		index = 0;
		
		if(N==0)
			break;
		else
			N--;

		currentCount = patterns[x].count;
		/*fout<<currentCount<<endl;*/
		fout<<currentCount<<endl;
		strPattern[index++] = patterns[x].pattern;
		while(patterns[++x].count==currentCount)
		{
			strPattern[index++] = patterns[x].pattern;
		}
		--x;

		qsort(strPattern,index,sizeof(strPattern[0]),cmp_plus);
		
		for(int n=0;n<index;n++)
		{
			fout<<strPattern[n];
			if((n+1)%6)
			{
				if(n!=index-1)
					fout<<" ";
			}
			else if(n!=index-1)
				fout<<endl;
		}
		fout<<endl;
	}
	
	
	return 0;
}


void check(const string& subStr, int from,int to, Patterns* patterns,int* hashTable,int& count)
{
	const char* sub_c_str;
	int hashcode;
	sub_c_str = subStr.c_str();
	
	if(from == to)
	{	
		hashcode = checkSum(sub_c_str,to);
		
		if(!patterns[hashTable[hashcode]].pattern.compare(subStr))
		{
				patterns[hashTable[hashcode]].count++;
		}
		else
		{
			hashTable[hashcode] = count;
			patterns[count].pattern = subStr;
			patterns[count].count = 1;
			count++;
		}
	}
	else
	{
		hashcode = checkSum(sub_c_str,to);
		
		if(!patterns[hashTable[hashcode]].pattern.compare(subStr))
		{
				patterns[hashTable[hashcode]].count++;
		}
		else
		{
			hashTable[hashcode] = count;
			patterns[count].pattern = subStr;
			patterns[count].count = 1;
			count++;
		}
		
		check(subStr.substr(0,to-1),from,to-1,patterns,hashTable,count);
	}
	
}

long checkSum(const char* str, int length)
{
	long index = (length)*4096;
	long offset = 0;
	for(int m=0;m<length;m++)
	{	
		if(str[m]=='1')
			offset = offset+pow(2.0,m);
	}
	return index+offset;
}