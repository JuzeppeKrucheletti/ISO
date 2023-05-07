param N, integer, >0; #число продуктов
param c {1..N}, >0; #вектор стоимости моркови и яблок
param a {1..N,1..N+1};#матрица ограничений
var x {1..N}, >= 0;#переменные решения

minimize totalcost: sum{i in 1..N} c[i]*x[i];

subject to nutrition {i in 1..N} : sum{j in 1..N} a[i,j]*x[j] >= a[i, N+1]
