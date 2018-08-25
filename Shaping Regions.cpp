/*
ID: chen.wu1
PROG: rect1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

typedef struct lineTreeNode LineTreeNode;

typedef struct rect
{
	int llx;
	int lly;
	int urx;
	int ury;
	int color;
	int priority;
}Rect;

struct lineTreeNode
{
	int left;
	int right;
	int color;
	int priority;
	bool access;
	LineTreeNode* ptr_lfchild;
	LineTreeNode* ptr_rtchild;
};

int cmp(const void *va, const void *vb)
{
	return (*(int*)va)-(*(int*)vb);
}

int cmp2(const void *va, const void *vb)
{
	return ((rect*)vb)->priority-((rect*)va)->priority;
}

LineTreeNode* lines_treeBuild(int l, int r);
void lines_treeInsert(Rect& rect,LineTreeNode* root,int width,int* areaColor);
void reset_tree(LineTreeNode *root);

int main()
{
	ifstream fin("rect1.in");
	ofstream fout("rect1.out");

	LineTreeNode* LineTree; 

	int x_coord[2000];
	int y_coord[2000];

	Rect rect[2500]; 
	int areaColor[2500];

	int llx;
	int lly;
	int urx;
	int ury;
	int color;

	int Nums;

	int width;
	int height;

	fin>>width;
	fin>>height;
	fin>>Nums;

	areaColor[1] = width*height;

	for(int i=0,n=0;i<Nums;++i,n+=2)
	{
		fin>>llx;
		fin>>lly;
		fin>>urx;
		fin>>ury;
		fin>>color;

		rect[i].llx=llx;
		rect[i].lly=lly;
		rect[i].urx=urx;
		rect[i].ury=ury;
		rect[i].color=color;
		rect[i].priority=i+1;

		x_coord[n] = llx;
		x_coord[n+1] = urx;

		y_coord[n]=lly;
		y_coord[n+1]=ury;
	}

	qsort(x_coord,2*Nums,sizeof(x_coord[0]),cmp);
	qsort(y_coord,2*Nums,sizeof(y_coord[0]),cmp);

	qsort(rect,Nums,sizeof(rect[0]),cmp2);

	LineTree = lines_treeBuild(y_coord[0],y_coord[2*Nums-1]);

	for(int j=0;j<2*Nums-1;j++)
	{
		if(x_coord[j]==x_coord[j+1])
			continue;

		for(int k=0;k<Nums;k++)
		{
			if(x_coord[j]>=rect[k].llx&&x_coord[j+1]<=rect[k].urx)
				lines_treeInsert(rect[k],LineTree,x_coord[j+1]-x_coord[j],areaColor);
		}
		reset_tree(LineTree);
	}

	for(int k=2;k<2500;k++)
	{
		if(areaColor[k]==0)
			continue; 
		areaColor[1]-=areaColor[k];
	}

	fout<<"1"<<" "<<areaColor[1]<<endl;
	for(int f=2;f<2500;f++)
	{
		if(areaColor[f]==0)
			continue; 

		fout<<f<<" "<<areaColor[f]<<endl;
	}

	return 0;
}

LineTreeNode* lines_treeBuild(int l, int r)
{
	LineTreeNode* root = (LineTreeNode*)malloc(sizeof(LineTreeNode));
	root->left = l;
	root->right = r;
	root->color = 1;
	root->priority = 0;
	root->access=false;
	if(r-l>1)
	{
		int k = (l+r)/2;
		root->ptr_lfchild = lines_treeBuild(l,k);
		root->ptr_rtchild = lines_treeBuild(k,r);
	}
	else
	{
		root->ptr_lfchild = NULL;
		root->ptr_rtchild = NULL;
	}
	return root;
}


void lines_treeInsert(Rect& rect,LineTreeNode* root,int width,int* areaColor)
{
	if(root)
	{
		if(!root->access&&rect.lly<=root->left&&root->right<=rect.ury)
		{
			if(!root->priority)
			{
				root->color = rect.color;
				root->priority = rect.priority;
				if(root->color!=1)
					areaColor[root->color]+=(root->right-root->left)*width;
			}
		}
		else 
		{	
			root->access=true;
			if(root->priority==0&&rect.lly<(root->left+root->right)/2)
				lines_treeInsert(rect,root->ptr_lfchild,width,areaColor);
			if(root->priority==0&&rect.ury>(root->left+root->right)/2)
				lines_treeInsert(rect,root->ptr_rtchild,width,areaColor);
		}
	}
}

void reset_tree(LineTreeNode *root)
{
	if(root)
	{
		if(root->access)
		{
			reset_tree(root->ptr_lfchild);
			reset_tree(root->ptr_rtchild);
		}
		root->color = 1;
		root->priority=0;
		root->access = false;
	}
}