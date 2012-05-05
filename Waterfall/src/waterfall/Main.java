/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package waterfall;

import java.util.Scanner;

/**
 *
 * @author s_tsturm
 */
public class Main {

    public static int[][] friends; //row (0 is top), friend-Index
    public static int[][] maxFriends;
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int numTestCases = scan.nextInt();
        for(int curr = 0; curr < numTestCases; curr++) {
            /////////// read input
            int numRows = scan.nextInt();
            friends = new int[numRows][];
            maxFriends  = new int[numRows][];

            for(int currRow = 0; currRow < numRows; currRow++) {
                friends[currRow] = new int[currRow + 1];
                maxFriends[currRow] = new int[currRow + 1];
                
                for(int currFriend = 0; currFriend < currRow + 1; currFriend++) {
                    friends[currRow][currFriend] = scan.nextInt();
                    maxFriends[currRow][currFriend] = 0;
                }
            }

            maxFriends[numRows - 1] = friends[numRows - 1];
            /////////// calc
            for(int i = numRows - 2; i >= 0; i--) { //go down up
                for(int j = 1; j < maxFriends[i].length - 1; j++) {
                    if(maxFriends[i - 1][j] < maxFriends[i - 1][j - 1])
                        maxFriends[i][j] = maxFriends[i - 1][j - 1];
                    else
                        maxFriends[i][j] = maxFriends[i - 1][j];
                }
            }
            ///////////
            System.out.println(maxFriends[0][0]);
        }
    }

}
