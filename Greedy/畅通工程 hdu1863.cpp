/*相比于Prim算法，Kruskal算法更适合简单图，
用并查集实现*/
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int fat[2000010];
struct node{
	int from,to,dis;
}edge[2000010];
bool cmp(const node &a, const node &b)
{
	return a.dis<b.dis;
}
int father(int x)
{
	if(fat[x]!=x)
		return father(fat[x]);
	else
		return x;
}
void unionn(int x,int y)
{
	fat[father(y)]=father(x);
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(!n) break;
		int tot=0,k=0;
        for(int i=0;i<n;i++)
        	scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].dis);
        sort(edge,edge+n,cmp);
        for(int i=1;i<=m;i++) fat[i]=i; //注意村庄编号是从1开始的
        for(int i=0;i<n;i++)
        {
        	if(k==m-1) break;
        	if(father(edge[i].from)!=father(edge[i].to))
        	{
        		unionn(edge[i].from,edge[i].to);
        		tot+=edge[i].dis;
        		k++;
        	}
        }
        // cout<<k<<endl;
        if(k<m-1)
        	printf("?\n");
        else
        printf("%d\n",tot);
	}
	return 0;
}