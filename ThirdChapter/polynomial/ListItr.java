package ThirdChapter.polynomial;

public class ListItr {

    public ListNode current;

    public ListItr(ListNode node){
        this.current=node;
    }

    public boolean isPastEnd(){
        return current==null;
    }

    public void advance(){
        if(!isPastEnd()){
            current=current.next;
        }
    }
}
