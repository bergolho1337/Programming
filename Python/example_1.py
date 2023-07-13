# ==============================================================================
# Example 1 - Using the SALib package to generate samples and evaluate 
#           a simple function:
#               f(x1,x2) = x1^2 + x2^2
# ==============================================================================

from SALib.sample import saltelli
from SALib.analyze import sobol
from SALib.test_functions import Ishigami
import numpy as np
import matplotlib.pyplot as plt

# Model function
def evaluate_model (X):
    print(X)
    return X[0]*X[0] + X[1]*X[1] 

def visualize_samples (param_values):
    X = param_values
    plt.ylabel("y", fontsize=15)
    plt.xlabel("x", fontsize=15)
    plt.title("samples", fontsize=14)
    plt.scatter(X[:,0], X[:,1], label="sample", c="black", linewidth=1.0)
    plt.legend(loc=0,fontsize=10)
    plt.show()

# Define the model inputs
problem = {
    'num_vars': 2,
    'names': ['x1', 'x2'],
    'bounds': [[-2.0, 2.0],
               [-2.0, 2.0]]
}

# Generate samples
param_values = saltelli.sample(problem, 100)
#visualize_samples(param_values)

# Run model (using a Python function)
Y = np.zeros([param_values.shape[0]])
for i, X in enumerate(param_values):
    Y[i] = evaluate_model(X)

# Run model (example)
#Y = Ishigami.evaluate(param_values)

# Perform analysis
#Si = sobol.analyze(problem, Y, print_to_console=True)

# Print the first-order sensitivity indices
#print(Si['S1'])