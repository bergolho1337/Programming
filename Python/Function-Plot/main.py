import sys
import numpy as np
import matplotlib.pyplot as plt


def read_data (input_file):
	data = np.genfromtxt(input_file)
	return data[:,0], data[:,1]


def plot_data(x, y):
	plt.grid()
	plt.plot(x, y, label="y", c="black", linewidth=3.0)
	plt.ylabel("y", fontsize=15)
	plt.xlabel("x", fontsize=15)
	plt.title("f(x)", fontsize=14)
	plt.legend(loc=0,fontsize=10)
	plt.show()
	#plt.savefig("function.svg")

def linear_function (x1, y1, x2, y2):
	a = (y2-y1)/(x2-x1)
	b = (y1*x2 - y2*x1)/(x2-x1)
	x = np.linspace(x1,x2,100)
	y = a*x + b
	print("a = %g" % (a))
	print("b = %g" % (b))
	return x, y

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
	#xfit, yfit = linear_function(50,0.0013,250,0.00724)
	#plt.plot(x,y,label="ref",c="red",linewidth=3.0)
	#plt.plot(xfit,yfit,label="aprox",c="blue",linewidth=3.0)
	#plt.show()


if __name__ == "__main__":
	main()
