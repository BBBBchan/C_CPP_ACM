#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

struct point{
double x,y;
};
 
double direct(point i,point j,point k){
	return (k.x-i.x)*(j.y-i.y)-(j.x-i.x)*(k.y-i.y);
}
 
int onsegment(point a,point b,point c)      
{
	double minx=min(a.x,b.x);
	double maxx=max(a.x,b.x);
	double miny=min(a.y,b.y);
	double maxy=max(a.y,b.y);
	return c.x>=minx&&c.x<=maxx&&c.y>=miny&&c.y<=maxy;
}
int f(point p1,point q1,point p2,point q2)
{
double d1=direct(p2,q2,p1);        
double d2=direct(p2,q2,q1);
double d3=direct(p1,q1,p2);
double d4=direct(p1,q1,q2);
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
		double x1, y1, x2, y2, x3, y3, x4, y4;
		point a,b,c,d;
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
		if(f(a,b,c,d)){
			point lowpoint1, lowpoint2,temppoint1, temppoint2;
			int tempx;
			if(a.y <= b.y){
				lowpoint1 = a;
			}
			else{
				lowpoint1 = b;
			}
			if(c.y <= d.y){
				lowpoint2 = c;
			}
			else{
				lowpoint2 = d;
			}
			if(lowpoint1.y >= lowpoint2.y){
				temppoint1 = lowpoint1;
				temppoint2 = lowpoint2;
			}
			else{
				temppoint1 = lowpoint2;
				temppoint2 = lowpoint1;
			}

			double x = ((a.x - b.x) * (c.x * d.y - d.x * c.y) - (c.x - d.x) * (a.x * b.y - b.x * a.y))  
    					/ ((c.x - d.x) * (a.y - b.y) - (a.x - b.x) * (c.y - d.y));  
  
			double y = ((a.y - b.y) * (c.x * d.y - d.x * c.y) - (a.x * b.y - b.x * a.y) * (c.y - d.y))  
    					/ ((a.y - b.y) * (c.x - d.x) - (a.x - b.x) * (c.y - d.y));  
    		//printf("%lf %lf\n", x, y);
    		point finpoint;
    		finpoint.y = temppoint1.y;
    		//printf("%lf %lf %lf %lf\n", temppoint1.x, temppoint1.y, temppoint2.x, temppoint2.y);
    		if(y == temppoint2.y){
    			finpoint.x = temppoint2.x;
    		}
    		else{
    			finpoint.x = ((temppoint2.x-x)/(temppoint2.y-y)) * (temppoint1.y-y) + x;
    		}
    	//	printf("%lf %lf\n", finpoint.x, finpoint.y);
    		double ans1 = 0.5*(x*temppoint1.y - temppoint1.x*y + temppoint1.x*finpoint.y - finpoint.x*temppoint1.y + finpoint.x*y-x*finpoint.y);
    		if(ans1 < 0){
    			ans1*= -1;
    		}
    		//printf("%.2lf\n", ans1);
    		//double ans = (x*temppoint1.y-x*finpoint.y+temppoint1.x*finpoint.y- temppoint1.x*y +finpoint.x*y- temppoint1.x*temppoint1.y);
		
    		if(a.y >= b.y){
				lowpoint1 = a;
			}
			else{
				lowpoint1 = b;
			}
			if(c.y >= d.y){
				lowpoint2 = c;
			}
			else{
				lowpoint2 = d;
			}
			if(lowpoint1.y <= lowpoint2.y){
				temppoint1 = lowpoint1;
				temppoint2 = lowpoint2;
			}
			else{
				temppoint1 = lowpoint2;
				temppoint2 = lowpoint1;
			}

			finpoint.y = temppoint1.y;
    		//printf("%lf %lf %lf %lf\n", temppoint1.x, temppoint1.y, temppoint2.x, temppoint2.y);
    		if(y == temppoint2.y){
    			finpoint.x = temppoint2.x;
    		}
    		else{
    			finpoint.x = ((temppoint2.x-x)/(temppoint2.y-y)) * (temppoint1.y-y) + x;
    		}
    	//	printf("%lf %lf\n", finpoint.x, finpoint.y);
    		double ans2 = 0.5*(x*temppoint1.y - temppoint1.x*y + temppoint1.x*finpoint.y - finpoint.x*temppoint1.y + finpoint.x*y-x*finpoint.y);
    		if(ans2 < 0){
    			ans2*= -1;
    		}
    	//	printf("%.2lf\n", ans2);

    		printf("%.2f\n", ans1+ans2);
		}
		else{
			printf("0.00\n");
		}
		
	}
	return 0;
}
