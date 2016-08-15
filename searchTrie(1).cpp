#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
class TrieNode{
   public:
   string word;
   bool isWord;
   unordered_map<char, TrieNode*> next;
   TrieNode():isWord(false){}
};

class Trie{
    TrieNode* root=NULL;
    TrieNode* put(TrieNode *root,string str, int index){
       if(root==NULL) root= new TrieNode;
       if(index==str.length()){
         root->isWord=true;
         root->word= str;
         return root;
       }
       char c = str[index];
       root->next[c] = put(root->next[c], str,index+1);
       return root;
    }
    
    void get(string &str, vector<string> & words, TrieNode * root, int l){
         if(root==NULL) return ;
         if(str.length()==l){
            if(root->isWord) words.push_back(root->word);
            return;
         }
         char c = str[l];
         if(c=='*'){ 
            for(auto p : root->next){
               get(str, words, root->next[p.first],l+1);
            }
         }
         else get(str,words,root->next[c],l+1);
    }
    public:
    
    void put(string str){
       root=put(root,str,0);
    }
    
    void get(string str){
       vector<string> words;
       get(str, words, root,0);
       for(auto p: words){
          std::cout<<p<<"  ";
       }
    }
};
int main(){
  Trie t;
  t.put("peak");
  t.put("park");
  t.put("pick");
  t.put("part");
  t.put("ambt");
  t.put("antt");
  t.get("***k");
}
