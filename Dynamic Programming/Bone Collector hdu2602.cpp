/*
01背包裸题：
特点是每种物品只有一件，可以选择放与不放。
转移方程为：
f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]} 
(定义f[i][v]表示前i件物品恰放入一个容量为v的背包可以获得的最大价值。) 
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int val[1001],vol[1001];
int dp[1001];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,V;
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&V);
		for(int i=1;i<=n;i++)
		 scanf("%d",&val[i]);
		 for(int i=1;i<=n;i++)
		 scanf("%d",&vol[i]);
		 for(int i=1;i<=n;i++)
		   for(int j=V;j>=vol[i];j--)
		     dp[j]=max(dp[j],dp[j-vol[i]]+val[i]);
		printf("%d\n",dp[V]);
	}
	return 0;
}
