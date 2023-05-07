set N := 1..4;
set K := 1..4;
param D{N, K};
var y{N, K}, binary;
subject to ogran_1{j in K}: sum{i in N} D[i,j]*y[i, j] = 3;
subject to ogran_2{i in N}: sum{j in K} D[i,j]*y[i, j] = 3;