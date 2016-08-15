#include<list>
#include<iostream>
using namespace std;
const int SIZE=10;

class Node {
   public:
   int key;
   int value;
   Node(int k, int v): key(k),value(v){}
};  
 
class HashMap{
   private:
   
   std::list<Node *>data[SIZE];
   int hashFn(int k){ return k%13;}
   
   public:
   ~HashMap(){
       std::list<Node *>::iterator itr;
      /* for(int i=0;i<SIZE;++i){
          itr=data[i].begin();
          while(itr!=data[i].end()) {
            delete *itr;
            ++itr;
          }
       }*/
       for(int i=0;i<SIZE;++i){
          for(auto &node : data[i]) delete node;
       }
   }
   Node *get(int k){
      int hash= hashFn(k);
      int pKey= hash%SIZE;
      list<Node *>::iterator itr=data[pKey].begin();
      while(itr!=data[pKey].end()){
         if( (*itr)->key==k) return *itr;
         ++itr;
      }
      
      
      //for(auto& node : data[pKey]){
        // if(node->key==k) return node;
      //}
      return NULL;
   }
   
   void put(int k, int v){
      int hash=hashFn(k);
      int pKey=hash%SIZE;
      Node * A= get(k);
      if(A==NULL){
         data[pKey].push_back( new Node(k,v));
      }
      else A->value=v;
   }
   
};

int main(){
    HashMap map;
    cout << "Finding 5: " << map.get(5) << endl;  // -1
    map.put(5, 10);
    map.put(5, 11);
    cout << "Finding 5: " << map.get(5)->value;  // 11
    return 1;
}
  
