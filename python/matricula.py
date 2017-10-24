#http://www.lfd.uci.edu/~gohlke/pythonlibs/#pyhook
#pip install pypiwin32

#https://github.com/SavinaRoja/PyUserInput
from pymouse import PyMouse
from pykeyboard import PyKeyboard
import time

m = PyMouse()
k = PyKeyboard()

x_dim, y_dim = m.screen_size()
m.click(510, 750,1)
m.click(587,574,1)
time.sleep(0.1)
m.click(587,575,1)
time.sleep(0.1)
k.type_string('ED23NB')
time.sleep(0.1)
m.click(790,575,1)
k.type_string('3MC')
time.sleep(0.1)
m.click(668,598,1)