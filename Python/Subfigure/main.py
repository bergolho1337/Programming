import sys
import numpy as np
import matplotlib.pyplot as plt

def f1 (x):
    return x

def f2 (x):
    return x*x

def f3 (x):
    return np.exp(x)

def f4 (x):
    return np.sqrt(x)

def main ():
    x1 = np.linspace(0,5,100)
    y1 = f1(x1)

    x2 = np.linspace(-2,2,100)
    y2 = f2(x2)

    x3 = np.linspace(0,5,100)
    y3 = f3(x3)

    x4 = np.linspace(0,5,100)
    y4 = f4(x4)

    figure, axes = plt.subplots(nrows=2,ncols=2)
    ax = axes[0][0] 
    ax.plot(x1,y1)
    ax.set_title("Linear function")
    ax.set_xlabel("x")
    ax.set_ylabel("y")
    ax.grid()
    
    ax = axes[0][1] 
    ax.plot(x2,y2)
    ax.set_title("Quadratic function")
    ax.set_xlabel("x")
    ax.set_ylabel("y")
    ax.grid()

    ax = axes[1][0]
    ax.plot(x3,y3)
    ax.set_title("Exponetial function")
    ax.set_xlabel("x")
    ax.set_ylabel("y")
    ax.grid()

    ax = axes[1][1]
    ax.plot(x4,y4)
    ax.set_title("Non-linear function")
    ax.set_xlabel("x")
    ax.set_ylabel("y")
    ax.grid()

    # Set a padding between the figures
    figure.tight_layout(pad=3.0)

    #plt.show(figure)
    plt.savefig("subfigures.pdf")


if __name__ == "__main__":
	main()

'''
# Alternative way ...
    plt.subplot(221)
    plt.title("Linear function")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.grid()
    plt.plot(x1,y1)

    plt.subplot(222)
    plt.title("Quadratic function")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.grid()
    plt.plot(x2,y2)

    plt.subplot(223)
    plt.title("Exponetial function")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.grid()
    plt.plot(x3,y3)

    plt.subplot(224)
    plt.title("Non-linear function")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.grid()
    plt.plot(x4,y4)

'''
