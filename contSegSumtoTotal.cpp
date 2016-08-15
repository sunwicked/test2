#include<iostream>
bool sumResults(int ar[],int len, int t){
	int sum=0;
	int k=0;
	for(int i=0;i<len;i++){
		sum=sum+ar[i];
		if(sum==t){
		  std::cout<<"\n starting index is : "<<k<<std::endl;
		 return true;
		 }
		else if(sum>t){
			while(sum>t){
				sum=sum-ar[k++];
			}
		if(sum==t){
		  std::cout<<"\n starting index is : "<<k<<std::endl;
		return true;
		 }
		}
	}
	return false;
}



int main(){
	int arr[]={2,3,11,8,10,5,6,10,11};
	int t;
  std::cin>>t;
	int l=sizeof(arr)/sizeof(arr[0]);
	if(sumResults(arr,l,t)) std::cout<<"cont seq is there"<<std::endl;
	else std::cout<<"no such sequence" <<std::endl;
}
