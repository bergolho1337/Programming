import sys
import numpy as np

def calculate_rms (y_true, y_pred):
    loss = np.sqrt(np.mean(np.square(((y_true - y_pred) / y_true))))
    return loss

def main():

    if len(sys.argv) != 3:
        print("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
        print("Usage:> python %s <reference_filename> <aproximation_filename>" % sys.argv[0])
        print("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
        return 1

    ref_filename = sys.argv[1]      	# Reference value
    aprox_filename = sys.argv[2]   	# Aproximation value

    data_ref = np.genfromtxt(ref_filename)
    data_aprox = np.genfromtxt(aprox_filename)

    apd_ref = data_ref[:,1]
    apd_aprox = data_aprox[:,1]

    print("RMS = %.10lf" % (calculate_rms(apd_ref,apd_aprox)))

if __name__ == "__main__":
        main()

