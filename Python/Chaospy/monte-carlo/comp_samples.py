# -----------------------------------------------------------------------------------------------
# Example that demonstrates how to use ChaosPy to run a Monte-Carlo simulation
# for an exponential model.
# -----------------------------------------------------------------------------------------------
# Here, we compared different sample schemes in order to verify which one returns the best result
# -----------------------------------------------------------------------------------------------

import numpy
from matplotlib import pyplot
from chaospy.example import coordinates, exponential_model, distribution
from chaospy.example import error_mean, error_variance

pyplot.rc("figure", figsize=[15, 15])
pyplot.rc("figure.subplot", hspace=0.2)
sampling_rules = ["halton", "hammersley",
                  "latin_hypercube", "korobov", "sobol", "random"]

for idx, rule in enumerate(sampling_rules, start=1):
    pyplot.subplot(4, 2, idx)

    pyplot.scatter(*distribution.sample(100, rule=rule))
    pyplot.axis([1, 2, 0.1, 0.2])
    pyplot.title(rule)

pyplot.show()

# NBVAL_CHECK_OUTPUT
for rule in sampling_rules:
    samples = distribution.sample(1000, rule=rule)
    evals = numpy.array([exponential_model(sample)
                         for sample in samples.T])
    errm = error_mean(numpy.mean(evals, axis=0))
    errv = error_variance(numpy.var(evals, axis=0))
    print("%20s %.6f %.6f" % (rule,errm,errv))
