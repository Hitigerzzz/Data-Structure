package ThirdChapter.Josephus;

import java.util.Scanner;

/**
 * User:
 * Date:
 * Time:
 */
public class JosephusArray {
    public static void main(String args[]){
        System.out.print("输入人数：");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.print("输入报数：");
        int m=sc.nextInt();
        sc.close();
        System.out.print("存活的人："+survival(n,m));
    }

    private static int survival(int n, int m) {
        //初始化数组
        int nums[]=new int[n];
        for (int i=0;i<n;i++){
            nums[i]=i+1;
        }

        int index=0;//删除的位置
        while (n>1){
            index=(index+m-1)%n;
            System.out.println(nums[index]+"被删除");
            //移动数组
            for (int j=index+1;j<n;j++){
                nums[j-1]=nums[j];
            }

            n--;
            if(index==n){
                index=0;
            }
        }
        return nums[index];
    }
}
