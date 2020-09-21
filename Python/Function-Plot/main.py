import sys
import numpy as np
import matplotlib.pyplot as plt


def read_data (input_file):
	data = np.genfromtxt(input_file)
	return data[:,0], data[:,1]


def plot_data(x, y):
	plt.grid()
	plt.plot(x, y, label="y", c="black", linewidth=3.0)
	#plt.plot(x, y/1000, label="CV", c="black", linewidth=3.0)
	#plt.plot(x, y, 'o', c="black")
	#plt.ylabel("v(m/s)",fontsize=15)
	#plt.xlabel(r'$\sigma$(mS/um)',fontsize=15)
	plt.ylabel("y", fontsize=15)
	plt.xlabel("x", fontsize=15)
	#plt.title("Conductivity x Propagation velocity (Trovato model)",fontsize=14)
	plt.title("f(x)", fontsize=14)
	plt.legend(loc=0,fontsize=10)
	plt.show()
	#plt.savefig("trovato_sigma_x_cv.svg")


def main():
	if len(sys.argv) != 2:
		print("-------------------------------------------------------------------------")
		print("Usage:> python %s <input_file>" % sys.argv[0])
		print("-------------------------------------------------------------------------")
		print("<input_file> = Input file with the function data")
		print("-------------------------------------------------------------------------")
		return 1

	input_file = sys.argv[1]

	x, y = read_data(input_file)

	plot_data(x,y)


if __name__ == "__main__":
	main()
