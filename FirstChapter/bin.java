
/**
 * User:
 * Date:
 * Time:
 */
public class bin {

    public static void main(String[] args){
        System.out.println(oneNum(8));
    }

    public static int oneNum(int num){
        if(num==1)
            return 1;
        return oneNum(num/2)+num%2;
    }

    
}
