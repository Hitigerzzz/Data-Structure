package Test;

/**
 * User:
 * Date:
 * Time:
 */
public class test {
    public static void main(String[] args) {
        int n=10;
        //申请第一维的空间
        int mat[][]=new int[n][];
        int i,j;
        for (i=0;i<n;i++) {
            //申请第二维的空间
            mat[i]=new int[i+1];
            //首末设为1
            mat[i][0]=1;
            mat[i][i]=1;
            //中间数
            for (j=1;j<i;j++) {
                mat[i][j]=mat[i-1][j-1]+mat[i-1][j];
            }

            //输出
            for (i=0;i<mat.length;i++) {
                //每行前面输出空格
                for (j=0;j<n-i;j++)
                    System.out.print(" ");
                //输出数字
                for (j=0;j<mat[i].length;j++)
                    System.out.print(" "+mat[i][j]);
                //换行
                System.out.println();
            }
        }

    }
}
