import numpy as np

file = open("sample.dat","w")
mu = 
sigma = 7.121111111
n = 674
s = np.random.normal(mu, sigma, n)
is_ok = False

#while (~is_ok):
#    s = np.random.normal(mu, sigma, n)
#    mean = np.mean(s)
#    std = np.std(s)
#    if (abs(mu-mean) < 1.0e-00 and abs(sigma-std) < 1.0e-00):
#        is_ok = True

for value in s:
    file.write("%g\n" % (value))
print("%g +/- %g" % (np.mean(s),np.std(s)))