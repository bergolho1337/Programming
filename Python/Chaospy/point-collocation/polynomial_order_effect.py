import numpy
import chaospy
from chaospy.example import (coordinates, exponential_model, distribution, error_mean, error_variance)
from matplotlib import pyplot

# Sampling schemes we want to include
rules = ["halton", "gaussian"]

# Estimate mean and variance for various number of samples
polynomial_orders = list(range(2, 6))
for idx, rule in enumerate(rules):
    pyplot.subplot(1, 2, idx+1)

    sample_sizes = []
    errors_mean = []
    errors_variance = []
    for order in polynomial_orders:

        # Perform analysis for a specific order
        samples = (
            distribution.sample((order+1)**2, rule="halton")
            if rule == "halton"
            else chaospy.generate_quadrature(
                order, distribution, rule="gaussian")[0]
        )
        evaluations = [exponential_model(sample)
                       for sample in samples.T]
        polynomial_expansion = chaospy.generate_expansion(
            order, distribution)
        model_approximation = chaospy.fit_regression(
            polynomial_expansion, samples, evaluations)

        # Store results
        sample_sizes.append((order+1)**2)
        errors_mean.append(error_mean(
            chaospy.E(model_approximation, distribution)))
        errors_variance.append(error_variance(
            chaospy.Var(model_approximation, distribution)))


    # Error plot for mean
    pyplot.loglog(sample_sizes, errors_mean, label="mean")

    # Error plot for variance
    pyplot.loglog(sample_sizes, errors_variance, label="variance")

    # Make plot pretty
    pyplot.axis([
        min(sample_sizes), max(sample_sizes), 1e-15, 1e-3])
    pyplot.title(rule)
    pyplot.xlabel("Number of samples")
    pyplot.legend() if idx else pyplot.ylabel("Error")

pyplot.show()
