/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package domino;

import java.util.Scanner;

/**
 *
 * @author s_tsturm
 */
public class Main {

    public static long[] fibo;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        fibo = new long[1000002];
        fibo[0] = 0;
        fibo[1] = 1;
        for(int i = 2; i < 1000002; i++)
            fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 999999001;

        long result[] = new long[scan.nextInt()];
        for(int i = 0; i < result.length; i++) {
            result[i] = fibo[scan.nextInt() + 1];
        }


        for(int i = 0; i < result.length; i++) {
            System.out.println(result[i]);
        }
    }
}
