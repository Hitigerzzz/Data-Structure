package ThirdChapter.polynomial;

public class ListNode {

    public int coef;
    public int exp;
    ListNode next;

    public ListNode(){}

    public ListNode(int coef,int exp){
        this(coef,exp,null);
    }

    public ListNode(int coef,int exp,ListNode n){
        this.coef=coef;
        this.exp=exp;
        this.next=n;
    }
}
