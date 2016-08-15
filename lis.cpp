#include<iostream>
#include<vector>
using namespace std;
int longestIncreasingSubsequence(vector<int> & arr){
	vector<int> lis(arr.size(),1);
	int maxSum=1;
	for(int i=1;i<arr.size();++i){
		for(int j=i-1;j>=0;--j){
			if(arr[i]>arr[j]) lis[i] = max(lis[i],1+lis[j]);
		}
		maxSum=max(lis[i],maxSum);
	}
	return maxSum;
}
int main(){
	vector<int> arr={ 10, 22, 9, 33, 21, 50, 41, 60 };
	std::cout<<longestIncreasingSubsequence(arr)<<std::endl;
}