/*
kmp算法的考察
要在开头和结尾都出现过，显然这个串的长度不可能大于next[len]。

因为next[len]表示的就是S[1,len]中，前缀和后缀匹配的最长的长度。

然后我们就要去找中间的。

现在我们已经知道S[1,next[len]和S[len-next[len]+1,len]是匹配的了，答案只能比他们更小

对于S[next[len],len-next[len]+1]的部分，我们去找每一个位置对应的next。

最大的那一个next就表示，可以找到的最长的一段既在开头出现又在中间出现的子串。

这个最大值和next[len]的较小值就是答案。
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
