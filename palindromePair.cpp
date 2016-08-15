#include<iostream>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<set>
#include<string>
class TrieNode{
  public:
  bool isWord;
  std::string val;
  std::unordered_map<char,TrieNode *> child;
  TrieNode():isWord(false){}
};

class Trie{
  public:
  TrieNode *root=NULL;
  
  TrieNode * put(TrieNode *x,std::string& word,std::string value, int l){
    if(x==NULL) x=new TrieNode;
    if(l==word.length()) {
      x->isWord=true;
      x->val=value;
      return x;
    }
    char c=word[l];
    x->child[c]=put(x->child[c],word,value,l+1);
    return x;
  }
  
  void get(TrieNode *x,std::string & word,int l,std::set<std::string> &words){
    if(x==NULL) return ;
    if(x->isWord) {
     // std::cout<<"VALUE "<< x->val<<std::endl;
      words.insert(x->val);
      }
    if(l==word.length()) return ;
    char c=word[l];
    get(x->child[c],word,l+1,words);
  }
  
  
  std::set<std::string> get(std::string &word){
    std::set<std::string> words;
    get(root,word,0,words);
    //for(auto p: words) std::cout<<p<<" : "; 
    return words;
  }
  void put(std::string &word,std::string value){ root=put(root,word,value,0); }
};
bool checkPalindrome(const std::string& words){
  int len=words.length();
  int l=-1;
  int r=len;
  while(l<r){
   if(words[++l]!=words[--r]) return false;
  }
  return true;
}
std::string reverse(std::string words){
  std::string rev="";
  int i=words.length()-1;
  while(i>=0){
    rev= rev+words[i];
    i--;
  }
  return rev;
}

void findPalindromePair(std::set<std::string> &dict){
  Trie t;
  Trie t1;
  for(auto p:dict){
    t.put(p,p);
    std::string rev=reverse(p);
    t1.put(rev,p);
  }
  for(auto p: dict){
    int len=p.length();
    int rem;
    std::string rev=reverse(p);
    std::set<std::string> setWords=t.get(rev);
    std::set<std::string> setWords2=t1.get(p);
   /* for(auto words :setWords){
      if(words==p) continue;
      rem=len-words.length();      
      if(rem==0 || rem==1) std::cout<< p<<"  "<<words<<std::endl;
      else{
         if(checkPalindrome(rev.substr(words.length())))
          std::cout<<p<<"  "<<words<<std::endl;
      }
      
    }  */ 
    for(auto words :setWords2){
     // if(words==p) continue;
      rem=len-words.length();      
      if(rem==0 || rem==1) std::cout<< p<<"  "<<words<<std::endl;
      else{
         if(checkPalindrome(p.substr(words.length()))) 
          std::cout<<p<<"  "<<words<<std::endl;
      }
      
    } 
  }
  
  
}
int main(){
  std::set<std::string> dict={"raw", "warrener","rotatively","levitator","redrawer","rewarder","none","xenon","ab","cdcba","abc","dcba"};
  findPalindromePair(dict);
   
}
