import sys
import numpy as np
import matplotlib.pyplot as plt

def theta (Gi,Cf,tauf,d):
    return ((d * Gi) / (4.0 * tauf * Cf ))**(0.5) * 0.1

def main ():
    Gi = 7.9
    Cf = 3.4
    tauf = 0.1

    d = np.linspace(0,300,200)
    v = theta(Gi,Cf,tauf,d)

    plt.plot(d,v)
    plt.xlabel(r"$d ( \mu m )$")
    plt.ylabel("v (m/s)")
    plt.grid()
    #plt.show()
    plt.savefig("cable_equation_purkinje.pdf")

if __name__ == "__main__":
	main()