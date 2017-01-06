import java.util.ArrayList;
public class listsize{
	static ArrayList<Integer> list=new ArrayList<Integer>();
	public static void main(String[] args) {
		list.add(0);
		list.add(1);
		list.add(2);
		System.out.println(calSize(list));
	}

	public static int calSize(ArrayList list){
		if(list.isEmpty()){
			return 0;
		}
		list.remove(0);
		return calSize(list)+1;
	}
}