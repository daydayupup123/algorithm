/*
kmp�㷨�Ŀ���
Ҫ�ڿ�ͷ�ͽ�β�����ֹ�����Ȼ������ĳ��Ȳ����ܴ���next[len]��

��Ϊnext[len]��ʾ�ľ���S[1,len]�У�ǰ׺�ͺ�׺ƥ�����ĳ��ȡ�

Ȼ�����Ǿ�Ҫȥ���м�ġ�

���������Ѿ�֪��S[1,next[len]��S[len-next[len]+1,len]��ƥ����ˣ���ֻ�ܱ����Ǹ�С

����S[next[len],len-next[len]+1]�Ĳ��֣�����ȥ��ÿһ��λ�ö�Ӧ��next��

������һ��next�ͱ�ʾ�������ҵ������һ�μ��ڿ�ͷ���������м���ֵ��Ӵ���

������ֵ��next[len]�Ľ�Сֵ���Ǵ𰸡�
*/
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int nextval[1000002];
char str[1000002];
void getnext()
{
	int k=-1;
	nextval[0]=-1;
	int len=strlen(str);
	for(int i=1;i<=len;i++)
	{
		while(k!=-1&&str[k]!=str[i-1])
		k=nextval[k];
		k++;
		
		nextval[i]=k;
	
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{    scanf("%s",str);
		int len=strlen(str);
		getnext();
//		if(str[nextval[len-1]]==str[len-1])
//		nextval[len]=nextval[len-1]+1;
//		else
//		nextval[len]=0;
//		for(int i=0;i<=len;i++)
//		cout<<nextval[i]<<" ";
//		cout<<endl;
//         cout<<nextval[len]<<endl;
         int y=len-nextval[len]+1;
         int re=0;
        for(int i=nextval[len];i<=y;i++)
        re=max(re,nextval[i]);
//        cout<<re<<endl;
        printf("%d\n",min(re,nextval[len]));
	}
	return 0;
}
