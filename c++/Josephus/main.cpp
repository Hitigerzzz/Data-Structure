//============================================================================
// Name        : Q34.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int nums=0;
	int startIndex=0;
	cin>>nums;
	cin>>startIndex;

	//初始化数组
	int *people=new int[nums];
	for(int i=0;i<nums;i++){
		people[i]=i;
	}

	//删除的位置
	int index=startIndex;
	while(nums>1){
		index=(startIndex+2)%nums;

		//移动数组
		for(int j=index+1;j<nums;j++){
			people[j-1]=people[j];
		}

		nums--;
		if(index==nums){
			index=0;
		}
	}

	cout<<people[index];
	return 0;
}
