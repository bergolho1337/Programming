import chaospy as cp
import numpy as np
import scipy

t = np.linspace(0, 1, 101)

def my_function (y, t, a, I):
	return -a*y

def solver (a, I):
	y0 = I
	sol = scipy.integrate.odeint(my_function, y0, t, args=(a,I))
	print(sol)
	return sol

def main ():
	dist_a = cp.Uniform(0, 0.1)
	dist_I = cp.Uniform(8, 10)

	dist = cp.J(dist_a, dist_I)

	samples = dist.sample(size=5)
	n_var, n_samples = samples.shape
	#print("%d %d" % (n_var, n_samples))

	#print(samples)
	samples_u = []
	for i in range(n_samples):
		a = samples[0][i]
		I = samples[1][i]
		a, I = samples[0][i], samples[1][i]
		sample_u = solver(a, I)
		samples_u.append(sample_u)
		#print("Index %d" % (i))
		#print("\ta = %lf || I = %lf" % (a, I))
	print(samples_u)

	#E = np.mean(samples_u, 0)
	#V = np.var(samples_u, 0)

	#print("E = %lf || V = %lf" % (E, V))

if __name__ == "__main__":
	main()
