! ========================================================
! DATA DE CRIACAO: 02-10-2014
! Programador: Lucas Arantes Berg
! ULTIMAS ALTERACOES : 09-10-2014
! ========================================================
! Programa para ordenacao de um vetor de numeros inteiros 
! --------------------------------------------------------
! Por enquanto o programa so consegue ordenar um vetor de
! tamanho 11, pretende-se amplia-lo para ordenar um vetor
! de tamanho 'n' qualquer.
! ========================================================

program ordenacao
implicit none

integer, dimension(11) :: a
integer :: i, j, aux

! ATRIBUI VALORES DESORDENADOS AO VETOR
a(1) = 1; a(2) = 211; a(3) = 979; a(4) = 31; a(5) = 93
a(6) = 327; a(7) = 7; a(8) = 35; a(9) = 56; a(10) = 211; a(11) = 527

!IMPRIME O VETOR DESORDENADO
write (*,*) "Vetor desordenado"
do i=1, 11
	write (*,*) a(i)
end do

! REALIZA A ORDENACAO INSERTION_SORT
! A ideia da ordenacao eh parecida com a ordenacao de cartas em um baralho. Para a carta que estamos no momento (i) iremos verificar se existe
! alguma outra para tras que eh menor em valor. Se sim, realizamos uma troca entre os elementos. De modo que, iremos passar todos os elementos
! uma posicao a frente. Fazendo isto iremos garantir que todos os elementos a esquerda do elemento (i) estejam ordenados.
do i=1, 11
	aux = a(i)
	j = i-1
	do while ( (j > 0) .AND. (aux < a(j)) )
		a(j+1) = a(j)
		j = j - 1
	end do
	a(j+1) = aux
end do

write (*,*) "Vetor em ordem crescente"
!IMPRIME O VETOR EM ORDEM CRESCENTE
do i=1, 11
	write (*,*) a(i) 
end do

!REALIZA NOVAMENTE O INSERTION_SORT POREM MUDANDO A CONDICAO DA TROCA, ISTO IRA GERAR O VETOR EM ORDEM DECRESCENTE
do i=1, 11
	aux = a(i)
	j = i-1
	do while ( (j > 0) .AND. (aux > a(j)) )
		a(j+1) = a(j)
		j = j - 1
	end do
	a(j+1) = aux 
end do

write (*,*) "Vetor em ordem decrescente"
!IMPRIME O VETOR EM ORDEM DECRESCENTE
do i=1, 11
	write (*,*) a(i)
end do

end program ordenacao
