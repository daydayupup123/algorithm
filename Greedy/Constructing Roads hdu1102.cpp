/*
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
#define inf 0x3f3f3f3f
int mp[101][101];
int dis[101];
int vis[101];
int prim(int n)
{
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	int sum=0;
	for(int j=1;j<n;j++)
		dis[j]=mp[0][j];
	for(int i=1;i<n;i++)
	{
         int k=-1;
         int minn=inf;
         for(int j=0;j<n;j++)
         	if(!vis[j])
         	{
         		if(minn>dis[j])
         		{
         			k=j;
         			minn=dis[j];
         		}
         	}
         vis[k]=1;
         sum+=dis[k];
         for(int j=0;j<n;j++)
         {
         	if(vis[j]) continue;
            if(mp[k][j]<dis[j])
            {
            	dis[j]=mp[k][j];
            }
         }
              
	}
	return sum;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&mp[i][j]);
		int m;
		scanf("%d",&m);
		while(m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			mp[a-1][b-1]=mp[b-1][a-1]=0;//已经建好的路就不用管了，把他们的距离设为0
		}
		// for(int i=0;i<n;i++)
		// {
		// 	for(int j=0;j<n;j++)
		// 		printf("%d ",mp[i][j]);
		// 	cout<<endl;
		// }
		printf("%d\n",prim(n));
	}
	return 0;
}