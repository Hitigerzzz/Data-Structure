package ThirdChapter.polynomial;

public class Polynomial {
    public List list1=new List();
    public List list2=new List();

    public static void main(String args[]){
        Polynomial pol=new Polynomial();
        List result=pol.add(pol.list1,pol.list2);
        pol.printList(result);
    }
    public Polynomial(){
        initPoly1();
        initPoly2();
    }
    /*
    初始化第一个多项式的数据
     */
    private void initPoly1() {
        list1.insert(new ListNode(2,100));
        list1.insert(new ListNode(3,14));
        list1.insert(new ListNode(2,8));
        list1.insert(new ListNode(1,0));
    }
    /*
    初始化第二个多项式的数据
     */
    private void initPoly2() {
        list2.insert(new ListNode(-2,100));
        list2.insert(new ListNode(8,14));
        list2.insert(new ListNode(-3,10));
        list2.insert(new ListNode(10,6));
        list2.insert(new ListNode(-1,1));
    }

    public List add(List list1,List list2){
        List resultList=new List();
        ListItr pa=list1.first();
        ListItr pb=list2.first();
        ListItr pc=resultList.zero();

        while (!pa.isPastEnd()&&!pb.isPastEnd()){
            ListNode newNode=new ListNode();

                if(pa.current.exp==pb.current.exp){
                    newNode.coef=pa.current.coef+pb.current.coef;
                    if(newNode.coef!=0){//系数不为0
                        newNode.exp=pa.current.exp;
                        resultList.insert(newNode);
                        pc.advance();
                    }
                    pa.advance();
                    pb.advance();
                }else if (pa.current.exp<pb.current.exp){//pb要插入结果链表
                    newNode=pb.current;
                    resultList.insert(newNode);
                    pc.advance();
                    pb.advance();
                }else {
                    newNode=pa.current;
                    resultList.insert(newNode);
                    pc.advance();
                    pa.advance();
                }
        }

        if(pa.isPastEnd()){
            pc.current.next=pb.current;
        }else if (pb.isPastEnd()){
            pc.current.next=pa.current;
        }

        return resultList;
    }

    public void printList(List list){
        ListItr p=list.first();
        boolean isFirst=true;
        while (!p.isPastEnd()){
            if(isFirst){
                System.out.print(p.current.coef+"x^"+p.current.exp);
                p.advance();
                isFirst=false;
            }

            if(p.current.exp==0){
                System.out.print("+"+p.current.coef);
            }else if(p.current.coef>0){
                if(p.current.coef==1){
                    System.out.print("+"+"x^"+p.current.exp);
                }else{
                    System.out.print("+"+p.current.coef+"x^"+p.current.exp);
                }
            }else if(p.current.coef<0){
                if(p.current.coef==-1){
                    System.out.print("-"+"x^"+p.current.exp);
                }else {
                    System.out.print(p.current.coef+"x^"+p.current.exp);
                }
            }
            p.advance();
        }
    }
}
