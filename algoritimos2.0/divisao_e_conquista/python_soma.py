import time
import sys
sys.setrecursionlimit(500000000)

def somarecursiva(n):
	if n==1:
		return n
	else:
		return somarecursiva(n-1)+n

def somagauss(n):
	return ((n*(n+1))/2)

def somaiterativa(n):
	soma=0
	for i in range(0,num):
		soma=soma+i
	return soma

num=50000000

Ti=time.clock()
#soma=somarecursiva(num)
soma=somaiterativa(num)
Tf=time.clock()

print("soma iterativa: ",soma,"|tempo: ",Tf-Ti)

Ti=time.clock()
soma=somagauss(num)
Tf=time.clock()

print("soma gauss: ",soma,"|tempo: ",Tf-Ti)