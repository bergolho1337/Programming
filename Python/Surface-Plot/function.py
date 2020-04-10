from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import numpy as np

min_sigma_c = 1             # {mS/cm}
max_sigma_c = 10            # {mS/cm}
#min_G_gap = 0.1 * 1.0e-03   # {mS}
#max_G_gap = 0.9 * 1.0e-03   # {mS}

l = 0.01                    # {cm}
A = 235.6 * 1.0e-08         # {cm^2}

def func (s_bar,s):
    return (-s_bar*s*A)/(s_bar*l-l*s) 

def func2 (s,G):
    return l / ( (l/s) + (A/G) )

sigma_c = np.linspace(min_sigma_c,max_sigma_c,100) 
sigma_bar = 1.59959

G_gap = func(sigma_bar,sigma_c)

for i in range(len(sigma_c)):
    print("%g %g = %g" % (sigma_c[i],G_gap[i],func2(sigma_c[i],G_gap[i])))

plt.plot(sigma_c,G_gap)
plt.show()
