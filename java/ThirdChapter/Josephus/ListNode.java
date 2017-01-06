package ThirdChapter.Josephus;

public class ListNode {

    public int id;
    public ListNode next;

    public ListNode(){}

    public ListNode(int id){
        this(id,null);
    }

    public ListNode(int id, ListNode n){
        this.id = id;
        this.next=n;
    }
}
