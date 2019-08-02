/*
样例：
1 + 2
4 + 2 * 5 - 7 / 11
0

思路：
栈的应用，因为运算有优先级，在刚开始考虑乘法和除法，如果运算符是加法，则直接把那个数字压入栈里，如果是减法，则把那个数的相反数压入栈里，如果是乘法，则取栈头的数相乘，pop出后把结果push进去，除法同理，最后就把栈中的数字相加就是结果（！！注意表达式中间有空格）
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string equ;
    stack<double> num;
    while(getline(cin,equ))
    {
    	if(equ=="0") break; 
    	double res=0,x;
    	int len=equ.length();
    	int sum=0;
    	int f=0;
    	for(int i=0;i<len;i++)
    	{
    		if(equ[i]==' ')continue;
    		if(equ[i]>='0'&&equ[i]<='9')
    		{
    			sum*=10;
    			sum+=equ[i]-'0';
			}
			else
			{    if(!f)
				{
				 num.push(sum);
				 f=1;	
				}
				 int j=i+2;
				 int t=0;
    			 while(equ[j]>='0'&&equ[j]<='9')
    				{
    					t*=10;
    					t+=equ[j]-'0';
    					j++;
					}
			
				switch(equ[i])
	    		{
	    		     	case '+':
						num.push(t);
	    				break;
	    				
	    				case '-':
	    				num.push(-t);
	    				break;
	    				
	    				case '*':
	    				x=num.top();
						num.pop();
						x*=t;
						num.push(x);
						break;	
						
						case '/':
	    				x=num.top();
						num.pop();
						x/=t;
						num.push(x);
						break;
						 
						default:break;			        
				        
				}
          		i=j-1;
			}
	   	}
		   while(!num.empty())
		   { 
			   res+=num.top();
			   num.pop(); 
	       }
	       printf("%.2lf\n",res);
	   }
	return 0;
}
/*
//下面这个代码感觉更简单
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack> 
using namespace std;
stack<double>num;

int main() {
    int n, i;
    while(scanf("%d", &n)){
        char c;
        c = getchar();
        if(c=='\n' && n==0)
            break;
        num.push(n);
        c = getchar(); 
        double m;
        while(scanf("%d", &n)){
            if(c == '*'){
                m = num.top();
                m*=n;
                num.pop();
                num.push(m);    
            }
            else if(c == '/'){
                m = num.top();
                m/=n;
                num.pop();
                num.push(m);
            }
            else if(c == '+'){
                num.push(n);
            }
            else if(c == '-'){
                num.push(0-n);
            }
            if(getchar()=='\n')    //本行输入完毕 
                break;
            c = getchar();
        } 
        double sum = 0;
        while(!num.empty()){
            sum+=num.top();
            num.pop();         //使用完后栈一定要清空
        }
        printf("%.2lf\n", sum);

    } 
    return 0;
}
 
*/ 
