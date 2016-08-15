#include<iostream>
#include<functional>
#include<unordered_set>
void twoNoSum(int arr[],int len,int k){
	std::unordered_set<int> h_int;
	int count=0;
	//for(int i=0;i<len;i++){
	//h_int.insert(arr[i]);
	//}
	for(int i=0;i<len;i++){
		int temp=k-arr[i];
		if(temp>0 && h_int.count(temp)==1){
		//if(h_int.count(k-arr[i])){
			std::cout<<"elements found "<<k-arr[i]<<" "<<arr[i]<<std::endl;
			count++;
		}
		h_int.insert(arr[i]);
	}
	if(count==0) std::cout<<"elements not found "<<std::endl;
}
int main(){
	int arr[]={2,4,8,9,10,5,11,6,13,18,7,1,23,25};
	int len=sizeof(arr)/sizeof(arr[0]);
	int k;
	char b;
	while(true){
	  std::cout<<"enter no for which numbers to be found : ";
	  std::cin>>k;
	  twoNoSum(arr,len,k);
	  std::cout<<" whether you want to continue ";
	  std::cin>>b;
	  if(b=='n') break;
	}
	return 0;
}

