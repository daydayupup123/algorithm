/*
暴力枚举最短串中的字串看是否在所有的串中都存在。
用到了string的查找子串的函数find，
截取子串：substr 
*/
#include<string>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
string xx[100];
bool cmp(string x,string y)
{
	return x.length()<y.length();
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
    	int n;
    	scanf("%d",&n);
    	for(int i=0;i<n;i++)
    	cin>>xx[i];
    	sort(xx,xx+n,cmp);
    	string t=xx[0];
    	string now;
    	int maxlen=0;
    	int len=t.length();
    	for(int i=1;i<=len;i++)
    	  for(int s=0;s<=len-i;s++)
    	    {
    	    	now=t.substr(s,i);
    	    	string re=now;
    	    	reverse(now.begin(),now.end());
//    	    	cout<<re<<" "<<now<<endl;
    	    	int z;
    	    	for(z=1;z<n;z++)
    	    	{
    	    		if(xx[z].find(now)==-1&&xx[z].find(re)==-1)
    	    		break;
				}
//				cout<<"z="<<z<<endl;
				 if(z<n)
				 maxlen=max(maxlen,0);
				 else
				 maxlen=max(maxlen,i);
			}
			printf("%d\n",maxlen);
	}
	return 0;
}
