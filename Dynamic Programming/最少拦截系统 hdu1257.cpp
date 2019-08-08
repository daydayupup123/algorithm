/* 
最长上升子序列的长度等于不下降子序列的个数。

定义dp[i]=以a[i]为末尾的最长上升子序列的长度。

那么，以a[i]为末尾的最长上升子序列有以下两种情形：
1.只包含a[i]的子序列
2.满足j<i并且a[j]<a[i]的以a[j]为结尾的上升子序列末尾，追加上a[i]后得到的子序列
得：dp[i]=max{1,dp[j]+1|j<i且a[j]<a[i]}

*/
#include<bits/stdc++.h>
using namespace std;
int n,a[1000001];
int dp[1000001];
int calc()
{
	memset(dp,0,sizeof(dp));
    int maxx=0;
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
    	dp[i]=1;
    	for(int j=0;j<i;j++)
    		if(a[j]<a[i])
    			dp[i]=max(dp[i],dp[j]+1);
    	maxx=max(dp[i],maxx);
    }
    return maxx;
}
int main()
{
     while(scanf("%d",&n)!=EOF)
     {
           for(int i=0;i<n;i++)
           	scanf("%d",&a[i]);
           int re=calc();
         printf("%d\n",re);
     }
}