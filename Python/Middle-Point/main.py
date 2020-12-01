import numpy as np

data = np.genfromtxt("points.txt")
x, y, z, lat = data[:,0], data[:,1], data[:,2],data[:,3]

new_x = (x[0]+x[1])/2.0
new_y = (y[0]+y[1])/2.0
new_z = (z[0]+z[1])/2.0
new_lat = (lat[0]+lat[1])/2.0

print("%g %g %g %g" % (new_x,new_y,new_z,new_lat))
