/*
 * Q27.cpp
 *
 *  Created on: 2016年11月1日
 *      Author: jone
 */
#include<iostream>
using namespace std;

int search(int nums[],int x,int numSize,int startIndex);
//可用异或算法
int main(){
	int numSize=0;
	cin>>numSize;
	int *nums=new int[numSize];

	for (int i = 0; i < numSize; i++) {
		cin >> nums[i];
	}

	for (int j = 0; j < numSize; j++) {
		if(nums[j]==search(nums,nums[j],numSize,j+1)){
			cout<<nums[j];
			break;
		}
	}

	delete nums;

}
int search(int nums[],int x,int numSize,int startIndex){
	for(int k=startIndex;k<numSize;k++){
		if(nums[k]==x)
			return nums[k];
	}
	return 0;
}



