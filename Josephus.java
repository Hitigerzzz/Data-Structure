

public class Josephus {
	public static void main(String[] args) {
	    int n = 500, m = 3;
	    int answer = 0;  
        for(int i = 2; i <= n; i++) {  
            answer = (answer + m) % i;  
        }  
        System.out.println("Survival: " + (answer+1)); 
	}
}
