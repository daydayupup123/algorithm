/*Nim Game
������ɶ�ʯ����������Ϊ0�������ְܡ� 
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int rocks[200001];
int main()
{
	int m;
	while(scanf("%d",&m)!=EOF)
	{
		if(!m) break;
		int t=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&rocks[i]);
			t^=rocks[i];
		 } 
		 if(t==0)
		 puts("No");
		 else
		 {
		 	puts("Yes");
		 	int ans=0;
		 	for(int i=0;i<m;i++)
		 	{
		 		ans=t^rocks[i];
		 		if(rocks[i]>ans)
		 		printf("%d %d\n",rocks[i],ans);
			 }
		 
		 }
	}
	return 0;
}
