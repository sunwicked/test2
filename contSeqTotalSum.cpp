//Given a sequence of positive integers 'seq' and an integer 'total', return whether a contiguous sequence of 'seq' sums up to 'total'.
#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> arr = {10,20,11,5,4,20,6,8};
	int sum = 0;
	int j = 0;
	int t = 29;
	int i = 0;
	std::cin>>t;
	bool flag = false;
	while(true){

		if(sum == t){
			flag = true;
			std::cout<<"FOUND";
			break;
		}
		else if(i<arr.size() && sum<t){
			sum += arr[i];
			i++;
		}
		else if(j<=i && sum>t){
			sum -=arr[j];
			j++;
		}
		else break;
		std::cout<<sum<<endl;
	}
	if(flag) std::cout<<"FOUND\n";
	else std::cout<<"NOT FOUND\n";
}