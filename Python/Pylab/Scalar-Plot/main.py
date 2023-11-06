import numpy as np
import pylab as pl

pl.rcParams["image.cmap"] = "jet"

x = np.random.uniform(-1, 1, 1000)
y = np.random.uniform(-1, 1, 1000)

z = np.sqrt(x*x+y*y)

pl.scatter(x, y, c=z)
pl.colorbar()
pl.show()
