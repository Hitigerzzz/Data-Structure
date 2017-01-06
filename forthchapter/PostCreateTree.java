package forthchapter;

import java.util.Stack;

/**
 * Created by Hitiger on 2016/11/17.
 * Description :
 */
public class PostCreateTree {

    public static void main(String[] args) {
        PostCreateTree postCreateTree = new PostCreateTree();
        String postStr = "ab+c*";
        TreeNode root = postCreateTree.createTree(postStr);
        System.out.println("先序：");
        postCreateTree.printPre(root);
        System.out.println();
        System.out.println("中序：");
        postCreateTree.printIn(root);
        System.out.println();
        System.out.println("后序：");
        postCreateTree.printPost(root);
    }

    private void printPost(TreeNode root) {
        if(root != null) {
            printPost(root.left);
            printPost(root.right);
            System.out.print(root.value);
        }
    }

    private void printIn(TreeNode root) {
        if(root != null) {
            printIn(root.left);
            System.out.print(root.value);
            printIn(root.right);
        }
    }

    private void printPre(TreeNode root) {
        if(root != null) {
            System.out.print(root.value);
            printPre(root.left);
            printPre(root.right);
        }
    }

    private TreeNode createTree(String postStr) {

        Stack <TreeNode> treeStack = new Stack<>();

        for (int i = 0; i < postStr.length(); i++) {

            char c = postStr.charAt(i);
            TreeNode op = new TreeNode(c);
            switch (c) {
                case '+' :
                case '-' :
                case '*' :
                case '/' :
                    op.right = treeStack.pop();
                    op.left = treeStack.pop();
                    treeStack.push(op);
                    break;
                default :
                    treeStack.push(op);
            }
        }

        return treeStack.pop();
    }


    public class TreeNode {
        char value;
        TreeNode left;
        TreeNode right;

		public TreeNode (char c) {
            value = c;
        }
    }

}
