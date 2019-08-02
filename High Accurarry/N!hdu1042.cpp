//大数乘法 
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
#define maxn 40000 
int a[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
    	memset(a,0,sizeof(a)); //无论何时，初始化最重要！！！ 
    	a[0]=1;
    	for(int i=2;i<=n;i++)
    	{
    		int c=0;
    		for(int j=0;j<maxn;j++)
    		{
    			int s=a[j]*i+c;
    			a[j]=s%10;
    			c=s/10;
			}
		}
		int j;
		for(j=maxn-1;j>=0&&a[j]==0;j--);
		for(;j>=0;j--)
		printf("%d",a[j]);
		printf("\n");
	}
	return 0;
}

