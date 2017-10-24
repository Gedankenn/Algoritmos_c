def b10_b(n,b):
	if n==0:
		return 0
	else:
		return (n%b+10*b10_b(n/b,b))

print(b10_b(97115108109111118123,64))