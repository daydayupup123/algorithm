/*
扩展kmp。 
最后的结果要用long long。 
*/ 
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int Next[1000002];
using namespace std ;
void GetNext(char*T, int m)
{
    int a = 0, p = 0;
    Next[0] = m;

    for (int i = 1; i < m; i++)
    {
        if (i >= p || i + Next[i - a] >= p)
        {
            if (i >= p)
                p = i;

            while (p < m && T[p] == T[p - i])
                p++;

            Next[i] = p - i;
            a = i;
        }
        else
            Next[i] = Next[i - a];
    }
}

int main()
{
	char str[1000001];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		  scanf("%s",str);
	  int len=strlen(str);
	  GetNext(str,len);
	  long long sum=0;
	  for(int i=1;i<len;i++)
	  {
//	  	cout<<Next[i]<<" ";
	  	if(!Next[i])
	  	sum++;
	  	else
	  	{
	  		sum+=Next[i]+1;
	  		if(i+Next[i]>=len)		
	  		sum--;
		}
//	  	sum += Next[i] + (i + Next[i] != len);
	  }
	  printf("%lld\n",sum);
	 }
	return 0;
}
