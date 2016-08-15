#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

void combineUtil(string str,int arr[],string out,int pos ,int level){
	std::cout<<out<<"\n";
	for(int i =pos;i<str.length();++i){
		//std::cout<<"\n value of i : "<<i<<std::endl;
		if (arr[i]==0) continue;
		out=out+str[i];
		arr[i]--;
	//	std::cout<<str<<std::endl;
		combineUtil(str,arr,out,i,level+1);
		out.erase(out.end()-1);
		arr[i]++;
	}
}
void combination(string str){
	map<char,int> countMap;
	for( int i =0; i<str.length();++i){
		countMap[str[i]]++;
	}
	string s="";
	int arr[countMap.size()];
	int i =0;
	for(auto p : countMap){
		s=s+p.first;
		arr[i]=p.second;
		++i;
	}
	string out = "";
	std::cout<<"CALCULATING  "<<s<<std::endl;
	combineUtil(s,arr,out,0,0);
}


int main(){
	string str = "AABC";
	combination(str);
}