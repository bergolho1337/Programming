! ========================================================
! DATA DE CRIACAO: 16-11-2014
! Programador: Lucas Arantes Berg
! ULTIMAS ALTERACOES : 20-11-2014
! ========================================================
! Programa que aproxima pi, sen(x) e cos(x) 
! ========================================================

program trabalho2
implicit none

real(kind=4) :: i, S, pi, pi_old
real(kind=8) :: j, S_DOUBLE, PI_DOUBLE, PI_OLD_DOUBLE, x1, x2, x3, seno, cosseno

! INICIALIZA OS PARÂMETROS USADOS NO PROGRAMA
i = 1
S = 0
pi = 0
pi_old = 1
j = 1
S_DOUBLE = 0
PI_DOUBLE = 0
PI_OLD_DOUBLE = 1 


! PERMANECE EM LOOP ATE QUE O VALOR DE PI TENHA CONVERGIDO PARA UM VALOR
! DA SERIE QUE SEJA MENOR QUE A PRECISAO DE FLOAT.
do while (abs(pi - pi_old) >= 1.0e-06)
	pi_old = pi	
	S = S + ( (-1)**(i+1) / (2*i - 1)**3 )
	pi = (32.0*S)**(1.0/3.0)
	i = i + 1
end do

write(*,*) '---------- VALOR DE PI -------------'
write(*,*) '===== PRECISAO SIMPLES ====='
write(*,*) 'Valor de pi = ',pi
write(*,*) 'Diferenca entre os dois ultimos termos da serie = ',(abs(pi - pi_old))
write(*,*) 'Numero de termos da serie necessarios --> ',i

! ABRE O ARQUIVO DE SAIDA PARA A APROXIMACAO DE PI
open(UNIT=20,FILE='pi.dat',STATUS='REPLACE',ACTION='WRITE')

! PERMANECE EM LOOP ATE QUE O VALOR DE PI TENHA CONVERGIDO PARA UM VALOR
! DA SERIE QUE SEJA MENOR QUE PRECISAO DE DOUBLE.
do while (abs(PI_DOUBLE - PI_OLD_DOUBLE) >= 1.0e-14)
	PI_OLD_DOUBLE = PI_DOUBLE	
	S_DOUBLE = S_DOUBLE + ( (-1)**(j+1) / (2*j - 1)**3 )
	PI_DOUBLE = (32.0*S_DOUBLE)**(1.0/3.0)
	! ESCREVE NO ARQUIVO	
	if (j < 100) then	
		write(20,*) j, PI_DOUBLE
	end if
	j = j + 1
end do

write(*,*) '===== PRECISAO DUPLA ====='
write(*,900) 'Valor de pi =',PI
write(*,*) 'Diferenca entre os dois ultimos termos da serie = ',(abs(PI_DOUBLE - PI_OLD_DOUBLE))
write(*,*) 'Numero de termos da serie necessarios --> ',j

! FECHA O ARQUIVO DE PI
close(20)

! REALIZA A LEITURA DOS 3 ÂNGULOS
write(*,*) '-------- LENDO ANGULOS ---------'
write(*,*) 'Digite um angulo em graus: '
read(*,*) x1
write(*,*) 'Digite um angulo em graus: '
read(*,*) x2
write(*,*) 'Digite um angulo em graus: '
read(*,*) x3

! CALCULA A APROXIMAÇÃO DO SENO
write(*,*) '---------- VALOR DE SENO -------------'
open(UNIT=21,FILE='seno.dat',STATUS='REPLACE',ACTION='WRITE')
call calculaSeno(x1,PI_DOUBLE,seno)
call calculaSeno(x2,PI_DOUBLE,seno)
call calculaSeno(x3,PI_DOUBLE,seno)
close(21)

! CALCULA A APROXIMAÇÃO DO COSSENO
write(*,*) '---------- VALOR DE COSSENO -------------'
open(UNIT=22,FILE='cosseno.dat',STATUS='REPLACE',ACTION='WRITE')
call calculaCosseno(x1,PI_DOUBLE,cosseno)
call calculaCosseno(x2,PI_DOUBLE,cosseno)
call calculaCosseno(x3,PI_DOUBLE,cosseno)
close(22)



! ============================================================================
! DEFINE OS FORMATOS DE SAIDA
900 format (a13,1x,f20.15)

end program trabalho2


! ===========================================================================
! DEFINE A SUBROTINA QUE CALCULA O SENO
subroutine calculaSeno (x,pi,seno)
implicit none

real(kind=8), intent(in) :: pi, x
real(kind=8) :: i, seno_old, seno, Fat, x_rad

i = 0
seno = 0
seno_old = 2

! CONVERTE PARA RADIANOS
x_rad = (x*pi)/180.0

do while (abs(seno - seno_old) >= 1.0e-14)
	seno_old = seno	
	call Fatorial(2*i+1,Fat)
	seno = seno + ( (-1)**i / Fat )*(x_rad**(2*i+1))
	if (i < 100) then	
		write(21,*) i, seno
	end if
	i = i + 1
end do

write(21,*) ' '
write(*,*) '===== PRECISAO DUPLA ====='
write(*,*) 'sen(',x,') = ',seno
write(*,*) 'Numero de termos da serie = ',i

end subroutine

! ===========================================================================
! DEFINE A SUBROTINA QUE CALCULA O COSSENO
subroutine calculaCosseno (x,pi,cosseno)
implicit none

real(kind=8), intent(in) :: pi, x
real(kind=8) :: i, cosseno_old, cosseno, Fat, x_rad

i = 0
cosseno = 0
cosseno_old = 1

! CONVERTE PARA RADIANOS
x_rad = (x*pi)/180.0

do while (abs(cosseno - cosseno_old) >= 1.0e-14)
	cosseno_old = cosseno	
	call Fatorial(2*i,Fat)
	cosseno = cosseno + ( (-1)**i / Fat )*(x_rad**(2*i))
	if (i < 100) then	
		write(22,*) i, cosseno
	end if
	i = i + 1
end do

write(22,*) ' '
write(*,*) '===== PRECISAO DUPLA ====='
write(*,*) 'cos(',x,') = ',cosseno
write(*,*) 'Numero de termos da serie = ',i

end subroutine

! ==========================================================================
! DEFINE SUBROTINA QUE CALCULA O FATORIAL DE UM NUMERO
subroutine Fatorial (i,Fat)
implicit none

real(kind=8) :: i, k
real(kind=8), intent(out) :: Fat

k = i
Fat = k

if (k == 0) then
	Fat = 1
end if

do while (k > 1.0)
	k = k - 1.0
	Fat = Fat*k 
end do 

return
end subroutine

