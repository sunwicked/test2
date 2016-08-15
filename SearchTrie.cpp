#include<iostream>
#include<unordered_map>
#include<string>
#include<set>
class TrieNode{
    public:
    std::string str;
    bool isWord;
    std::unordered_map<char,TrieNode*> next;
    TrieNode() : isWord(false){}
};

class Trie{
    private:
    
    TrieNode *root=NULL;
    
    TrieNode* put(TrieNode* x, std::string& word,int level){
        if(x==NULL) x= new TrieNode;
        if(level==word.size()){
            x->isWord=true;
            x->str = word;
            return x;
        }
        char c= word[level];
        x->next[c] = put(x->next[c],word,level+1);
        return x;
    }
    
    void  get(TrieNode *x, std::string &word, int level,std::set<std::string>& words){
        if(x==NULL) return;
       
        if(level==word.size()){
            std::cout<<"Inside "<<x->str<<std::endl;
            words.insert(x->str);
            return ;
        }    
        char c = word[level];
        if(c =='*') {
            for(auto p : x->next)  get(x->next[p.first], word,level+1,words);
        }
        else get(x->next[c],word,level+1,words);
    }

    
    public :
    

    void put(std::string word){
        root=put(root,word,0);        
    }

    
    void get(std::string word){
        std::set<std::string> words;
        get(root,word,0,words);
        if(words.size()!=0 ) for(auto p : words) std::cout<<p<<std::endl;
        else std::cout<<"NOT FOUND"<<std::endl;
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
  t.get("p**k"); 
}
