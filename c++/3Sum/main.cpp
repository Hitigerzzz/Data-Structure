//============================================================================
// Name        : Q25.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
void printResult(int a,int b,int c);
bool isFirst=false;//第一个正确答案，解决换行问题
bool isPrint=false;
int d;
int e;

int main() {
	int n;
	int i=0;
	cin >> n;
	int nums[n];
	while(i<n){
		cin>>nums[i];
		i++;
	}

	fstream out("test.txt",ios::app);
	out<<"数量"<<n<<endl;
	for(int i=0;i<n;i++){
		out<<nums[i]<<" ";
	}
	out<<endl;

	if(nums[0]<=nums[n-1]){//从小到大
		for(int i=0;i<n-2;i++){
			for(int j=i+1;j<n;j++){
				int temp=nums[i]+nums[j];
				if(temp>0){//前两项之和大于0，直接退出for循环
					break;
				}else{//遍历寻找剩下部分是否满足和为0
					for(int k=j+1;k<n;k++){
						if(nums[k]+temp==0){//三个数满足要求，输出
							printResult(nums[i],nums[j],nums[k]);
						}
					}
				}
			}
		}
	}else{//从大到小
		for(int i=0;i<n-2;i++){
			for(int j=i+1;j<n;j++){
				int temp=nums[i]+nums[j];
				if(temp<0){//前两项之和小于0，直接退出for循环
					break;
				}else{//遍历寻找剩下部分是否满足和为0
					for(int k=j+1;k<n;k++){
						if(nums[k]+temp==0){//三个数满足要求，输出
							printResult(nums[i],nums[j],nums[k]);
						}
					}
				}
			}
		}
	}


	return 0;
}


void printResult(int a,int b,int c){


	if(!isFirst){
		cout<<a<<" "<<b<<" "<<c;
		d=a;
		e=b;
		isFirst=true;
	}else{
		if(a==d&&b==e)return;
		d=a;
		e=b;
		cout<<endl;
		cout<<a<<" "<<b<<" "<<c;
	}
}
