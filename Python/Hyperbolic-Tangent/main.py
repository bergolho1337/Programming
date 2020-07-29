import numpy as np
from matplotlib import pyplot as plt 

A = 50
B = 50
C = 0.25
D = 4

def f (x):
    return A*np.tanh(-C*x+D) + B

def main ():
    x = np.linspace(0,50,200)
    y = f(x)
    
    for i in range(len(x)):
	print("%g %g" % (x[i],y[i]))
    plt.grid()
    plt.title("Pruning function - p(lvl) = %g*tanh(-%g*lvl+%g) + %g" % (A,B,C,D))
    plt.xlabel("level")
    plt.ylabel("%")
    plt.plot(x,y)
    #plt.show()
    plt.savefig("pruning_function.pdf")

if __name__ == "__main__":
    main()
