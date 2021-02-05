! Programa para converter graus Fahrenheit em graus Celsius

	PROGRAM Converte_Grau

	REAL Celsius, Fahrenheit
	open(1,file='fahrenheit.dat',status='old')
	open(2,file='celsius.sai',status='new')
	read(1,11) Fahrenheit
	Celsius = (Fahrenheit - 32.) * 5. / 9.
	write(2,12) Fahrenheit, Celsius
	close(2,status='keep')
	stop
11 format(f5.0)
12 format(f8.3,' Fahrenheit = ', f8.3,' Celsius')
	END

