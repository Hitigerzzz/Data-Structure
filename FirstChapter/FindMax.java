package FirstChapter;

/**
 * User:
 * Date:
 * Time:
 */
public class FindMax {
    static int[] a=new int[]{5,4,9,8,6,7,2,1,3,10};
    public static void main(String[] args){

//        System.out.println(finaMax(a,a.length));
        System.out.println(meanValue(a,a.length));
    }

    public static Integer finaMax(int[] a,int length){
        if(length==1)
            return a[length-1];
        if(a[length-1]>a[length-2]){
           a[length-2]=a[length-1];
        }
        return finaMax(a,length-1);
    }

    public static Double meanValue(int[] a,int length){
        if(length==1)
            return (double)a[length-1]/(double)a.length;
        a[length-2]+=a[length-1];
        return meanValue(a,length-1);
    }
}
