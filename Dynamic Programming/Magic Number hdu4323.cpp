/*最短编辑距离

设所给的两个字符串为A[1:m]和B[1:n]。定义D[i][j]=d(A[1:i],B[1,j])。单字符a,b间的距离定义为：
d(a,b)=0 (a=b)
d(a,b)=1(a!=b)

考察从字符串A[1:i]到字符串B[1:j]的变换。可分成以下几种情况：
（1）字符A[i]改为字符B[j]；需要d(A[i],B[j])次操作。
（2）删除字符A[i]；需要1次操作。
（3）插入字符B[j]；需要1次操作。
因此，D[i][j]可递归地计算如下。

D[i][j]=min{D[i-1][j-1]+d(A[i],B[j]),D[i-1][j]+1,D[i][j-1]+1}
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int dp[11][11];
string x[1501];
int calc(string t1,string t2)
{
	int len1=t1.length();
	int len2=t2.length();
	for(int i=0;i<=len2;i++)
		dp[0][i]=i;
	for(int i=0;i<=len1;i++)
		dp[i][0]=i;
	for(int i=1;i<=len1;i++)
		for(int j=1;j<=len2;j++)
		{
			int f=0;
			if(t1[i-1]==t2[j-1])
				f=0;
			else
				f=1;
			dp[i][j]=min(dp[i-1][j-1]+f,dp[i-1][j]+1);
			dp[i][j]=min(dp[i][j],dp[i][j-1]+1);

		}
		return dp[len1][len2];
}
int main()
{
	int t;
	scanf("%d",&t);
	int ca=1;
	while(t--)
	{
       int n,m;
       scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
       	cin>>x[i];
        printf("Case #%d:\n",ca++);
       while(m--)
       {
       	  string query;
       	  int thre;
       	  cin>>query;
          scanf("%d",&thre);

          int re=0;
          for(int i=1;i<=n;i++)
          if(calc(query,x[i])<=thre)
          	re++;
          printf("%d\n",re);
       }

	}
	return 0;
}