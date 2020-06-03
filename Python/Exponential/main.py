import numpy as np
from matplotlib import pyplot as plt 

A = 100
B = -0.2
C = 0

def f (x):
    return A*np.exp(B*x) + C 

def main ():
    x = np.linspace(0,50,200)
    y = f(x)
    
    plt.grid()
    plt.plot(x,y)
    plt.show()

if __name__ == "__main__":
    main()
