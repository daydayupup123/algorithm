/*
本题要求的是哈夫曼树的带权路径长度
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int vis[26];
int tr[26];
struct HuffmanNode{
	int index;
	int weight;
	int par,lc,rc;
};
bool operator<(const HuffmanNode &node1,const HuffmanNode& node2)
{
	return node1.weight<node2.weight;
}
struct HuffmanTree{
	HuffmanNode *nodes;
	int leafnumber;
};
int select(HuffmanTree &T,int n,int &k1,int &k2)  //选出权值最小的两个叶子结点
{
	int i1=-1,i2=-2;
	for(int  i=0;i<n;i++)
	{
		if(T.nodes[i].par!=-1)
			continue;
		if(i1==-1||T.nodes[i].weight<T.nodes[i1].weight)
		{
			i2=i1;
			i1=i;
		}
		else if(i2==-1||T.nodes[i].weight<T.nodes[i2].weight)
            i2=i;
	}
	k1=min(i1,i2);
	k2=max(i1,i2);
	return 0;
}
int CreateHuffmanTree2(HuffmanTree &T,int leafnumber,int *weights)  //建树
{
     T.nodes=new HuffmanNode[leafnumber+leafnumber-1];
     T.leafnumber=leafnumber;
     for(int i=0;i<leafnumber;i++)
     {
     	T.nodes[i].index=i;
     	T.nodes[i].weight=weights[i];
     	T.nodes[i].par=T.nodes[i].lc=T.nodes[i].rc=-1;
     }
     int sum=0;
     for(int i=0;i<leafnumber-1;i++)
     {
     	int k1,k2;
     	select(T,leafnumber+i,k1,k2);
     	T.nodes[i+leafnumber].weight=T.nodes[k1].weight+T.nodes[k2].weight;
     	T.nodes[i+leafnumber].par=-1;
     	T.nodes[i+leafnumber].lc=k1;
     	T.nodes[i+leafnumber].rc=k2;
     	T.nodes[k1].par=T.nodes[k2].par=i+leafnumber;
     	sum+=T.nodes[i+leafnumber].weight;
     }
     return sum;
}
int DestroyHuffmanTree(HuffmanTree &T)  
{
	delete []T.nodes;
	T.nodes=NULL;
	T.leafnumber=0;
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		int m;
		scanf("%d",&m);
		string str;
		cin>>str;
		int c=0;
		int len=str.length();
        for(int i=0;i<len;i++)  //统计各字符出现的次数
        	vis[str[i]-'a']++;
        
        for(int i=0;i<26;i++)
        	if(vis[i])
        		tr[c++]=vis[i];
        HuffmanTree T;
        int re=CreateHuffmanTree2(T,c,tr);
        // cout<<re<<endl;
        if(c==1)
        {
        	if(tr[0]<=m)
        		puts("yes");
        	else
        		puts("no");
        	continue;
        }
        if(re<=m)
        	puts("yes");
        else
        	puts("no");

        DestroyHuffmanTree(T);
 
	}
	return 0;
}
