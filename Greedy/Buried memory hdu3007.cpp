/*模拟退火算法+最小圆覆盖*/
#include<bits/stdc++.h>
using namespace std;
const int N = 55;
#pragma warning(disable:4996);
const double eps = 1e-8;
const double INF = 1e19;
struct Point
{
	double x, y;
}p[N];
int n;
double x, y, r;
double dis(Point a, Point b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y,2));
}
void SA()
{
	double T = 10;
	double delt = 0.98;
	Point a = p[0];
	 r = INF;
	while (T > eps)
	{
		int  k = 0;
		double d = 0;
		for (int i = 0; i < n; i++)
		{
			double f = dis(a, p[i]);
			if (f>d)
			{
				d = f;
				k = i;
			}
		}
		a.x += (p[k].x - a.x) / d * T;
		a.y += (p[k].y - a.y) / d * T;
		r = min(r, d);
		T *= delt;
	}
	x = a.x, y = a.y;
}
int main()
{
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		SA();
		printf("%.2lf %.2lf %.2lf\n", x, y, r);
	}
}
