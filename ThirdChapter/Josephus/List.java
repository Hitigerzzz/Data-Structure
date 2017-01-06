package ThirdChapter.Josephus;

public class List {

    public ListNode header;
    public ListNode lastNode;

    public List(){
        header=new ListNode();
    }

    public ListItr first(){
        return new ListItr(header.next);
    }

    public ListItr zero(){return new ListItr(header);}

    public void insert(ListNode newNode){
        if(header.next==null){
            header.next=newNode;
            lastNode=newNode;
        }else {
            lastNode.next=newNode;
            lastNode=newNode;
        }
    }
}
