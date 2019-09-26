#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int N=100001;
int n;
struct point
{
float x;
float y;
};
 
float direct(point i,point j,point k)     //计算叉积
{
	return (k.x-i.x)*(j.y-i.y)-(j.x-i.x)*(k.y-i.y);
}
 
int onsegment(point a,point b,point c)   //共线时，判断点是否落在线段上   
{
	float minx=min(a.x,b.x);
	float maxx=max(a.x,b.x);
	float miny=min(a.y,b.y);
	float maxy=max(a.y,b.y);
	return c.x>=minx&&c.x<=maxx&&c.y>=miny&&c.y<=maxy;
}
int f(point p1,point q1,point p2,point q2)
{
float d1=direct(p2,q2,p1);        
float d2=direct(p2,q2,q1);
float d3=direct(p1,q1,p2);
float d4=direct(p1,q1,q2);
if(d1*d2<0&&d3*d4<0)
	return true;
else if(d1==0&&onsegment(p2,q2,p1))
	return true;
else if(d2==0&&onsegment(p2,q2,q1))
	return true;
else if(d3==0&&onsegment(p1,q1,p2))
	return true;
else if(d4==0&&onsegment(p1,q1,q2))
	return true;
return false;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		float x1, y1, x2, y2, x3, y3, x4, y4;
		point a,b,c,d;
		scanf("%f %f %f %f %f %f %f %f", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
		if(f(a,b,c,d)){
			point lowpoin1, lowpoin2;
			if(a.y < b.y){
				lowpoin1 = a;
			}
			else{
				lowpoin1 = b;
			}
			if(c.y < d.y){
				lowpoin2 = c;
			}
			else{
				lowpoin2 = d;
			}
		//	int s1 = x1
			double x = ((x1 - x2) * (x3 * y4 - x4 * y3) - (x3 - x4) * (x1 * y2 - x2 * y1))  
    					/ ((x3 - x4) * (y1 - y2) - (x1 - x2) * (y3 - y4));  
  
			double y = ((y1 - y2) * (x3 * y4 - x4 * y3) - (x1 * y2 - x2 * y1) * (y3 - y4))  
    					/ ((y1 - y2) * (x3 - x4) - (x1 - x2) * (y3 - y4));  
    		printf("%lf %lf\n", x, y);
		}
		else{
			printf("0\n");
		}
		
	}
	cout<<f(a,b,c,d)<<endl; //输出 1 ，即线段相交 
	return 0;
}
