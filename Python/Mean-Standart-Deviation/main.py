import sys
import numpy as np

def main():
    if len(sys.argv) != 2:
        print("-------------------------------------------------------------------------")
        print("Usage:> python %s <input_file>" % sys.argv[0])
        print("-------------------------------------------------------------------------")
        print("<input_file> = Input file with the data")
        print("-------------------------------------------------------------------------")
        return 1

    input_file = sys.argv[1]
    data = np.genfromtxt(input_file)

    mean_value = np.mean(data)
    std_value = np.std(data)
    sem_value = std_value / np.sqrt(np.size(data))
    print(50*"-")
    print("Mean +/- Standart deviation")
    print("%.2lf +/- %.2lf" % (mean_value, std_value))
    print(50*"-")
    print("Mean +/- Standart error")
    print("%.2lf +/- %.2lf" % (mean_value, sem_value))
    print(50*"-")

if __name__ == "__main__":
	main()

