#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;
void exch(string& str,int& i, int &j){
	char c= str[i];
	str[i]=str[j];
	str[j]=c;
}
///-----------FIND ALL PERMUTATION IN SORTED ORDER----------------------->
//Input ----------> AABC
//OUTPUt ----------> AABC AACB ABAC ABCA ACAB ACBA BAAC BACA BCAA CAAB CABA CBAA
void lexiHelper(string& str, vector<string> &res, map<char,int> &count, string &s){
   //res.push_back(s);-------- this line will include combination of all length
	if(s.length() == str.length()){
		res.push_back(s);
	return;
	}
	for( auto &p:count){
		if(p.second>0){
			s = s+p.first;
			p.second--;
			lexiHelper(str,res,count,s);
			p.second++;
			s.pop_back();
		}
	}
}

void findAllPermLexiOrder(vector<string> &res, string str){
	
	map<char,int> charMap;
	for(int i = 0;i<str.length();++i){
		charMap[str[i]]++;
	}
	string s = "";
	lexiHelper(str,res,charMap,s);
	//return res;
}
// ---------> FIND ALL COMBINATION IN SORTED ORDER-----------------------
void combHelper(vector<string> & res,string &str,vector<char> &s,vector<int> &count, string &st, int index){
	res.push_back(st);
	for(int i = index;i<str.size();++i){
		if(count[i]>0){
			count[i]--;
			st = st + s[i];
			if(count[i]>0)combHelper(res,str,s,count,st,index+1);
			else combHelper(res,str,s,count,st,index);
			count[i]++;
			st.pop_back();
		}
	}
}
void findAllComb(vector<string> &res, string str){
	
	map<char,int> charMap;
	for(int i = 0;i<str.length();++i){
		charMap[str[i]]++;
	}
	vector<char> s;
	vector<int> count;
	s.reserve(charMap.size());
	count.reserve(charMap.size());
	
	for(auto &p: charMap){
		s.push_back(p.first);
		count.push_back(p.second);
	}
	
	string st = "";
	combHelper(res,str,s,count,st,0);
	//return res;
}

/// -- FIND ALL PERMUTATION--------------------
void findAllPerm(vector<string> & res,string &str,int ind, int len){
	if(ind==len-1){
		
		res.push_back(str);
		return;
	}
	//std::cout<<str<<endl;      
	for(int i = ind;i<len;++i){
		exch(str, i,ind);
		findAllPerm(res,str,ind+1,len);
		exch(str,i,ind);
	}
}

int main(){
	string str = "ABCA";
	vector<string> res;
	//findAllPerm(res,str,0,str.size());
	//findAllPermLexiOrder(res,str);
	findAllComb(res,str);
	for(auto p : res) cout<<p<<" ";
}