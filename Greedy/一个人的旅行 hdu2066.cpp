/*
Dijstra的应用：
可以把草儿的家当作0，其到相邻村子的距离为0，然后用一次Dijstra求出草儿家到各个村子的距离，再取最小值
*/
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int inf=1<<30;
int mp[1111][1111];
int vis[1111];
int de[1111];
int s[1111];
int shortest[1111];
int n;
int T,S,D;
void dijstra()
{
    
     memset(vis,0,sizeof(vis));
     vis[0]=1;
     for(int i=0;i<=n;i++)
        shortest[i]=mp[0][i];
        
    
     for(int i=0;i<n;i++)
     {
         int minn=inf;
         int pos=0;    //因为这个pos的初始值wa了好几次，注意如果找不到合适的pos的话，他的值应该是0而不是-1
        for(int j=1;j<=n;j++)
        {
               if(shortest[j]==inf||vis[j]) continue;
                if(minn>shortest[j])
                {
                        minn=shortest[j];
                        pos=j;
                }
        }
        vis[pos]=1;
       
        for(int j=1;j<=n;j++)
        {
                if(vis[j]||mp[pos][j]==inf||shortest[pos]==inf) continue;
                if(mp[pos][j]+shortest[pos]<shortest[j])
                        shortest[j]=mp[pos][j]+shortest[pos];
        }
     }
    
}
int main()
{
	
        while(~scanf("%d%d%d",&T,&S,&D))
        {
              
               n=0;
                for(int i=0;i<=1110;i++)
                {
                         for(int j=0;j<=1110;j++)
                             mp[i][j]=inf;
                     mp[i][i]=0;
                        
                }
                       
                        while(T--)
                        {
                                int x,y,z;
                                scanf("%d%d%d",&x,&y,&z);
                                n=max(max(n,x),y);
                                if(mp[x][y]>z)
                                mp[x][y]=mp[y][x]=z;
                               
                        }
                      int minn=inf;
                      
                        for(int i=0;i<S;i++)
                        {
                                scanf("%d",&s[i]);
                                mp[0][s[i]]=mp[s[i]][0]=0;
                        }
                        for(int i=0;i<D;i++)
                                scanf("%d",&de[i]);
                        dijstra();
                        
                        for(int i=0;i<D;i++)
                                minn=min(minn,shortest[de[i]]);
                        printf("%d\n",minn);
        }
	return 0;
}