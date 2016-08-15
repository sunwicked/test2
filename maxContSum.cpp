#include<iostream>
int maxContSum(int arr[],int n){
	int maxSum=arr[0];
	int maxContSumUptilHere=arr[0];
	for(int i=1;i<n;i++){
		maxContSumUptilHere=maxContSumUptilHere + arr[i];
		if(arr[i]>maxContSumUptilHere)
		 maxContSumUptilHere = arr[i];
		if(maxContSumUptilHere > maxSum)
			maxSum = maxContSumUptilHere;
	}
	return maxSum;
}
int main(){
	int arr[]={1,2,4,-1,5,1,2,-3,1,-1};
	int num = sizeof(arr)/sizeof(arr[0]);
	std::cout<<"max sum is "<<maxContSum(arr,num);
	return 0;
}
