/*主要考察的是对优先队列的应用
 priority_queue<int,vector<int>,greater<int> >que3; //小的先出队
 priority_queue<int,vector<int>,less<int> >que4;//大的先出队 默认方式
*/

#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;
struct stone{
	long long pos;
	long long dis;
	friend bool operator<(const stone a,const stone b)
	{
		if(a.pos!=b.pos)
		return a.pos>b.pos;
	    return a.dis>b.dis;
	}
};
int main()
{

     priority_queue<int> que;
     que.push(1);
     que.push(5);
     que.push(4);
     while(!que.empty())
     {
     	cout<<que.top()<<" ";
         que.pop();
     }
    // int t;
    // scanf("%d",&t);
    
    // while(t--)
    // {
       
    //    int n;
    //    scanf("%d",&n);
    //    stone x;
    //    priority_queue<stone> que;
    //    for(int i=0;i<n;i++)
    //    {
    //       scanf("%lld%lld",&x.pos,&x.dis);
    //       que.push(x);
    //    }
    //    long long maxx=0;
    //    int num=1; //用来存储当前遇到的是第几个石子
    //    while(!que.empty())
    //    {
    //    	  // cout<<que.top().pos<<endl;
    //    	  stone temp=que.top();
    //       if(maxx<temp.pos)
    //       	maxx=temp.pos;
    //    	  que.pop();
    //    	  if(num&1)
    //    	  {
    //    	  	stone now;
    //    	  	now.pos=temp.pos+temp.dis;
    //    	  	now.dis=temp.dis;
    //    	  	que.push(now);
    //    	  }
    //    	  num++;
    //    }
    //    printf("%lld\n",maxx);
    // }
	return 0;
}