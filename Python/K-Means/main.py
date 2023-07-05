import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

# The "elbow" method helps data scientists to select the optimal number of clusters 
# by fitting the model with a range of values for K
# WCSS is the sum of squared distance
def calculate_elbow (x):
    wcss = []
    for i in range(1,11):
        kmeans = KMeans(n_clusters=i, init='random')
        kmeans.fit(x)
        print(i, kmeans.inertia_)
        wcss.append(kmeans.inertia_)

    plt.plot(range(1,11),wcss)
    plt.title("Elbow method (K-Means) - Right Ventricle")
    plt.xlabel("Number of clusters")
    plt.ylabel("WCSS")
    #plt.show()
    plt.savefig("elbow_result.pdf")

def write_point_data_to_vtk (coords,labels):
    n = len(coords)
    file = open("pmj_data.vtk","w")
    file.write("# vtk DataFile Version 4.1\n")
    file.write("vtk output\n")
    file.write("ASCII\n")
    file.write("DATASET POLYDATA\n")
    file.write("POINTS %d float\n" % (n))
    for i in range(n):
        file.write("%g %g %g\n" % (coords[i][0],coords[i][1],coords[i][2]))
    file.write("VERTICES %d %d\n" % (n,n*2))
    for i in range(n):
        file.write("1 %d\n" % i)
    file.write("POINT_DATA %d\n" % (n))
    file.write("FIELD FieldData 1\n")
    file.write("Labels 1 %d float\n" % (n))
    for i in range(n):
        file.write("%g\n" % (labels[i]))
    file.close()

def write_cluster_centers_to_vtk (centers):
    n = len(centers)
    file = open("cluster_centers.vtk","w")
    file.write("# vtk DataFile Version 4.1\n")
    file.write("vtk output\n")
    file.write("ASCII\n")
    file.write("DATASET POLYDATA\n")
    file.write("POINTS %d float\n" % (n))
    for i in range(n):
        file.write("%g %g %g\n" % (centers[i][0],centers[i][1],centers[i][2]))
    file.write("VERTICES %d %d\n" % (n,n*2))
    for i in range(n):
        file.write("1 %d\n" % i)
    file.write("POINT_DATA %d\n" % (n))
    file.write("FIELD FieldData 1\n")
    file.write("Labels 1 %d float\n" % (n))
    for i in range(n):
        file.write("%d\n" % (i))
    file.close()

pmj_data = pd.read_csv("sebastian_pmj_data_LV.csv")
normalized_pmj_data = (pmj_data-pmj_data.min())/(pmj_data.max()-pmj_data.min())
#X = pmj_data.iloc[:, 0:4].values
#X = normalized_pmj_data.iloc[:, 0:4].values
coords = pmj_data.iloc[:, 1:4].values
LAT = pmj_data.iloc[:, 0:1].values
LAT_normalized = normalized_pmj_data.iloc[:, 0:1].values
#calculate_elbow(LAT)

kmeans = KMeans(n_clusters=4, init='random')
kmeans.fit(LAT)
labels = kmeans.labels_
centers = kmeans.cluster_centers_

kmeans.fit(coords)
centers = kmeans.cluster_centers_

write_point_data_to_vtk(coords,labels)
write_cluster_centers_to_vtk(centers)