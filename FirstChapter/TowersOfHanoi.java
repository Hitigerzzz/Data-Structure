package FirstChapter;
import java.util.Scanner;

/**
 * User:
 * Date:
 * Time:
 */
public class TowersOfHanoi {

    public static void main(String[] args){
        System.out.println("Enter number of disks" );
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        sc.close();

        System.out.println( "The move are:");
        moveDISKs(n, 'A','B','C');
    }

    private static void moveDISKs(int n, char fromTower, char toTower, char auxTower) {
        if (n==1){
            System.out.println("move disk "+n+" from "+fromTower+" to "+toTower);
        }else {
            moveDISKs(n-1,fromTower,auxTower,toTower);
            System.out.println("move disk "+n+" from "+fromTower+" to "+toTower);
            moveDISKs(n-1,auxTower,toTower,fromTower);
        }
    }
}
