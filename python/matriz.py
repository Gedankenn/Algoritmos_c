import time

l=[]
with open('matriz.txt','r') as f:
	for line in f:
		l.append(line.split(','))

print(l)
