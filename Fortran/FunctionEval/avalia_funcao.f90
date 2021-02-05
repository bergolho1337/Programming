! Programa para avaliar a função modular f(x) = |2x|

	PROGRAM avalia_funcao
	
	REAL fx, x	
	read *, x
	if (x .ge. 0.0) then
		 fx = 2.0 * x
	else
		fx = -2.0 * x
	endif	
	print *, 'x = ', x, '  Fx = ', fx 
	stop
	
	END
