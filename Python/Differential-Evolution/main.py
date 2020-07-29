# ===========================================================================================================
# Example code that demonstrate how to use the Differential Evolution function from the Scipy library
# ===========================================================================================================

from scipy.optimize import rosen, differential_evolution

# Paraboloid centered at the origin (0,0)
def f (x):
    return x[0]*x[0] + x[1]*x[1]

# Call the Differential Evolution (DE) algorithm
def solve_DE (fn,bounds):
    return differential_evolution(fn, bounds)

def main():
    # Rosenbrock function
    print("Min: Rosenbrock function")
    target_function = rosen
    bounds = [(0,2), (0,2)]
    result = solve_DE(target_function,bounds)
    if (result.success):
        print("\tSuccess!")
    else:
        print("\tERROR!")
    print("\tSolution = [%s]" % (result.x))
    print("\tMessage = %s" % (result.message))
    print("\tFunction value = %s" % (result.fun))
    print("\tNumber of objective function evaluations = %s" % (result.nfev))
    print("\tNumber of iterations = %s" % (result.nit))

    # Paraboloid
    print("Min: z = x^2 + y+2")
    target_function = f
    bounds = [(-2,2), (-2,2)]
    result = solve_DE(target_function,bounds)
    if (result.success):
        print("\tSuccess!")
    else:
        print("\tERROR!")
    print("\tSolution = [%s]" % (result.x))
    print("\tMessage = %s" % (result.message))
    print("\tFunction value = %s" % (result.fun))
    print("\tNumber of objective function evaluations = %s" % (result.nfev))
    print("\tNumber of iterations = %s" % (result.nit))



if __name__ == "__main__":
        main()



