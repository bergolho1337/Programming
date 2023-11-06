import numpy as np
import scipy
import matplotlib.pyplot as plt

def pend (y, t, b, c):
	theta, omega = y
	dydt = [omega, -b*omega - c*np.sin(theta)]
	return dydt

def main ():
	b = 0.25
	c = 5.0

	y0 = [np.pi - 0.1, 0.0]
	t = np.linspace(0, 10, 101)

	sol = scipy.integrate.odeint(pend, y0, t, args=(b,c))
	#print(sol)

	plt.plot(t, sol[:,0], 'b', label="theta(t)")
	plt.plot(t, sol[:,1], 'g', label="omega(t)")
	plt.legend(loc=0)
	plt.title("Pendulum")
	plt.xlabel("t")
	plt.grid()
	plt.show()

if __name__ == "__main__":
	main()
