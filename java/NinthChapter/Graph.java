package NinthChapter;

import java.util.ArrayList;
import java.util.Stack;

/**
 * Created by Hitiger on 2016/12/22.
 * Description :
 */
public class Graph {

    //图的所有边
    private ArrayList<ArrayList<Integer>> edges = new ArrayList<>();
    //用于存放点的访问状态,未访问默认为-1,已访问则记录其在路径栈中的位置
    private int visited[];
    //利用栈来存放路径
    private Stack pathStack;
    //用来存所有的环
    private ArrayList<ArrayList<Integer>> cycles = new ArrayList<>();

    public static void main(String[] args) {
        //初始化图的大小
        Graph graph1 = new Graph(4);

        //向图添加边
        graph1.addEdge(1, 2);
        graph1.addEdge(2, 3);
        graph1.addEdge(3, 4);
        graph1.addEdge(3, 1);
        graph1.addEdge(4, 1);

        Graph graph2 = new Graph(8);
        graph2.addEdge(1, 2);
        graph2.addEdge(2, 3);
        graph2.addEdge(3, 4);
        graph2.addEdge(4, 5);
        graph2.addEdge(5, 1);
        graph2.addEdge(5, 2);
        graph2.addEdge(5, 7);
        graph2.addEdge(4, 8);
        graph2.addEdge(8, 7);
        graph2.addEdge(7, 6);
        graph2.addEdge(6, 5);

        Graph graph3 = new Graph(3);
        graph3.addEdge(1, 2);
        graph3.addEdge(2, 3);

        //深度优先遍历
        System.out.println("测试用例1：");
        graph1.dfs();
        System.out.println("测试用例2：");
        graph2.dfs();
        System.out.println("测试用例3：");
        graph3.dfs();
    }

    /*
    初始化图的大小
     */
    public Graph(int size) {
        for (int i = 0; i < size; i++)
            edges.add(new ArrayList<>());
    }

    /**
     * 向图添加边
     * @param startVertex 边开始的顶点
     * @param endVertex   边结束的顶点
     */
    private void addEdge(int startVertex, int endVertex){
        edges.get(startVertex - 1).add(endVertex);
    }

    /**
     *深度优先遍历图
     */
    private void dfs() {
        int vertex;

        for(vertex = 0; vertex < edges.size(); vertex++){
            //找到第一个有边的顶点
            if(edges.get(vertex).size() != 0){
                break;
            }
        }

        //初始化访问状态，默认为-1
        visited = new int[edges.size()];
        for(int i = 0; i < edges.size(); i ++) {
            visited[i] = -1;
        }

        //初始化路径栈
        pathStack = new Stack();

        //开始遍历
        visited[vertex] = 0;
        pathStack.push(vertex + 1);
        dfs(vertex, edges.get(vertex));

        if(cycles.size() == 0) System.out.println("NO Cycles!");
        System.out.println("---------------------");
    }

    private void dfs(int vertex, ArrayList<Integer> edgesOfVertex) {
        //遍历邻接表
        for(int eachVertex : edgesOfVertex){
            if(visited[eachVertex - 1] != -1){
                //产生环
                ArrayList<Integer> cycle = new ArrayList<>();
                //将路径上的所有点加入环
                for(int i = visited[eachVertex - 1]; i < pathStack.size(); i++){
                    cycle.add((Integer) pathStack.get(i));
                }
                cycle.add(eachVertex);
                addCycle(cycle);
            }else {
                //由eachVertex继续深度遍历
                pathStack.push(eachVertex);
                visited[eachVertex - 1] = pathStack.size() - 1;
                dfs(eachVertex - 1, edges.get(eachVertex - 1));
            }
        }

        //遍历结束
        visited[vertex] = -1;
        pathStack.pop();
    }

    private void addCycle(ArrayList<Integer> cycle) {
        //判断cycles中是否已存在该cycle，若有则不添加
        for(ArrayList<Integer> each : cycles) {
            if(each.size() == cycle.size()) {
                boolean isSameCycle = true;
                for(int i : each) {
                    if(!cycle.contains(i)) {
                        isSameCycle  = false;
                        break;
                    }
                }
                if(isSameCycle) {
                    //存在该cycle，不添加
                    return;
                }
            }
        }
        cycles.add(cycle);
        //打印环
        printCycle(cycle);
    }

    private void printCycle(ArrayList<Integer> cycle){
        System.out.print("Cycle : ");
        for(int i : cycle) {
            System.out.print(" " + i);
        }
        System.out.println();
    }
}