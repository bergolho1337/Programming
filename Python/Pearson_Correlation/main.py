import numpy as np

# Input 1
#x = np.array([-2,-1,0,1,2])
#y = np.array([4,1,3,2,0])

# Input 2
x = np.array([6,8,10])
y = np.array([12,10,20])

r = np.corrcoef(x,y)
print("Pearson correlation = %g" % (r[0][1]))