//============================================================================
// Name        : Q32.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int listLength=0;
class ListNode {
	public:
		int key;
		ListNode *next;
		ListNode(int x) : key(x), next(NULL) {}
};

ListNode *createList(){
	//声明链表头指针，当前指针，数值
	ListNode *header = new ListNode(0);
	ListNode *currentNode=header;
	int op=0;
	cin >> op;
	while(op != -1){
		ListNode *newNode = new ListNode(op);
		currentNode->next = newNode;
		currentNode = newNode;
		listLength++;
		cin >> op;
	}

	return header;
}

void rotateList(ListNode *&header,int k){
	if(!header->next){
				return;
			}
	int rotateIndex = listLength - (k%listLength);
	if(rotateIndex == listLength){
		//不必翻转
		return;
	}else{
		//临时第一个结点
		ListNode *tempFirstNode = header->next;
		//当前结点
		ListNode *currentNode = header->next;
		//尾结点
		ListNode *tailNode;
		//记录前进个数
		int i = 1;
		while(currentNode){
			if(i == rotateIndex){
				header->next = currentNode->next;
				currentNode->next = NULL;
				currentNode = header->next;
			}else{
				if(i == listLength){
					tailNode = currentNode;
				}
				currentNode = currentNode->next;
			}
			i++;
		}
		tailNode->next = tempFirstNode;
	}
}

void deleteNodes(ListNode *&header,int key){
	if(!header->next){
			return;
		}
	//当前结点
	ListNode *currentNode = header->next;
	//删除结点的前一个结点
	ListNode *beforeNode = header;

	while(currentNode){
		if(currentNode->key == key){
			//删除
			beforeNode->next = currentNode->next;
			listLength--;
		}else{
			beforeNode = beforeNode->next;
		}
		currentNode = currentNode->next;
	}
}

void addNode(ListNode *&header,int key,int k){
	if(!header->next){
			return;
		}
	//新建结点
	ListNode *newNode = new ListNode(key);
	//当前指针
	ListNode *currentNode = header->next;
	if(k>=listLength){
		//直接插在最后面
		int i=1;
		while(i<listLength){
			currentNode = currentNode->next;
			i++;
		}
		currentNode->next=newNode;
	}else{
		if(k == 0){
			header->next = newNode;
			newNode->next = currentNode;
		}else{
			int i=1;
			while(i<k){
				currentNode = currentNode->next;
				i++;
			}
			//临时结点
			ListNode *tempNode = currentNode->next;
			currentNode->next=newNode;
			newNode->next=tempNode;
		}
	}
	listLength++;
}

void printAllNodes(ListNode *&header){
	if(!header->next){
			return;
		}
	//当前指针
	ListNode *currentNode = header->next;
	//是否是第一个输出的数值
	bool isFirst = true;

	while(currentNode){
		if(isFirst){
			cout << currentNode->key;
			currentNode = currentNode->next;
			isFirst = false;
		}else{
			cout << " " << currentNode->key;
			currentNode = currentNode->next;
		}
	}
	cout << endl;
}

void runOperations(int opTimes,ListNode *&header){
	//选择操作类型
	for(int i = 0;i < opTimes;i++){
		//操作类型
		int type=0;
		cin >> type;

		//选择
		switch(type){
			case 0 :
				//遍历打印链表
				printAllNodes(header);
				break;
			case 1 :
				//插入结点的值
				int key;
				//插入的位置
				int index;
				cin >> key;
				cin >> index;
				//插入链表结点
				addNode(header,key,index);
				break;
			case 2 :
				//删除结点的值
				int value;
				cin >> value;
				//删除链表结点
				deleteNodes(header,value);
				break;
			case 3 :
				//旋转位数
				int k;
				cin >> k;
				//旋转链表
				rotateList(header,k);
				break;
			default :
				break;
		}
	}
}

int main() {
	int opTimes=0;

	//创建链表
	ListNode *header = createList();
	//输入操作次数
	cin >> opTimes;
	//进行操作
	runOperations(opTimes,header);

	return 0;
}
