# ==================================================================================================
# In this example, it is demonstrate how to perform a Linear Regresson 
# with Least Squares method using the ChaosPy default 
# scipy.linalg.lstsq() function and using the LinearRegression model
# from the sklearn package.
#
# LinearRegression:
# 	Fits a linear model with coefficients w = (w1, ..., wp) to minimize the residual 
# sum of squares between the observed targets in the dataset, and the targets predicted 
# by the linear approximation.
#	One major application of this method is in data fitting. It is used when we want to predict the 
# value of a variable based on the value of another one. The variable we want to predict is 
# called the dependent variable (or sometimes, the outcome variable).
# ==================================================================================================

import sklearn
import numpy
import chaospy
from matplotlib import pyplot
from sklearn.linear_model import LinearRegression
from chaospy.example import coordinates, exponential_model, distribution, error_mean, error_variance

def plot_data (samples, evals):
	pyplot.rc("figure", figsize=[15, 6])
	pyplot.plot(samples, evals)
	pyplot.show()

def calc_errors (samples,fitted_polynomial):
	self_evals = fitted_polynomial(*samples)
	error_mean = chaospy.E(fitted_polynomial, distribution)
	error_var = chaospy.Var(fitted_polynomial, distribution)
	return error_mean, error_var

samples = numpy.linspace(0, 5, 50)
numpy.random.seed(1000)
noise = chaospy.Normal(0, 0.1).sample(50)
evals = numpy.sin(samples) + noise
# Plot the result
#pyplot.scatter(samples, evals)
#plot_data(samples,evals)

# Using Scipy
q0 = chaospy.variable()
expansion = chaospy.polynomial([1, q0, q0**2, q0**3])
fitted_polynomial = chaospy.fit_regression(expansion, samples, evals)
# Calculate errors
#error_mean, error_var = calc_errors(samples,fitted_polynomial)
#print("Error using Scipy Least Squares Regression: %g +/- %g" % (error_mean,numpy.sqrt(error_var)))
# Plot the result
#pyplot.scatter(samples, evals)
#plot_data(samples,fitted_polynomial(samples))

# Using Sklearn
model = LinearRegression(fit_intercept=False)
fitted_polynomial = chaospy.fit_regression(expansion, samples, evals, model=model)
# Calculate errors
error_mean, error_var = calc_errors(samples,fitted_polynomial)
print("Error using Scipy Least Squares Regression: %g +/- %g" % (error_mean,numpy.sqrt(error_var)))
#pyplot.scatter(samples, evals)
#plot_data(samples,fitted_polynomial(samples))

