#include "sort.h"

void sortColors(int* nums, int numSize) {
	int temp=0;

	for(int i=0;i<numSize-1;i++){
		for(int j=0;j<numSize-1-i;j++){
			if(nums[j]>nums[j+1]){
				temp=nums[j];
				nums[j]=nums[j+1];
				nums[j+1]=temp;
			}
		}
	}
}
