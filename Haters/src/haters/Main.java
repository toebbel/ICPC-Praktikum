/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package haters;

import java.util.Scanner;

/**
 *
 * @author s_tsturm
 */
public class Main {

    static int[] q;
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int num = scan.nextInt();
        q = new int[num];

        for(int i = 0; i < num; i++)
            q[i] = scan.nextInt();

        int counter = num;
        for(int i = 0; i < num - 1 && i > 0; i++) {

            if(q[i] == -1 * q[getNextId(i)]) {
                q[i] = 0;
                q[getNextId(i)] = 0;
                counter -= 2;
                i-=2;
            }
        }
        System.out.println(counter);
    }

    private static int getNextId(int i) {
        
        for(int j = i + 1; j < q.length; j++)
            if(q[j] != 0)
                return j;
        return 0;
    }



}