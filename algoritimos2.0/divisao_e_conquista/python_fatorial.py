import time
import sys
sys.setrecursionlimit(1000000)

def fatorial_recursivo(n):
	if n==1:
		return 1
	else:
		return fatorial_recursivo(n-1)*n

def fatorial_iterativo(n):
	fat=1
	for i in range(1, n):
		fat=fat*i+fat
	return fat

num=3000

Ti=time.clock()
fat=fatorial_recursivo(num)
Tf=time.clock()
print("fatorial_recursivo: | tempo: ",Tf-Ti)

Ti=time.clock()
fat=fatorial_iterativo(num)
Tf=time.clock()
print("fatorial_iterativo: | tempo: ",Tf-Ti)