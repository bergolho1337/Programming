import sys
import numpy as np
import matplotlib.pyplot as plt


def read_data (input_file):
	data = np.genfromtxt(input_file)
	return data[:,0], data[:,1]


def plot_data(x, y, colorname):
	#plt.grid()
	plt.plot(x, y, label="y", c=colorname, linewidth=3.0)
	#plt.ylabel("y", fontsize=15)
	#plt.xlabel("x", fontsize=15)
	#plt.title("f(x)", fontsize=14)
	#plt.legend(loc=0,fontsize=10)
	#plt.show()
	#plt.savefig("function.svg")


def main():
	if len(sys.argv) != 3:
		print("-------------------------------------------------------------------------")
		print("Usage:> python %s <input_file_1> <input_file_2>" % sys.argv[0])
		print("-------------------------------------------------------------------------")
		print("<input_file_1> = Input file with the function data 1")
		print("<input_file_2> = Input file with the function data 2")
		print("-------------------------------------------------------------------------")
		return 1

	input_file_1 = sys.argv[1]
	input_file_2 = sys.argv[2]

	x1, y1 = read_data(input_file_1)
	x2, y2 = read_data(input_file_2)

	plot_data(x1,y1,"red")
	plot_data(x2,y2,"blue")
	plt.grid()
	plt.show()


if __name__ == "__main__":
	main()
