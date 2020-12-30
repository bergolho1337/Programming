# -----------------------------------------------------------------------------------------------
# Example that demonstrates how to use ChaosPy to run a Monte-Carlo simulation
# for an exponential model.
# -----------------------------------------------------------------------------------------------
# There are two types of samples generated in this example. The default pseudo-random
# and the Halton generator. The difference between these two is that the Halton 
# sequence separates tries to spread the sampling, avoiding clustering the points 
# in certain region of the sample domain. 
# -----------------------------------------------------------------------------------------------
# The ChaosPy library is normally used for uncertainty quantification. 
# -----------------------------------------------------------------------------------------------
# Uncertainty quantification (UQ) is the science of quantitative characterization and 
# reduction of uncertainties in both computational and real world applications. 
# It tries to determine how likely certain outcomes are if some aspects of the system 
# are not exactly known. An example would be to predict the acceleration of a human body 
# in a head-on crash with another car: even if we exactly knew the speed, small differences 
# in the manufacturing of individual cars, how tightly every bolt has been tightened, etc., 
# will lead to different results that can only be predicted in a statistical sense. 
# -----------------------------------------------------------------------------------------------
# Many problems in the natural sciences and engineering are also rife with sources of uncertainty. 
# Computer experiments on computer simulations are the most common approach to study problems 
# in uncertainty quantification.
# -----------------------------------------------------------------------------------------------

import numpy
from matplotlib import pyplot
from chaospy.example import coordinates, exponential_model, distribution
from chaospy.example import error_mean, error_variance

def plot_samples (samples,rules):
	pyplot.rc("figure", figsize=[15, 6])

	for fig_idx, rule in enumerate(rules, start=1):
		pyplot.subplot(1, 2, fig_idx)

		x_coors, y_coors = samples[rule][:, :300]
		pyplot.scatter(x_coors, y_coors)

		pyplot.xlabel("init (normal)")
		pyplot.ylabel("rate (uniform)") if fig_idx == 1 else None
		pyplot.axis([1, 2, 0.1, 0.2])
		pyplot.title(rule)

	pyplot.show()

def plot_evaluations (evaluations,rules):
	for idx, rule in enumerate(rules, start=1):
		pyplot.subplot(1, 2, idx)
		# Make a plot line for the first 50 evaluations
		pyplot.plot(coordinates, evaluations[rule][:50].T, alpha=0.3)
		pyplot.xlabel("coordinates $t$")
		pyplot.ylabel("model evaluations $u$") if idx == 1 else None
		pyplot.title(rule)
		pyplot.axis([0, 10, 0, 2])
	pyplot.show()

def plot_statistics (evaluations,rules):
	for fig_idx, rule in enumerate(rules, start=1):
		pyplot.subplot(1, 2, fig_idx)

		# Sample mean and variance
		smean = numpy.mean(evaluations[rule], axis=0)
		svar = numpy.var(evaluations[rule], axis=0)
		sstd = numpy.std(evaluations[rule], axis=0)

		# Create band one standard deviation away from mean
		pyplot.fill_between(coordinates, smean-numpy.sqrt(svar),
							smean+numpy.sqrt(svar), alpha=0.3)
		pyplot.plot(coordinates, smean)
		
		# Make plot pretty
		pyplot.xlabel("coordinates $t$")
		pyplot.ylabel("Model evaluations $u$")
		pyplot.axis([0, 10, 0, 2])
		pyplot.title(rule)

	pyplot.show()
	return smean, svar, sstd

def plot_error_analysis (estimated_mean,estimated_var,rules):
	for fig_idx, rule in enumerate(rules, start=1):
		pyplot.subplot(1, 2, fig_idx)

		# error plot for mean
		errors = [error_mean(mean)
				  for mean in estimated_mean[rule]]
		pyplot.loglog(sizes, errors, label="mean")

		# error plot for variance
		errors = [error_variance(variance)
				  for variance in estimated_var[rule]]
		pyplot.loglog(sizes, errors, label="variance")

		pyplot.axis([10, 10000, 1e-5, 5e-1])
		pyplot.title(rule)
		pyplot.xlabel("Number of samples")
		if fig_idx == 1:
			pyplot.ylabel("Error")
		else:
			pyplot.legend()

	pyplot.show()

# Fix random seed to enforce determinism
numpy.random.seed(123)

# Sampling schemes we want to include
#	Random: Default pseudo-random sequence
#	Halton: Low-discrepancy sequence, which avoids clustering elements
rules = ["random", "halton"]

# Generate samples for both schemes
number_of_samples = 10000
samples = {rule: distribution.sample(
    number_of_samples, rule=rule) for rule in rules}

assert samples["random"].shape == (len(distribution), number_of_samples)
assert samples["halton"].shape == (len(distribution), number_of_samples)

# Plot the two samples
#plot_samples(samples,rules)

# samples[rule] = Stores all the samples for the specific 'rule' (The .T is the transpose)
# evaluations[rule] = Stores all the evaluations for the specific 'rule'
evaluations = {}
for rule in samples:
	evals = [ exponential_model(sample)
			for sample in samples[rule].T ]
	evaluations[rule] = numpy.array(evals)
	
assert evaluations["random"].shape == (number_of_samples, len(coordinates))
assert evaluations["halton"].shape == (number_of_samples, len(coordinates))
    
#plot_evaluations(evaluations,rules)

smean, svar, sstd = plot_statistics(evaluations,rules)

# Error analysis
# Logarithmic scale
sizes = (10**numpy.linspace(1, 4, 20)).astype(int)

estimated_mean = {"halton": [], "random": []}
estimated_var = {"halton": [], "random": []}
for rule in rules:
    for size in sizes:
        estimated_mean[rule].append(
            numpy.mean(evaluations[rule][:size], axis=0))
        estimated_var[rule].append(
            numpy.var(evaluations[rule][:size], axis=0))
            
#plot_error_analysis(estimated_mean,estimated_var,rules)
