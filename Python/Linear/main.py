import numpy as np
from matplotlib import pyplot as plt 

A = 0.2
B = 0

def f (x):
    return A*x + B 

def main ():
    x = np.linspace(0,50,200)
    y = f(x)
    
    plt.grid()
    plt.plot(x,y)
    plt.show()

if __name__ == "__main__":
    main()
