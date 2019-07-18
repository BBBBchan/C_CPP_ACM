while 1:
	try:
		a,b,c,d=input().split()
		a=int(a)
		b=int(b)
		c=int(c)
		d=int(d)
		if a*d==b*c:
			print("=")
		elif a*d>b*c:
			print(">")
		else:
			print("<")
	except:
		break
