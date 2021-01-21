# In this example we want to solve the following problem:
# Given a set of samples Q_1, Q_2, ..., Q_n, model evaluations U_1, U_2, ..., U_N and polynomial
# expansions phi_1, phi_2, ..., phi_M solve the linear system:
#	U_n = sum_{m=1}^{M} c_m(t) . phi_m(Q_n) , n = 1, 2, ..., N
# Basically, we want to find a set of constants c_m that multipled by a given polynomial expansion
# will result in the model evaluation. This problem is also know as Regression.
# With this solution we have a formula to aproximate our evaluation for any given point. We just need
# to use the coefficients c_m and the polynomial expansion phi_m.

import numpy
import chaospy
from chaospy.example import (coordinates, exponential_model, distribution, error_mean, error_variance)
from matplotlib import pyplot

def plot_distributions (samples, rules):
	# increase figure width to better fit two plots
	pyplot.rc("figure", figsize=[15, 6])

	for fig_idx, rule in enumerate(rules, start=1):
		pyplot.subplot(1, 2, fig_idx)

		pyplot.scatter(*samples[rule])

		pyplot.xlabel("init (normal)")
		pyplot.ylabel("rate (uniform)") if fig_idx == 1 else None
		#pyplot.axis([0.9, 2.1, 0.1, 0.2])
		pyplot.title(rule)

	pyplot.show()

def plot_evaluations (evaluations, rules):
	for fig_idx, rule in enumerate(rules, start=1):
		pyplot.subplot(1, 2, fig_idx)
		pyplot.plot(coordinates, evaluations[rule][::3].T, alpha=0.3)
		pyplot.xlabel("coordinates $t$")
		pyplot.ylabel("model evaluations $u$")
		pyplot.title(rule)
		pyplot.axis([0, 10, 0, 2])

	pyplot.show()

def plot_statistics (model_approximations,rules):
	for fig_idx, rule in enumerate(rules, start=1):
		pyplot.subplot(1, 2, fig_idx)

		mean = chaospy.E(
			model_approximations[rule], distribution)
		var = chaospy.Var(
			model_approximations[rule], distribution)

		pyplot.fill_between(coordinates, mean-numpy.sqrt(var),
							mean+numpy.sqrt(var), alpha=0.3)
		pyplot.plot(coordinates, mean, "k-")

		pyplot.xlabel("coordinates $t$")
		pyplot.ylabel("Model evaluations $u$")
		pyplot.axis([0, 10, 0, 2])
		pyplot.title(rule)

	pyplot.show()
	return mean, var

# Sampling schemes we want to include
rules = ["halton", "gaussian"]

# Generate samples for different orders:
quadrature_order = 10
number_of_samples = (quadrature_order+1)**2
samples = {
    "halton": distribution.sample(
        number_of_samples, rule="halton"),
    "gaussian": chaospy.generate_quadrature(
        quadrature_order, distribution, rule="gaussian")[0],
}

assert samples["halton"].shape ==  (len(distribution), number_of_samples)
assert samples["gaussian"].shape == (len(distribution), number_of_samples)

# Plot distributions
#plot_distributions(samples,rules)

print(samples["halton"].shape)
print(samples["gaussian"].shape)

# Evaluate the samples
evaluations = {}
for rule in rules:
	evaluations[rule] = numpy.array( [exponential_model(sample) for sample in samples[rule].T] )

assert evaluations["halton"].shape == (number_of_samples, len(coordinates))
assert evaluations["gaussian"].shape == (number_of_samples, len(coordinates))

# Plot samples evaluations
#plot_evaluations(evaluations,rules)

# Create the polynomial expansion
polynomial_order = 4
polynomial_expansion = chaospy.generate_expansion(polynomial_order, distribution)

# To avoid numerical instability the polynomials from the expansion are orthogonal to each other
outer_product = chaospy.outer(
    polynomial_expansion[:6], polynomial_expansion[:6])
normed_inner_products = (
    chaospy.E(outer_product, distribution)/
    chaospy.E(polynomial_expansion[:6]**2, distribution)
)
print(normed_inner_products.round(10))


# Make the aproximation
model_approximations = { rule: chaospy.fit_regression(polynomial_expansion, samples[rule], evaluations[rule]) for rule in rules }
print(model_approximations["halton"][:4].round(3),model_approximations["gaussian"][:4].round(3))

# Calculate the analitical value for comparison
P = polynomial_expansion(*samples["halton"]).T
c_hat = numpy.linalg.inv(P.T @ P) @ P.T @ evaluations["halton"] 
analitical_approximation = chaospy.sum(c_hat.T*polynomial_expansion, axis=1).T
print(analitical_approximation[:4].round(3))

mean, var = plot_statistics(model_approximations,rules)

# Error analysis
assert abs(error_mean(mean)) < 1e-9
assert abs(error_variance(var)) < 1e-7
