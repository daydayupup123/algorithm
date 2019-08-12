/*
最长公共子序列。

1、
  对线性序列：
	if(val[i]==val[j])
	    dp[i][j]=dp[i+1][j-1]+2;
	else
	    dp[i][j]=max(dp[i][j-1],dp[i+1][j])。
(dp[i][j]表示[i,j]这段序列所能组成回文子序列的最大长度)

2、
  对本题：
	将序列复制两倍，然后计算dp。
	这时我们枚举一只兔子的起点i.
	由于不能一圈，另一只兔子最多站到i+n-1的位置。所以取dp[i][i+n-1]的最大值即可。
	还有种可能就是两只兔子站在同一块石头上,这时由兔子于站在回文序列的两端,
	所以起点和终点值相同.就要利用到dp[i][i+n]-1(一个点被重复计算)。
	
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2010][2010];
int a[2010];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(!n) break;
		memset(dp,0,sizeof(dp));
		int m=2*n;
           for(int i=0;i<n;i++)
           {
           	   scanf("%d",&a[i]);
           	   a[i+n]=a[i];
           }

           for(int i=0;i<m;i++)
           	dp[i][i]=1;
       
         for(int i=m-2;i>=0;i--)
        	for(int j=i+1;j<m;j++)
        		if(a[i]==a[j])
        			dp[i][j]=dp[i+1][j-1]+2;
        		else
        			dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
         int ans=1;
         for(int i=0;i<n;i++)
         {
         	ans=max(ans,dp[i][i+n-1]);
         	ans=max(ans,dp[i][i+n]-1);
         }
         printf("%d\n",ans);
	} 
	return 0;
}