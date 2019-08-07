/*
最长公共子序列的变形。 
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int dp[2][2005]; 
int point[26];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		string ters;
		cin>>ters;
		for(int i=0;i<n;i++)
		scanf("%d",&point[ters[i]-'a']);
		memset(dp,0,sizeof(dp));
		string gun;
		cin>>gun;
		int len1=gun.length();
		string ord;
		cin>>ord;
		int len2=ord.length();
		int pre=0;
		int now=1;
		for(int i=1;i<=len1;i++)
		{
			for(int j=1;j<=len2;j++)
			{
				if(gun[i-1]==ord[j-1])
				dp[now][j]=dp[pre][j-1]+point[ord[j-1]-'a'];
				else
				dp[now][j]=max(dp[pre][j],dp[now][j-1]);
			}
			now^=1;
			pre=1-now;
		} 
		printf("%d\n",dp[len1&1][len2]);
	}
	return 0;
}
