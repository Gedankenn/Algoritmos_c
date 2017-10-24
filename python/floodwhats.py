#http://www.lfd.uci.edu/~gohlke/pythonlibs/#pyhook
#pip install pypiwin32

#https://github.com/SavinaRoja/PyUserInput

from pynput import mouse, keyboard
from pynput.mouse import Button, Controller

mouse = Controller()


#from pymouse import PyMouse
#from pykeyboard import PyKeyboard
#import time


#m = PyMouse()
#k = PyKeyboard()

#x_dim, y_dim = m.screen_size()
#m.click(387, 758,1)
#time.sleep(0.1)
#for n in range(0,200):
#	m.click(538,707,1)
#	time.sleep(0.1)
#	k.type_string('KABRA VIADO')
#	time.sleep(0.1)
#	m.click(1336,704,1)
#	time.sleep(0.1)

mouse.position = (538, 758)
mouse.click(Button.left, 1)