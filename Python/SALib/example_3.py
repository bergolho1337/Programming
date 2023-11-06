from SALib.sample import saltelli
from SALib.sample import sobol
from SALib.sample import latin
from SALib.analyze import sobol as sobol_analyze
from SALib.test_functions import Ishigami
import matplotlib.pyplot as plt
import numpy as np

def plot_distribution (param_values):
    for i, X in enumerate(param_values):
        plt.scatter(X[0], X[1])
    plt.savefig("distribution.png", dpi=300)
    #plt.show()

np.random.seed(1562046115)

problem = {
    'num_vars': 2,
    'names': ['x1', 'x2'],
    'bounds': [[0, 1],
               [0, 1]]
}

#problem = {
#    'num_vars': 4,
#    'names': ['x1', 'x2', 'x3', 'x4'],
#    'bounds': [[0, 1],
#               [0, 1],
#               [0, 1],
#               [0, 1]]
#}

# Generating samples
#param_values = saltelli.sample(problem, 64)
#param_values = sobol.sample(problem, 64)
param_values = latin.sample(problem, 384)
#print(len(param_values))
plot_distribution(param_values)
