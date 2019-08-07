/*
dp[i][j] ��ʾ��i��¥�� ʣ��j����ʱ�� ����Ҫȷ��K ����Ĵ���

��ô����Щ¥����

���ǿ���ѡ����k��(1<= k <= i)��

������������Ƹ�����

(1)���ƣ� ���ų�����k�㣬ʣ��i-k�� ,��ת��Ϊ dp[i - k][j]

(2)���� ��ʣ��i - 1�㣬 ��ʣk - 1�� , ת��Ϊ dp[i - 1][ k - 1]

Ȼ�����������������Զ����ض��� i,j�У� 

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
