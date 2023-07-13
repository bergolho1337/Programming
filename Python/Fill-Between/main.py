import numpy as np
import matplotlib.pyplot as plt

def main ():
    x = np.linspace(-1,1,100)
    y1 = x**2
    y2 = 2*x**2 + 2

    plt.plot(x, y1)
    plt.plot(x, y2)
    plt.fill_between(x, y1, y2, alpha=0.2)
    plt.show()

if __name__ == "__main__":
    main()
