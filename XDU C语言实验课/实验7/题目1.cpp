#include <stdio.h>
struct fushu{
	int a;
	int b;
}p,q;
void sum(struct fushu p, struct fushu q){
	struct fushu s;
	s.a =  p.a + q.a;
	s.b =  p.b + q.b;
	if(s.a == 0 && s.b == 0)
		printf("0\n");
		else if(s.a != 0 && s.b == 0)
			printf("%d\n",s.a);
		else if(s.a == 0 && s.b != 0)
			printf("%di\n",s.b);
		else 
			printf("%d + %di\n",s.a, s.b);
}
void jianfa(struct fushu p, struct fushu q){
	struct fushu j;
	j.a = p.a - q.a;
	j.b = p.b - q.b;
	if(j.a == 0 && j.b == 0)
		printf("0\n");
	else if(j.a != 0 && j.b == 0)
		printf("%d\n",j.a);
	else if(j.a == 0 && j.b != 0)
		printf("%di\n",j.b);
	else 
		printf("%d + %di\n",j.a, j.b);

}
void chengfa(struct fushu p, struct fushu q){
	struct fushu c;
	c.a = p.a  * q.a - p.b * q.b;
	c.b = p.a * q.b + p.b * q.a;
	if(c.a == 0 && c.b == 0)
		printf("0\n");
	else if(c.a != 0 && c.b == 0)
		printf("%d\n",c.a);
	else if(c.a == 0 && c.b != 0)
		printf("%di\n",c.b);
	else 
		printf("%d + %di\n",c.a, c.b);	

}
int chufa(struct fushu p, struct fushu q){
	struct fushu c;
	int x;
	if(q.a == 0 && q.b == 0){
		printf("illeagle\n");
		return 0;
	}
	c.a = p.a  * q.a - p.b * q.b;
	c.b = p.a * q.b + p.b * q.a;
	x = q.a*q.a + p.a*p.a;
	if(c.a == 0 && c.b == 0)
		printf("0\n");
	else if(c.a != 0 && c.b == 0)
		printf("%d/%d\n",c.a,x);
	else if(c.a == 0 && c.b != 0)
		printf("%di/%d\n",c.b,x);
	else 
		printf("(%d + %di)/%d\n",c.a, c.b, x);

}
int main(){
	scanf("%d %d", &p.a, &p.b);
	scanf("%d %d", &q.a, &q.b);
	sum(p,q);
	jianfa(p,q);
	chengfa(p,q);
	chufa(p,q);

	return 0; 
}