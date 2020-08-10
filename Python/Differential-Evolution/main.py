# ===========================================================================================================
# Example code that demonstrate how to use the Differential Evolution function from the Scipy library
# ===========================================================================================================

from scipy.optimize import rosen, differential_evolution

# Parabola centered at the origin (0,0)
def g (x):
    eval = x[0]*x[0]
    return eval

# Paraboloid centered at the origin (0,0)
def f (x):
    eval = x[0]*x[0] + x[1]*x[1]
    return eval

# Call the Differential Evolution (DE) algorithm
def solve_DE (fn,bounds):
    #return differential_evolution(fn, bounds)
    return differential_evolution(fn, bounds, maxiter=3,popsize=5,disp=True)

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

    # Parabola
    print("Min: y = x^2")
    target_function = g
    bounds = [(-2,2)]
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



