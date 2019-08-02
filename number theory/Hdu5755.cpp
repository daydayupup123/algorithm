/*
������
Sample Input

2 
2 3 
2 1 2 
0 2 0 
3 3 
1 0 1 
0 1 0 
1 0 1

Sample Output

1 
1 2 
5 
1 1 
1 3 
2 2 
3 1 
3 3
 
�ⷨ������ÿ��λ�ñ仯�Ĵ������ǿ�����ɢ����������Ϊһ��δ֪�����������������ǿ��Խ���һ�������顣�������ǿ��Խ���n*m�������飬Ȼ���˹��Ԫ������������з��̵�һ��ͨ�⡣����λ���ϵĲ��������� 
�±߸����˵�һ�������ľ��� 
2 1 0 1 0 0 1 
1 2 1 0 1 0 2 
0 1 2 0 0 1 1 
1 0 0 2 1 0 0 
0 1 0 1 2 1 1 
0 0 1 0 1 2 0

�ڶ��������ľ��� 
2 1 0 1 0 0 0 0 0 2 
1 2 1 0 1 0 0 0 0 0 
0 1 2 0 0 1 0 0 0 2 
1 0 0 2 1 0 1 0 0 0 
0 1 0 1 2 1 0 1 0 2 
0 0 1 0 1 2 0 0 1 0 
0 0 0 1 0 0 2 1 0 2 
0 0 0 0 1 0 1 2 1 0 
0 0 0 0 0 1 0 1 2 2
*/ 
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int msz=10000;
const int mod=3;
const double eps=1e-8;
const int MAXN=1000;
int a[MAXN][MAXN];//�洢��Ŀ������ת���ɵ�������� 
int x[MAXN];//���̽�
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}
int Gauss(int equ,int var)//equΪ����������varΪ������ ,�����Ǹ�˹��Ԫ�㷨����· 
{
	int max_r,col,k;
	for(k=0,col=0;k<equ&&col<var;++k,++col)
	{
	   max_r=k;
	   for(int i=k+1;i<equ;i++)
	      if(abs(a[i][col])>abs(a[max_r][col])) max_r=i;
	   if(a[max_r][col]==0)
	   {
	   	--k;
		continue;
       }	
	   if(max_r!=k)
	     for(int j=col;j<var+1;j++)
		    swap(a[k][j],a[max_r][j]);
	   for(int i=k+1;i<equ;i++)
	   {
	   	  if(a[i][col]!=0)
	   	  {
	   	  	int LCM=lcm(abs(a[i][col]),abs(a[k][col]));
		    int ta=LCM/abs(a[i][col]);
			int tb=LCM/abs(a[k][col]);
			if(a[i][col]*a[k][col]<0) tb=-tb;
			for(int j=col;j<var+1;j++)
			 a[i][j]=((a[i][j]*ta-a[k][j]*tb)%mod+mod)%mod;
		 }
	   }  	
	} 
	for(int i=var-1;i>=0;i--)
	{
		if(!a[i][i]) continue;
		int t=a[i][var];
		for(int j=i+1;j<var;j++)
		{
			if(a[i][j]!=0)
			{
				t-=a[i][j]*x[j];
				t=(t%mod+mod)%mod;
			}
		}
		x[i]=(t*a[i][i])%mod;
	}
	return 0;
}
pair<int,int> out[2333];
int solve(int equ,int var,int n,int m)
{
	int t=Gauss(equ,var);
	int ans=0;
	for(int i=0;i<var;i++)
	{
		while(x[i])
		{
			out[ans].first=i/m+1;
			out[ans++].second=i%m+1;
			x[i]--;
		}
	 } 
	 return ans;
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void init(int n,int m)//��ʼ������ԭ����ת���ɷ����飬�����Ա���Ϊÿ��λ�ñ仯�Ĵ��� 
{
	int pos;
	int xx,yy;
	memset(a,0,sizeof(a));
	memset(x,0,sizeof(x));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			pos=i*m+j;
			scanf("%d",&a[pos][n*m]);
			a[pos][n*m]=((mod-a[pos][n*m])%mod+mod)%mod;
			for(int k=0;k<4;k++)
			{
				xx=i+dx[k];
				yy=j+dy[k];
				if(xx<0||xx>=n||yy<0||yy>=m)continue;
				a[pos][xx*m+yy]=1;
			}
			a[pos][pos]=2;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	int n,m;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		init(n,m);
		int ans=solve(n*m,n*m,n,m);
		printf("%d\n",ans);
		for(int i=0;i<ans;i++)
		{
			printf("%d %d\n",out[i].first,out[i].second);
		}
	}
	return 0;
}
