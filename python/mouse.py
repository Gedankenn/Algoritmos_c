from pymouse import PyMouse
from pykeyboard import PyKeyboard

m = PyMouse()
k = PyKeyboard()

x_dim, y_dim = m.screen_size()
print(m.screen_size())
m.click(1300, 400,1)
#k.type_string('Hello, World!')