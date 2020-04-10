import numpy as np  
from scipy.optimize import curve_fit
from matplotlib import pyplot as plt 

def func (x):
    #return -60*np.tanh(1.5*x + 0.5) + 320
    return -np.tanh(100*x-50) + 320

x = np.linspace(0,1,100)
y = func(x)

data = np.genfromtxt("input.txt")

xp = data[:,0]
yp = data[:,1]

plt.plot(x,y)
plt.plot(xp,yp)
#plt.plot(x,y)
#plt.plot(x,ynew)

plt.show()
