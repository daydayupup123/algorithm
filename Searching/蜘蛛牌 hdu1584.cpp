/*dfs
对于i号牌，不管i+1号牌怎么移动，
它的位置一定与某一个i+k（k>=1）相同，
那么与哪一个相同？
答：与这些里第一个没有被访问过的那个相同
（在它之前的那些牌都会压在它的上面）
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
#define inf 0x3f3f3f3f
int a[11];
int vis[11];
int minn;
void dfs(int cc,int sum)
{
	if(cc>=9)
	{
		minn=min(minn,sum);
		return;
	}
	if(sum>minn)
		return;
	for(int i=1;i<10;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
            for(int j=i+1;j<=10;j++)
            {
            	if(!vis[j])
            	{
            	dfs(cc+1,sum+abs(a[i]-a[j]));
            	break;
            	}
            	
            }
            vis[i]=0;

		}
	}
}
int main()
{
	int t;
	int num;
	scanf("%d",&t);
	while(t--)
	{
		minn=inf;
		memset(vis,0,sizeof(vis));
        for(int i=1;i<=10;i++)
        {
        	scanf("%d",&num);
        	a[num]=i;
        }
        dfs(0,0);
        printf("%d\n",minn);
	}
	return 0;
}