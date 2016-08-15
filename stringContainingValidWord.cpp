#include<iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;
void findWord(set<string> &dict,vector<string> &words,  string str, int si, int part,int len){
   if(str.length()==0) return;
   if(part==len+1) return;
   string str2=str.substr(si,part-si);
   if(dict.count(str2)){
      words.push_back(str2);
      if(part==len) { 
         for(auto p:words) std::cout<<p<<"  ";     
         std::cout<<std::endl;  
      }
      else{
         findWord(dict,words,str,part,part+1,len);
      }
      words.pop_back(); 
   }
   findWord(dict,words,str,si,part+1,len);   
}
  
int main(){
  std::set<std::string> dict;
  std::vector<std::string> sentences;
  dict.insert("a");
  dict.insert("b");
  dict.insert("c");
  dict.insert("bc");
  dict.insert("ab");
  dict.insert("abc");
  dict.insert("be");
  dict.insert("bed");
  dict.insert("bedb");
  dict.insert("bedba");
  dict.insert("bedbat");
  dict.insert("bedbath");
  dict.insert("bedbatha");
  dict.insert("bedbathan");
  dict.insert("bedbathand");
  
  dict.insert("bat");
  dict.insert("bath");
  dict.insert("hand");
  dict.insert("and");
  dict.insert("beyond");
  std::string str("bedbathandbeyond");
  int count=0;
 //std::string str("abc");
  int len=str.length();
  findWord(dict,sentences, str,0,1,len) ;
  std::cout<<endl<<count;
  return 0;
  }
