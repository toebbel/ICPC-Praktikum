
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */



/**
 *
 * @author s_tsturm
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int numCases = scan.nextInt();
        int[] results = new int[numCases];
        for(int i = 0; i < numCases; i++) {
            int roomNum = scan.nextInt();
            results[i] = roomNum * roomNum;
        }

        for (int i = 0; i < numCases; i++) {
            System.out.println(results[i]);
        }
    }

}
