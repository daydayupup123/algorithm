/*
定义f[N]为从1到N且满足|pi-pi+1|≤2的排列数，其满足f[i]=f[i-1]+f[i-2]:
1.可打表找规律
2.N-1这个位置有两种情况，N-2或者N-1
等于N-1时，排列数为f[N-1];
等于N-2时，排列数为f[N-3],因为此时N-2位置的数已经定了只能是N-1。

然后很容易发现从x到1以及从y到n的路径是唯一的，所以只需要计算中间的数的排列。 
*/
#include<string>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define mod 998244353
long long f[100001];
int main()
{
    int t;
	scanf("%d",&t);
	f[0]=0;f[1]=1;f[2]=1;
	for(int i=3;i<=100000;i++)
	f[i]=(f[i-1]+f[i-3])%mod;
	while(t--)
	{
		int n,x,y;
		int sum=0;
		scanf("%d%d%d",&n,&x,&y);
		if(x==1&&y==n)
		printf("%lld\n",f[n]);
		else if(x==1||y==n)
		printf("%lld\n",f[y-x]);
		else
		printf("%lld\n",f[y-x-1]); 
	} 
	return 0;
}
