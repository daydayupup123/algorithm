/*
����f[N]Ϊ��1��N������|pi-pi+1|��2����������������f[i]=f[i-1]+f[i-2]:
1.�ɴ���ҹ���
2.N-1���λ�������������N-2����N-1
����N-1ʱ��������Ϊf[N-1];
����N-2ʱ��������Ϊf[N-3],��Ϊ��ʱN-2λ�õ����Ѿ�����ֻ����N-1��

Ȼ������׷��ִ�x��1�Լ���y��n��·����Ψһ�ģ�����ֻ��Ҫ�����м���������С� 
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
