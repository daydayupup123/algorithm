/*
字典树参考博客：
https://blog.csdn.net/weixin_39778570/article/details/81990417
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX_NODE=1000000+10;
const int CHARSET=26;
int trie[MAX_NODE][CHARSET]={0};
int color[MAX_NODE]={0};
int k=1;
void insert(char *w)//trie中插入字符串
{
	int len=strlen(w);
	int p=0;
	for(int i=0;i<len;i++)
	{
		int c=w[i]-'a';
		if(!trie[p][c])
		{
			trie[p][c]=k;
			k++;
		}
		p=trie[p][c];
	}
	color[p]=1;
}
int search(char *s)//trie中查找是否存在某字符串
{
	int len=strlen(s);
	int p=0;
	for(int i=0;i<len;i++)
	{
		int c=s[i]-'a';
		if(!trie[p][c])return 0;
		p=trie[p][c];
	}
	return color[p]==1;
}
int main()
{
    int t,q;
    char s[20];
    scanf("%d%d",&t,&q);
    while(t--)
    {
    	scanf("%s",s);
    	insert(s);
    }
    while(q--)
    {
    	scanf("%s",s);
    	if(search(s))
    		puts("YES");
    	else
    		puts("NO");
    }
	return 0;
}