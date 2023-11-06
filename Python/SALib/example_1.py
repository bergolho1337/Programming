from SALib.sample import saltelli
from SALib.sample import sobol
from SALib.analyze import sobol as sobol_analyze
from SALib.test_functions import Ishigami
import matplotlib.pyplot as plt
import numpy as np

# My own implementation of the Ishigami function
def evaluate_model (X, A=7.0, B=0.1):
    return np.sin(X[0]) + A * np.power(np.sin(X[1]), 2) + B * np.power(X[2], 4) * np.sin(X[0])

def write_samples_to_file (param_values):
    filename = "outputs/param_values.txt"
    file = open(filename, "w")
    for i, X in enumerate(param_values):
        file.write("%.20g %.20g %.20g\n" % (X[0], X[1], X[2]))
    file.close()

def write_evaluation_to_file (Y):
    filename = "outputs/evaluation.txt"
    file = open(filename, "w")
    for value in Y:
        file.write("%.20g\n" % (value))
    file.close()

problem = {
    'num_vars': 3,
    'names': ['x1', 'x2', 'x3'],
    'bounds': [[-3.14159265359, 3.14159265359],
               [-3.14159265359, 3.14159265359],
               [-3.14159265359, 3.14159265359]]
}

# Generating samples
param_values = saltelli.sample(problem, 1024)
#param_values = sobol.sample(problem, 4)
#write_samples_to_file(param_values)
#print(param_values)

# Evaluate the samples using the desired model

# 0) Using the builtin function from the library
#Y = Ishigami.evaluate(param_values)     # default values: (a=7.0, b=0.1)
#write_evaluation_to_file(Y)
#for value in Y:
#    print(value)
#print(Y)

# 1) Using a Python method
#Y = np.zeros([param_values.shape[0]])
#for i, X in enumerate(param_values):
#    Y[i] = evaluate_model(X)

# 2) Saving the samples in a file to send to be solved by an external model.
#   Then, we load the solution using to be evaluated by the library
Y = np.loadtxt("outputs/evaluation.txt", float)

# Perform the analysis
Si = sobol_analyze.analyze(problem, Y)
#print(Si['S1'])     # First order sensitivity index
#print(Si['ST'])     # Total order sensitivity index

# Printing the relation between the second order sensitivity index through the variables
#print("x1-x2:", Si['S2'][0,1])
#print("x1-x3:", Si['S2'][0,2])
#print("x2-x3:", Si['S2'][1,2])

# Parsing the sensitivity indexes to a Pandas dataframe
total_Si, first_Si, second_Si = Si.to_df()
#print(total_Si)
#print(first_Si)
#print(second_Si)

Si.plot()
#plt.show()
plt.savefig("outputs/Si_v3.png", dpi=300)