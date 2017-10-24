import io

l1=io.open('Rick.and.Morty.S03E08.720p.HDTV.x264-BATV[ettv]-port.srt','r',encoding='utf-8')
l2=io.open('Rick.and.Morty.S03E08.720p.HDTV.x264-BATV[ettv]-port.srt','r',encoding='utf-8')
l3=io.open('legenda_traduzida.srt','w',encoding='utf-8')


prox=l2.read(1)
anterior='c'

atual=l1.read(1)
while(atual!=""):
	prox=l2.read(1)
	if(atual!='\n'):	
		if(prox!=""):
			if((ord(prox)<58) and (ord(prox)>47)):
				if((ord(anterior)!=62)):
					atual=l1.read(1)
					prox=l2.read(1)
	anterior=atual;
	l3.write(atual)
	#print(atual)
	atual=l1.read(1)

l1.close()
l2.close()
l3.close()