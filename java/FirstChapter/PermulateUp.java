package FirstChapter;

import java.util.Scanner;

/**
 * User:
 * Date:
 * Time:
 */
public class PermulateUp {

    private static int n;

    private static int r;

    private static char[] nums;

    public static void main(String[] args){
        System.out.println("Input number n:");
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        System.out.println("Input number r:");
        r=sc.nextInt();
        sc.close();
        nums=new char[n];
        for (int i=1;i<=n;i++){
            nums[i-1]= (char) ('0'+(char)i);
        }
        perm(nums,0,n);

    }

    public static void perm(char[] list,int k,int m){
        int i;
        if(k==r){
            for (i=0;i<r;i++){
                System.out.print(list[i]);
            }
            System.out.println();
        }else {
            for(i=k;i<m;i++){
                swap(list,k,i);
                perm(list,k+1,m);
                swap(list,k,i);
            }
        }
    }


    public static void swap(char[] str, int i, int j)
    {
        char temp;
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
