  package FirstChapter;

/**
 * User:
 * Date:
 * Time:
 */
public class palindromes {

    public static void main(String[] args){
        System.out.println(checkPalindromes("Madam, I‟m Adam"));
    }

    private static boolean checkPalindromes(String str){
        //去除格式
        str=str.toLowerCase();
        char[] tempArray=str.toCharArray();
        StringBuilder strBuilder=new StringBuilder();
        for (int i=0;i<tempArray.length;i++){
            if(tempArray[i]>('a'-1)&&tempArray[i]<('z'-1)){
                strBuilder.append(tempArray[i]);
            }
        }
        str=strBuilder.toString();
        if(str.equals(reverseStr(str))){
            return true;
        }
        return false;
    }

    private static String reverseStr(String str) {
        if(str.length()==1){
            return str;
        }
        return reverseStr(str.substring(1))+str.substring(0,1);
    }
}
