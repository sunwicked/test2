#include<iostream>
#include<cstring>
#include<set>
void swap(std::string &word, int a,int b){
	char temp=word[a];
	word[a]=word[b];
	word[b]=temp;
}

void anagramSet(std::string word, int l, int r, std::set<std::string> &anagrams){
	if (l==r){
		std::cout<<word<<std::endl;
		anagrams.insert(word);}
	else {
		for (int i=l;i<=r;i++){
			swap(word,l,i);
			anagramSet(word,l+1,r,anagrams);
			swap(word,l,i);
		}
	}
}

int main(){
	std::set<std::string> anagrams;
	std::string word="AABB";
	std::cout<<"following are the anagrams of the word : "<<std::endl;
	int len = word.length();
	for(int i=0;i<len;i++){
	anagramSet(word,0,i,anagrams);
	}
	std::set<std::string>::iterator it;
	std::cout<<"following are the contents of cset "<<std::endl;
	for(it=anagrams.begin();it!=anagrams.end();it++)
		std::cout<<*it<<std::endl;
}
