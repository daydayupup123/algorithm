/*因为n太大，所以要用Miller-Rabin进行素数的判断。
不是素数的话要用Pollar-rho算法对n进行素因子的分解。
最好用快速乘。*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<time.h>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 111
int Times=20;
long long mod_mul(long long a,long long b,long long p) //快速乘 
{
	
	long long ans=0;
	a%=p;
	b%=p;
	if(a>b) swap(a,b);
	while(b)
	{
		if(b&1) ans=(ans+a)%p;
		a=(a+a)%p;
		b>>=1;
	}
	return ans;
}
long long mod_pow(long long a,long long b,long long p) //快速幂 
{
	long long ans=1;
	a%=p;
	while(b)
	{
		if(b&1) ans=mod_mul(ans,a,p);
		a=mod_mul(a,a,p);
		b>>=1;
	}
	return ans;
}
bool witness(long long a,long long n)
{
	long long m=n-1;
	int j=0;
	while((m&1)==0)
	{
		j++;
		m>>=1;
	}
	long long x=mod_pow(a,m,n);
	if(x==1||x==n-1)
	return 0;
	while(j--)
	{
		x=(x*x)%n;
		if(x==(n-1))
		  return 0;
	}
	return 1;
}
bool Miller_Rabin(long long n)//判断n是否为素数 
{
	srand(time(0));
	if(n<2)
	 return 0;
	if(n==2)
	 return 1;
	if((n&1)==0)
	 return 0;
	for(int i=0;i<Times;i++)
	{
		long long a=rand()%(n-1)+1;
		if(witness(a,n))
		  return 0;
	}
	return 1;
}
long long factor[maxn];
int res;

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	if(a<0)return gcd(-a,b);
	return gcd(b,a%b);
}
long long Pollar_Rho(long long x,long long c)
{
	long long i=1,k=2;
	long long x0=rand()%x;
	long long y=x0;
	while(1)
	{
		i++;
		x0=(mod_mul(x0,x0,x)+c)%x;
		long long d=gcd(y-x0,x);
		if(d!=1&&d!=x) return d;
		if(y==x0) return x;
		if(i==k)
		{
			y=x0;
			k+=k;
		}
	}
}
void Find_Factor(long long n)//对n进行素因子的分解 
{
	if(Miller_Rabin(n)) 
	{
		factor[res++]=n;
		return;
	}
	long long p=n;
	while(p>=n) p=Pollar_Rho(p,rand()%(n-1)+1);
	Find_Factor(p);
	Find_Factor(n/p);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,ans;
		scanf("%lld",&n);
		if(Miller_Rabin(n))
		{
			printf("Prime\n");
			continue;
		}
		res=0;
		Find_Factor(n);
		ans=factor[0];
		for(int i=1;i<res;i++)
		  ans=min(ans,factor[i]);
		printf("%lld\n",ans); 
	}
	return 0;
} 
