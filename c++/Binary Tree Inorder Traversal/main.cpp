//============================================================================
// Name        : Q29.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <string.h>
#include <strstream>
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

/*
 * 非递归中序
 * */
void InorderPrint(BTreeNode* root){
	stack<BTreeNode*> tempStack;
	BTreeNode* currentNode=root;//临时节点
	bool isFirst=true;

	while(true){
		while(currentNode!=NULL){//左子树深度压栈
			tempStack.push(currentNode);
			currentNode=currentNode->left;
		}
		if(!tempStack.empty()){
			currentNode=tempStack.top();
			tempStack.pop();
			if(isFirst){
				cout<<currentNode->key;
				isFirst=false;
			}else{
				cout<<" "<<currentNode->key;
			}
			currentNode=currentNode->right;//进入右子树
		}else{
			cout<<endl;
			return;
		}
	}
}

/**
 * 打印高度
 * */
int treeHight(BTreeNode* root){
	if(!root) return 0;
	int hl=treeHight(root->left);//左侧高度
	int hr=treeHight(root->right);//右侧高度
	if(hl>hr)return ++hl;
	else return ++hr;
}

int main() {
	string str;
	cin>>str;
	BTreeNode *BTree;
	createBTree(BTree,str,str.length());//生成二叉树
	InorderPrint(BTree);//中序打印
	cout<<treeHight(BTree);//打印高度
	return 0;
}
