#include<iostream>
#include<vector>
using namespace std;
void f(string str,string &s,int index,int k,vector<bool> &v,vector<string> &result){
	/*if(s.length()==k) {//if we want to generate all possible permuataion of length k; 
		//result.push_back(s);
		return;
	}*/
	
	for(int i=index;i<str.length();++i){// if i = index then it will generate all possible combination where ba=ab
		if(v[i]==1) continue;
		s=s+str[i];
		v[i]=1;
		result.push_back(s); //this will generate all the possible combination from length 1 to N
		f(str,s,i,k,v,result);
		v[i]=0;
		
		s.pop_back();
		
	}
}

void generateAllPermutation(string str,int k){
	vector<bool> v(str.length(),0);
	vector<string> res;
	string s="";
	f(str,s,0,k,v,res);
	for(auto p: res) std::cout<<p<<"  ";
	std::cout<<std::endl<<res.size();
}

int main(){
	string str="ABCDE";
	generateAllPermutation(str,2);
}