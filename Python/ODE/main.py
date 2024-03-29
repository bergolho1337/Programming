# y' = 1,84y^(1/2) - 1,14y^(1/4) , y(0) = 1,44
import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt

# function that returns dy/dt
def model(y,t):
    h = y
    if (h <= 6):
		return eq_1
	else:
		return eq_2

# initial condition
h0 = 4

# time points
t = np.linspace(0,100)

# solve ODE
y = odeint(model,y0,t)

# plot results
plt.plot(t,y)
plt.xlabel('time')
plt.ylabel('y(t)')
plt.show()
