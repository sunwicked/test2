#include<string>
#include<vector>
#include<iostream>
#include<map>
using namespace std;
//http://articles.leetcode.com/finding-minimum-window-in-s-which Finding the Minimum Window in S which Contains All Elements from T
string findMinWindow(string str,string pat){
	std::map<char,int> needToFind;
	std::map<char,int> hasFound;
	for(int i = 0 ;i<pat.size();++i)   needToFind[pat[i]]++;
	for(auto p: needToFind) 	hasFound[p.first]=0;
	int minWindowBegin,minWindowLen= INT_MAX ;
	int minWindowEnd;	
	int begin=0,end=0;
	int count =0;
	for(end =0;end<str.length();++end){
		
		if(needToFind.find(str[end])==needToFind.end()) continue;
		hasFound[str[end]]++;
		if(hasFound[str[end]] <= needToFind[str[end]]) count++;
		if(count==pat.size()){
			while(needToFind.find(str[begin])== needToFind.end() || (hasFound.find(str[begin])!=hasFound.end()&&
				hasFound[str[begin]] > needToFind[str[begin]])){
				if(hasFound.find(str[begin])!=hasFound.end() && hasFound[str[begin]]>needToFind[str[begin]])
					hasFound[str[begin]]--;
			}		
			int windowLen = end-begin+1;
			if(windowLen<minWindowLen){
				minWindowBegin=begin;
				minWindowEnd = end;
				minWindowLen = windowLen;
			}
		}
	}
	return str.substr(minWindowBegin,minWindowEnd-minWindowBegin+1);
}

int main(){
	string str ="AADOBECODEBAC";
	string pat= "ABC";
	std::cout<<"The Min Window is : "<<findMinWindow(str,pat)<<std::endl;
	
}
