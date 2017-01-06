package ThirdChapter.Josephus;

import java.util.Scanner;

/**
 * Created by:Hitiger
 * Date: 2016/11/6   Time: 18:50
 * Description:
 */
public class JosephusList {
    private static List list;

    public static void main(String args[]){
        System.out.print("输入人数：");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.print("输入报数：");
        int m=sc.nextInt();
        sc.close();
        createInitList(n,m);
        killPeople(list,n,m);
    }

    private static void killPeople(List list,int n,int m) {
        //指向要出对列的前一个结点
        ListItr rear = list.zero();
        //指向链表的尾结点
        ListNode p = null;
        //指向出队列结点链表的开头结点
        ListNode head = null;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m-1; j++) rear.advance();
            if (i == 1){
                head = rear.current.next;
                p = head;
            }else {
                p.next = rear.current.next;
                p = rear.current.next;
            }
            //kill people
            rear.current.next = p.next;
        }

        p.next = rear.current;
        rear.current.next = null;

        System.out.print("存活的人："+p.id);
    }

    private static void createInitList(int n, int m) {
        list = new List();
        ListNode node = null;
        for (int i = 0;i < n;i++){
            node = new ListNode(i + 1);
            list.insert(node);
        }

        //末结点连接到第一个结点
        node.next = list.header.next;
    }
}
