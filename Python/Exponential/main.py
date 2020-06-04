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
    plt.title("Pruning function")
    plt.xlabel("level")
    plt.ylabel("%")
    plt.plot(x,y)
    #plt.show()
    plt.savefig("pruning_function.pdf")

if __name__ == "__main__":
    main()
