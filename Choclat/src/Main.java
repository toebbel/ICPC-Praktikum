
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

    public static int count = 0;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        while(scan.hasNextInt()) {
            count = 0;
            int w = scan.nextInt();
            int h = scan.nextInt();
            System.out.println(w * h - 1);
        }
    }


}
