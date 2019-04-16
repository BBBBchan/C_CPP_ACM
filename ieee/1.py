m=int(input())
def C (bb,cc):
	t1=int(1)
	for i in range(1,bb+1):
		t1*=i
	t2=int(1)
	for i in range(1,cc+1):
		t2*=i
	t3=int(1)
	for i in range(1,bb-cc+1):
		t3*=i
	return int(t1/(t2*t3))     
def qpow(x,y,z):
	if y==0:
		return 1%z
	tmp=qpow(x,y>>1,z)
	tmp=tmp*tmp%z
	if y&1:
		tmp=tmp*x%z
	return tmp
while m > 0:
	a,b,c =input().split()
	a=int(a)
	b=int(b)
	c=int(c)
	print(int(qpow(a,C(b,c),1000000007)))
	m-=1