! Programa para verificar a propriedade que diz que a soma de 'n' números ímpares é n^2

	PROGRAM soma_impares
	INTEGER n, i
	REAL Soma
	
	read *, n
	Soma = 0.0
	do i=1, 2*n - 1, 2
		Soma = Soma + i
	enddo
	print *, 'Soma = ', Soma, ' n^2 = ', n**2
	END
