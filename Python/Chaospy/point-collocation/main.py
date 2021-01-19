import numpy
import chaospy
from chaospy.example import (coordinates, exponential_model, distribution)
from matplotlib import pyplot

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

print(samples["halton"].shape)
print(samples["gaussian"].shape)
