////============================================================================
//// Name        : Q28.cpp
//// Author      :
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================

#include <iostream>
#include <sstream>
#include <string.h>
//#include <strstream>
#include <stack>
using namespace std;

class BTreeNode{
	public:
		int key;
        BTreeNode *left;
        BTreeNode *right;
};

//生成二叉树，数据结构ppt
void createBTree(BTreeNode*&BT,string str,int length){
	BTreeNode *s[10000];
	int top=-1;
	BT=NULL;
	BTreeNode *p;
	int k=0;//记录左右节点 1 左节点 2右节点
	stringstream stream;
	int i=0;

	while(i<length){
		switch(str[i]){
			case '(':
				top++;
				s[top]=p;
				k=1;
				break;
			case ')':
				top--;
				break;
			case ',':
				k=2;
				break;
			default:
				p=new BTreeNode;
				string buffer="";
				buffer+=str[i];
				while(str[i+1]>='0'&&str[i+1]<='9'){//读到一个数字，往后遍历是否是数字
					buffer+=str[i+1];
					i++;
				}
				stream<<buffer;
				int temp=0;
				stream>>temp;//将字符串转化成int
				stream.clear();
				p->key=temp;p->left=p->right=NULL;
				if(BT==NULL)BT=p;
				else{
					if(k==1){
						s[top]->left=p;
					}else{
						s[top]->right=p;
					}
				}
		}
		i++;
	}
}
//递归会爆掉
//int isBSTUtil(BTreeNode* node,int min,int max){
//	if(node==NULL) return 1;
//	// 如果不满足min和max约束，返回false
//	if (node->key<min || node->key>max) return 0;
//	// 递归判断左右子树是否满足min和max约束条件
//	return isBSTUtil(node->left, min, node->key)&&isBSTUtil(node->right, node->key, max);
//}
//int isBST(BTreeNode* node){
//	return isBSTUtil(node, -1,node->key);
//}

//非递归,判断是否是二叉搜索树
int isBST2(BTreeNode* root){
	stack<BTreeNode*> tempStack;//栈好像不限大小
	BTreeNode* tempNode=root;//临时节点
	int minVal=-1;//初始化一个最小值;
	if(root==NULL){
		return 1;
	}else{
		while(tempNode||!tempStack.empty()){
		    while(tempNode){//左树全部入栈，深度优先
		          tempStack.push(tempNode);
		          tempNode=tempNode->left;
		     }
		    if(!tempStack.empty()){
		        if (minVal>tempStack.top()->key){//右侧节点小于左侧节点
		                    return 0;
		        }
		        minVal=tempStack.top()->key;
		        tempNode=tempStack.top()->right;
		        tempStack.pop();//出栈;
		     }
		}
		return 1;
	}
}

int main() {
	string str;
	cin>>str;
	BTreeNode *BTree;
	createBTree(BTree,str,str.length());//生成二叉树
	cout<<isBST2(BTree);
	return 0;
}
