#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <cstdio>
#include <algorithm>
typedef class OutMapPix
{
    public:
        int pos;    //OutMap中每个像素点的顺序位置，pos从1开始
        int code;   //OutMap中每个像素点对应InMap的编码
}pix;
int a[1005][2];
int pos_sum = 0, count= 0,t;
pix out[8000];
int GetValue(int pos){
	int i=0,p=0;
	while(p<pos){
		p+=a[i][1];
		i++;
	}
	return a[i-1][0];
}
int Getcode(int pos){
	int code = GetValue(pos),max=0;
	int x = (pos-1)/t;
	int y = (pos-1)%t;
	for(int i = x-1; i <= x+1; i++)
		for(int j = y-1; j <= y+1; j++){
			int tpos = i*t+j;
			if(i<0 || j < 0 || j >= t || tpos==pos-1 || tpos >= pos_sum)
				continue;
			int tcode = GetValue(tpos+1);
			if(max<abs(tcode-code))
				max = abs(tcode-code);
		}
	return max; 
}
int cmp(const void* a,const void* b)
{
    pix* x=(pix*)a;
    pix* y=(pix*)b;
    return x->pos - y->pos;
}
int main(int argc, char const *argv[])
{
	while(scanf("%d", &t) != EOF && t){
		int pairv,pairt;
		pos_sum = 0;
		count = 0;
		while(scanf("%d %d", &pairv, &pairt) &&pairt){
			a[count][0] = pairv;
			a[count][1] = pairt;
			count++;
			pos_sum += pairt;
		}
		printf("%d\n", t);
		int pos=1,cnt=0;
		for(int i =0;i<=count;i++){
			int x = (pos-1)/t;
			int y = (pos-1)%t;
			for(int m = x-1; m <=x+1; m++)
				for(int n = y-1; n<=y+1; n++){
					int pos_temp = m*t+n;
					if(m<0 || n < 0 || n >= t || pos_temp >= pos_sum)
						continue;
					out[cnt].pos = pos_temp+1;
					out[cnt].code = Getcode(pos_temp+1);
					cnt++;
				}
			pos+=a[i][1];
		}
		qsort(out,cnt,sizeof(pix),cmp);
		pix temp = out[0];
		for(int i = 0; i < cnt; i++){
			if(temp.code == out[i].code)
				continue;
			printf("%d %d\n", temp.code, out[i].pos-temp.pos);
			temp = out[i];
		}
		printf("%d %d\n", temp.code, pos_sum-temp.pos+1);
		printf("0 0\n");
	}
	printf("0\n");
	return 0;
}