import io
from mtranslate import translate

l1=io.open('legenda_ingles2.srt','r',encoding='utf-8')
l3=io.open('legenda_traduzida_test.srt','w',encoding='utf-8')
#traduz do google
cont=0

while 1:
	line=l1.readline()
	if not line:
		l3.write(translate(line,'pt','en'))
		break
	l3.write(translate(line,'pt','en'))
	l3.write('\n')


l1.close()
l3.close()
