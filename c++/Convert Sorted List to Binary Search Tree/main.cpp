//============================================================================
// Name        : Q31.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

class ListNode{
	public:
		int key;
	    ListNode *next;
};

class BTreeNode{
	public:
		int key;
        BTreeNode *left;
        BTreeNode *right;
};

BTreeNode *sortedListToBST(ListNode *&list,int start,int end){
	if(start>end)	return NULL;
	int mid=start+(end-start+1)/2;
	BTreeNode *leftChild=sortedListToBST(list,start,mid-1);
	BTreeNode *parent=new BTreeNode();
	parent->key=list->key;
	parent->left=leftChild;
	list=list->next;
	parent->right=sortedListToBST(list,mid+1,end);

	return parent;
}
BTreeNode* sortedListToBST(ListNode *head, int n) {
	return sortedListToBST(head, 0, n-1);
}

void printLeafFromLeftToRight(BTreeNode *root){
	static stack<BTreeNode *> tempStack;
	BTreeNode* currentNode=root;//临时节点
	bool isFirst=true;

	if(root==NULL){
		return;
	}else{
		while(currentNode||!tempStack.empty()){
			while(currentNode){
				////左子树结点全部入栈，深度优先
				tempStack.push(currentNode);
				currentNode=currentNode->left;
			}
			if(!tempStack.empty()){
				currentNode=tempStack.top();
				tempStack.pop();
				if(!currentNode->left&&!currentNode->right){
					if(isFirst){
						//输出第一个结果
						cout<<currentNode->key;
						isFirst=false;
					}else{
						cout<<" "<<currentNode->key;
					}
				}
				currentNode=currentNode->right;//进入右子树
			}else{
				cout<<endl;
				return;
			}
		}
	}
}
int main() {
	ListNode *firstListNode=NULL;
	ListNode *currentListNode=NULL;
	char ch;
	int temp;
	int listLength=0;

	while((ch=getchar())!='\n'){
		if(ch!=' '){
			//读取数字
			cin.putback(ch);
			cin>>temp;

			//创建新结点
			ListNode *node=new ListNode();
			node->key=temp;

			if(firstListNode==NULL){
				firstListNode=node;
				currentListNode=firstListNode;
			}else{
				currentListNode->next=node;
				currentListNode=node;
			}
			//链表长度+1
			listLength++;
		}
	}
	BTreeNode *root=sortedListToBST(firstListNode,listLength);
	printLeafFromLeftToRight(root);

	delete firstListNode;
	delete currentListNode;
	delete root;
	return 0;
}
