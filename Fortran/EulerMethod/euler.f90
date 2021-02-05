! Programa que utiliza o Método de Euler para resolver um PVI

	PROGRAM euler
	! Entrada	
	REAL a, b, y0, m
	REAL h, Fxy, x, y
	a = 0.0
	b = 1.0
	y0 = 1.0
	m = 10

		
	! Algoritmo em si	
	h = (b - a) / m
	x = a
	y = y0
	Fxy = avaliaFuncao(x,y)
	print *, Fxy  
	END

	REAL function avaliaFuncao (x,y)
		avaliaFuncao = x - 2*y + 1
	END
