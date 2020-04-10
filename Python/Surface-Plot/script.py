from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import numpy as np

min_sigma_c = 1             # {mS/cm}
max_sigma_c = 10            # {mS/cm}
min_G_gap = 0.1 * 1.0e-03   # {mS}
max_G_gap = 0.9 * 1.0e-03   # {mS}

l = 0.01                    # {cm}
A = 235.6 * 1.0e-08         # {cm^2}

def func (s,G):
    return l / ( (l/s) + (A/G) ) 

sigma_c = np.linspace(min_sigma_c,max_sigma_c,25) 
G_gap = np.linspace(min_G_gap,max_G_gap,25)

X, Y = np.meshgrid(sigma_c,G_gap)
Z = func(X,Y)

fig = plt.figure()
ax = plt.axes(projection="3d")
ax.plot_surface(X, Y, Z)

plt.show()

print("sigma_bar = %g" % (func(4,0.628*1.0e-03)))