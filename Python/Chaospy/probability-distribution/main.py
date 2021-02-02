import chaospy
import numpy

# Fixing seed for reproducing results
#numpy.random.seed(1234)

# Create a Gaussian distribution with mean=2 and deviation=2 
distribution = chaospy.Normal(mu=2, sigma=2)

# Generate sample using a Probability density function (PDF) 
#  Probability density function = a function whose integral is calculated to find 
# probabilities associated with a continuous random variable. 
# Its graph is a curve above the horizontal axis that defines a total area, between itself and the axis, of 1.
# It commonly used to visualize the distribution of a given sample (boxplot)
t = numpy.linspace(-3, 3, 9)
samples = distribution.pdf(t).round(3)
print("Using PDF")
print(samples)

# Generate sample using a Cumulative distribution function (CDF)
#  The cumulative distribution function (cdf) gives the probability that 
# the random variable X is less than or equal to x and is usually denoted F(x). 
# The cumulative distribution function of a random variable X is the function given by F(x)=P[X<=x].
samples = distribution.cdf(t).round(3)
print("Using CDF")
print(samples)

# A PDF is simply the derivative of a CDF. Thus a PDF is also a function of a random variable, x, 
# and its magnitude will be some indication of the relative likelihood of measuring a particular value.

# Monte Carlo methods, or Monte Carlo experiments, are a broad class of computational algorithms that rely 
# on repeated random sampling to obtain numerical results. The underlying concept is to use randomness to 
# solve problems that might be deterministic in principle. They are often used in physical and mathematical 
# problems and are most useful when it is difficult or impossible to use other approaches. Monte Carlo methods 
# are mainly used in three problem classes:[1] optimization, numerical integration, and generating draws from a probability distribution.
samples = distribution.sample(6).round(4)
print("Using Monte-Carlo")
print(samples)

# Calculating the expected value (E) of a sample (Univariate)
distribution = chaospy.Uniform(0, 1)
expected_value = chaospy.E(distribution)
print(expected_value)

# Calculating the expected value (E) of a sample (Multivariate)
distribution = chaospy.J(chaospy.Uniform(0, 1),chaospy.Normal(0, 1))
expected_value = chaospy.E(distribution)
print(expected_value)
