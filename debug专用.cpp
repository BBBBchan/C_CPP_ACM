#include <cstdio>
#include <algorithm>
using namespace std;
int a[1055][2];
int pos_sum = 0, count= 0,t;
struct pix{
	int pos;
	int code;
}out[9000],temp;
int GetValue(int pos){
	int i=0,p=0;
	while(p<pos){
		p+=a[i++][1];
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
			if(i<0 || j < 0 || j >= t || tpos>=pos_sum)
				continue;
			int tcode = GetValue(tpos+1);
			if(max<abs(tcode-code))
				max = abs(tcode - code);
		}
	return max; 
}
int cmp(pix a, pix b){
	return a.pos>b.pos;
}
int main(int argc, char const *argv[])
{
	while(scanf("%d", &t) != EOF){
		int a[1055][2];
		int pos_sum = 0, count= 0,pairv,pairt;
		while(scanf("%d %d", &pairv, &pairt) &&pairt){
			a[count][0] = pairv;
			a[count++][1] = pairt;

			pos_sum += a[count][1];
		}
		int pos=1,cnt;
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
		sort(out,out+cnt,cmp);
		temp = out[0];
		for(int i = 0; i < cnt; i++){
			if(temp.code == out[i].code)
				continue;
			printf("%d %d\n", temp.code, out[i].pos-temp.pos);
			temp = out[i];
		}
		printf("0 0\n");
	}
	return 0;
}
