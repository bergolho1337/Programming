! Algoritmo para determinar o maior número em ponto flutuante que somado a 1 resulta em 1, ou seja, qual é a precisão da máquina corrente

	PROGRAM precisao
	REAL Epsilon
	Epsilon = 1.0
	do while (.true.)
		Epsilon = Epsilon / 2.0
		if (Epsilon + 1.0 .eq. 1.0) then
			go to 10
		endif
	enddo
10 continue
	print *, Epsilon
	stop
	
	END
