 set title 'Magnetização'
 set grid
 set xlabel 'passos'
 set ylabel 'M'
 set yrange [0:150]
 set terminal png
 set key bottom right
 set output 'grafico2.png'
 plot 'dados2.dat' title 'M_total' w l
