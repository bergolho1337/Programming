import numpy as np  
from scipy.optimize import curve_fit
from matplotlib import pyplot as plt 

def func (x,a,b,c):
    return x

data = np.genfromtxt("input.txt")

x = data[:,0]
y = data[:,1]

popt, pcov = curve_fit(func, x, y)

ynew = func(x,popt[0],popt[1],popt[2])

x2 = []
y2 = []

for i in range(len(y)):
    print("%g %g" % (y[i],ynew[i]))
    if (i % 1 == 0):
        x2.append(x[i])
        y2.append(y[i])

plt.plot(x2,y2)
#plt.plot(x,y)
#plt.plot(x,ynew)

plt.show()
