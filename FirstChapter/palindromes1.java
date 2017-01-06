

public class palindromes1{

	public static void main(String[] args) {
		System.out.println(checkPalindromes("abcbd"));
	}

	private static boolean checkPalindromes(String str){
		if (str.length()==1||str.length()==0) {
			return true;
		}else if(str.charAt(0)!=str.charAt(str.length()-1)){
			return false;
		}
		return checkPalindromes(str.substring(1,str.length()-1));
	}
}