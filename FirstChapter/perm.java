package FirstChapter;

/**
 * User:
 * Date:
 * Time:
 */
public class perm {

    static char[] list=new char[]{'a','b','c'};

    public static void main(String args[]){
        perm(list,0,2);
    }

    public static void perm(char[] list,int k,int m){
        int i;

        if(k==m){
            for (i=0;i<=m;i++){
                System.out.print(list[i]);
            }
            System.out.println();
        }else {
            for(i=k;i<=m;i++){
               swap(list,k,i);
                perm(list,k+1,m);
                swap(list,k,i);
//                swap(list,list[k],list[i]);
//                perm(list,k+1,m);
//                swap(list,list[k],list[i]);
            }
        }
    }
    //
    public static void swap(char[] list,char a,char b){
        char temp;
        temp=a;
        a=b;
        b=temp;
    }

    public static void swap(char[] str, int i, int j)
    {
        char temp;
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

}
