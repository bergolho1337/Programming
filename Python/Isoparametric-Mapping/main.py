import numpy as np

def write_to_file (filename,points):
	n = len(points)
	file = open(filename,"w")
	file.write("# vtk DataFile Version 4.1\n")
	file.write("vtk output\n")
	file.write("ASCII\n")
	file.write("DATASET POLYDATA\n")
	file.write("POINTS %u float\n" % (n))
	for i in range(n):
		file.write("%g %g %g\n" % (points[i][0],points[i][1],points[i][2]))
	file.write("VERTICES %u %u\n" % (n,n*2))
	for i in range(n):
		file.write("1 %u\n" % (i))
	file.close()

def normal_optimization (points):
	mapped_points = []
	npts = 6
	t = 0.3
	d_eta = 1.0/5.0
	d_neta = 1.0/5.0
	G = points[0]
	F = points[1]
	E = points[3]
	for i in range(0,npts,1):
		for j in range(0,npts-i,1):
			epsilon = i * d_eta
			eta = j * d_eta
			phi = (1 - epsilon - eta)
			pos = phi * G + epsilon * F + eta * E;
			mapped_points.append(pos)
	return np.array(mapped_points)
	
def rafael_optimization (points):
	mapped_points = []
	npts = 6
	t = 0.3
	d_eta = 1.0/5.0
	d_neta = 1.0/5.0
	E = points[1] + (points[0] - points[1]) * (1-t)
	F = points[3] + (points[2] - points[3]) * (t)
	G = points[1] + (points[0] - points[1]) * (t)
	for i in range(npts,0,-1):
		for j in range(1,i+1,1):
			neta = (npts-i) * d_neta
			eta = (j - 1) * d_eta
			phi = (1 - eta - neta)
			pos = (1 - eta - neta) * G + eta * F + neta * E;
			mapped_points.append(pos)
	return np.array(mapped_points)
	
points = np.array([[0,0,0],[2,0,0],[1,0,0],[2,2,0]])
mapped_points = rafael_optimization(points)
mapped_points2 = normal_optimization(points)

write_to_file("points.vtk",points)
write_to_file("mapped_points.vtk",mapped_points)
write_to_file("mapped_points_2.vtk",mapped_points2)
