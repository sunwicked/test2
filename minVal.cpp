#include<iostream>
class Node{
  public:
  Node *lc=NULL;
  Node *rc=NULL;
  int val;
  Node(int x):val(x){}
};

Node * findMinNode(Node *root,int val){
   Node* current=root;
   Node *parent=root;
   Node *minNode= NULL;
   while(current!=NULL){
   
      if(current->val<val) minNode=current;
            
      if(val==current->val){
         return current;
      }
      
      else if(val>current->val){
         current=current->rc;
      }
      
      else{
         current=current->lc;
      }
   }
   return minNode;
}

int findNode(Node *root,int val){
   Node *current=root;
   Node *x=findMinNode(current,val);
   if(x!=NULL) return x->val;
   else return -1;
   
}

int main(){
  Node *root=new Node(30);
  Node *A=new Node(20);
  Node *B=new Node(50);
  Node *C=new Node(40);
  Node *D=new Node(35);
  B->lc=C;
  C->lc=D;
  root->lc=A;
  root->rc=B;
  for(int i=10 ;i<55;i++)
  std::cout<<i<<" : "<<findNode(root,i)<<std::endl;  
  return 0;  
}
