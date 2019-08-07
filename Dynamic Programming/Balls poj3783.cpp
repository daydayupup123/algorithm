/*
dp[i][j] 表示有i层楼， 剩余j个球时， 最坏情况要确定K 所需的次数

那么在这些楼层里

我们可以选择在k层(1<= k <= i)扔

有两种情况，破跟不破

(1)不破， 则排除掉了k层，剩余i-k层 ,则转化为 dp[i - k][j]

(2)破了 则剩余i - 1层， 球剩k - 1个 , 转化为 dp[i - 1][ k - 1]

然后由于是最坏情况，所以对于特定的 i,j有： 

dp[i][j] = min(dp[i][j], max(dp[i - k][j], dp[k - 1][ j - 1]) + 1 )

*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
#define inf 0x3f3f3f3f
int dp[1001][51];
void calc()
{
	for(int i=1;i<=1000;i++)
	for(int j=1;j<=50;j++)
	dp[i][j]=inf;
	for(int i=1;i<=1000;i++)
	dp[i][1]=i;
	for(int j=1;j<=50;j++)
	dp[1][j]=1;
	for(int i=1;i<=1000;i++)
	for(int j=2;j<=50;j++)
	for(int k=1;k<=i;k++)
	dp[i][j]=min(dp[i][j],max(dp[k-1][j],dp[i-k][j-1])+1);
}
int main()
{
	int p;
	scanf("%d",&p);
	calc();
	while(p--)
    {
    	int o,b,s;
    	scanf("%d%d%d",&o,&b,&s);
    	printf("%d %d\n",o,dp[s][b]);
	}
	return 0;
}
