#include<iostream>
#include<vector>
void printArray(std::vector<int> &vec){
	static int count=0;
	std::cout<<"combintation "<<(++count)<<" is  :  ";
	for(int i=0;i<vec.size();i++)
		std::cout<<vec[i]<<"  ";
	std::cout<<"\n";
}

void getCombination(std::vector<int> & vec,int arr[],int len,int k,int level){
	if(k==0){
		printArray(vec);
		return;
	}
	for(int i=level;i<=len-k;++i){
		vec.push_back(arr[i]);
		getCombination(vec,arr,len,k-1,i+1);
		vec.pop_back();
	}
}

int main(){
	int arr[]={1,2,3,4,5};
	std::vector<int> vec;
	int len=sizeof(arr)/sizeof(arr[0]);
	std::cout<<"len = "<<len<<std::endl;
	int k=3;
	getCombination(vec,arr,len,k,0);
	return 0;
}
