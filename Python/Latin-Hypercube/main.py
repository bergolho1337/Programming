import chaospy as cp

a = cp.Uniform(0,10)
b = cp.Uniform(0,5)

distribution = cp.J(a,b)
samples = distribution.sample(100,"L")

print samples.T

