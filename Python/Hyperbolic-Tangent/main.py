import numpy as np
from matplotlib import pyplot as plt 

A = 50
B = 50
C = 0.25
D = 4

def f (x):
    return A*np.tanh(-C*x+D) + B

def f2 (x,d):
    return A*np.tanh(-C*x+d) + B

def main ():
    x = np.linspace(0,50,200)
    y1 = f2(x,3)
    y2 = f2(x,5)
    y3 = f2(x,7)

    #for i in range(len(x)):
    #	print("%g %g" % (x[i],y[i]))
    
    plt.grid()
    plt.title("Pruning function - A.tanh(C.x + D) + B")
    plt.xlabel("level")
    plt.ylabel("%")
    plt.plot(x,y1,label="soft (D=3)",color="blue")
    plt.plot(x,y2,label="moderate (D=5)",color="orange")
    plt.plot(x,y3,label="heavy (D=7)",color="red")
    plt.legend(loc=0)
    #plt.show()
    plt.savefig("pruning_function_2.pdf")

if __name__ == "__main__":
    main()
