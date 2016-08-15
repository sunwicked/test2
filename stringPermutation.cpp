#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

void permuteUtil(string &str,int arr[],string &out,int level,int len ){
	if(level==len){
		std::cout<<out<<"\n";
		return ;
	}
	for(int i =0;i<str.length();++i){
		if (arr[i]==0) continue;
		out=out+str[i];
		arr[i]--;
	//	std::cout<<str<<std::endl;
		permuteUtil(str,arr,out,level+1,len);
		out.erase(out.end()-1);
		arr[i]++;
	}
}
void permute(string str){
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
	permuteUtil(s,arr,out,0,str.length());
}

int main(){
	string str = "ABC";
	permute(str);
}