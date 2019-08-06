#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int next[1000002];
using namespace std ;
void GetNext(char*T, int m)
{
    int a = 0, p = 0;
    next[0] = m;

    for (int i = 1; i < m; i++)
    {
        if (i >= p || i + next[i - a] >= p)
        {
            if (i >= p)
                p = i;

            while (p < m && T[p] == T[p - i])
                p++;

            next[i] = p - i;
            a = i;
        }
        else
            next[i] = next[i - a];
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
	  int sum=0;
	  for(int i=1;i<len;i++)
	  {
//	  	cout<<next[i]<<" ";
	  	if(!next[i])
	  	sum++;
	  	else
	  	{
	  		sum+=next[i]+1;
	  		if(i+next[i]>=len)
	  		
	  		sum--;
		}
	  	
	  }
	  printf("%d\n",sum);
	 }
	return 0;
}
