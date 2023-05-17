import java.util.*;
import java.io.*;
class Rucksack {
    Integer[] w;
    Integer[] c;
    Integer W;
    public Rucksack(Integer[]w, Integer[] c, Integer W){
        this.c = c;
        this.w = w;
        this.W = W;
    }
    public void Solve(){
        int n = w.length;
        Integer [][] f = new Integer[n+1][W+1];
        Integer[][] p = new Integer[n+1][W+1];
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < W+1; j++ )
                f[i][j] = 0;
        }

        for(int i = 1; i < n+1; i++) {
            for (int k = 1; k < W + 1; k++) {
                if (k >= w[i - 1]) {
                    f[i][k] = Math.max(f[i - 1][k], f[i][k - w[i - 1]] + c[i - 1]);
                } else {
                    f[i][k] = f[i - 1][k];
                }
                if(f[i][k]==f[i-1][k]) p[i][k] = 0;
                else p[i][k] = 1;
            }
        }
                    // обратный ход
        Integer [] items = new Integer[n];
        for(int i = 0; i < n; i++){
            items[i] = 0;
        }
        int t = W;
        int i = n;
        while(i != 0 && t != 0){
        if (p[i][t] == 1){
        items[i - 1] += 1;
        t -= w[i - 1];
        }
    else i -= 1;
        }

        System.out.println("Максимальная стоимость товаров при ограничениях на вес: " + f[n][W]);
        for(i = 0; i < n; i++){
            System.out.println("x" + (i+1) + " = " + items[i]);
        }
        System.out.println("Матрица f:");
        for(int k = 0; k < W+1; k ++){
        for(int j = 1; j < n+1; j++){
                System.out.print(f[j][k]+" ");
            }
            System.out.println("");
        }
        System.out.println("Матрица p:");
        for(int k = 1; k < W+1; k ++){
            for(int j = 1; j < n+1; j++){
                System.out.print(p[j][k]+" ");
            }
            System.out.println("");
        }
    }
}

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Integer W = 9;
        Integer c[] = { 3, 7, 17 };
        Integer w[] = { 2, 3, 7 };
        Rucksack R = new Rucksack(w,c,W);
        R.Solve();
    }
}