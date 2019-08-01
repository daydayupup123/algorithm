#include<cstdio>
#include<iostream>
using namespace std;
int exg(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	int r=exg(b,a%b,x,y);
	int t=y;
	y=x-(a/b)*t;
	x=t;
	return r;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
    	int n,b;
    	int a=9973;
    	scanf("%d%d",&n,&b);
    	int x,y;
    	exg(b,a,x,y);
    	x=(x+a)%a;
    	printf("%d\n",n*x%a);
	}
	return 0;
}
