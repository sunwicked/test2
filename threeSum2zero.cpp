#include<iostream>
#include<vector>
#include<algorithm>
void sum2zero(std::vector<int> &vec){
	for(int i=0;i<vec.size();i++){
		int a=vec[i];
		int start=i+1;
		int end=vec.size()-1;
		while(start<end){
			int b=vec[start];
			int c=vec[end];
			if(a+b+c==0){
				std::cout<<a<<"  "<<b<<"  "<<c<<std::endl;
				break;
			}
			else if(a+b+c>0) end--;
			else start++;
		}
	}
}
int main(){
	std::vector<int> vec={2,-4,10,-25,-10,8,-3,-7,4};
	sort(vec.begin(),vec.end());
	sum2zero(vec);
}
