#include<iostream>
#include<list>
#include<stack>
#include<map>
#include<vector>
/*
                2
               /\
              /  \
             /    \
            7      5
             \      \
             6       9
            / \       \
           1   11      4
          /
         3
*/
class Node{
  public:
  Node *lc= NULL;
  Node *rc=NULL;
  int data;
  Node(int val){
  data=val;
  }
};
void deleteTree(Node * root){
  if(root!=NULL){
    deleteTree(root->lc);
    deleteTree(root->rc);
    delete root;
  }
}
void iterativeInorder(Node *root){
  std::cout<<"\n inorder traversal is :";
  std::stack<Node *> vertex;
  Node *current=root;
  while(true){
    if(current!=NULL){
      vertex.push(current);
      current=current->lc;
    }
    else if(!vertex.empty()){
      current= vertex.top();
      std::cout<<current->data<<"  ";
      vertex.pop();
      current=current->rc;
    }
    else break;;
  }     
}
void iterativePostorder(Node *root){
  std::stack<Node *> stack1;
  std::cout<<"\n postorder traversal is :";
  std::stack<Node *> stack2;
  Node *current=root;
  stack1.push(current);
  while(!stack1.empty()){
    current=stack1.top();
    stack2.push(current);
    stack1.pop();
    if(current->lc!=NULL) stack1.push(current->lc);
    if(current->rc!=NULL) stack1.push(current->rc);
  }
  while(!stack2.empty()){
    current=stack2.top();
    stack2.pop();
    std::cout<<current->data<<"  "; 
  }
}
void inorderTraversal(Node *root,Node *target,std::map<Node *, Node*> &parent,bool &found){
  if(root==target){ 
    found=true;
    return;
  }
  if(root->lc!=NULL && !found){
    parent[root->lc]=root;
    inorderTraversal(root->lc,target,parent,found);
  } 
  if(root->rc!=NULL && !found){
    parent[root->rc]=root;
    inorderTraversal(root->rc,target,parent,found);
  }
}
bool findPathUtil(Node *root,Node* target,std::vector<Node *>& path){
  if(root==target){
    path.push_back(root);
    return true;
  }
  path.push_back(root);
  if((root->lc!=NULL && findPathUtil(root->lc,target,path))
  || ((root->rc!=NULL) && findPathUtil(root->rc,target,path))) return true;
  
  path.pop_back();
  return false;
}
void findPath2(Node *root,Node* target){
  std::vector<Node *> path;
  findPathUtil(root,target,path);
  std::cout<<path.size();
  std::cout<<"Path is : ";
  for(auto p: path) std::cout<<p->data<<"  ";
}
void findPath(Node *root,Node* target){
  std::map<Node *,Node*>parentMap;
  parentMap[root]=root;
  bool found=false;
  inorderTraversal(root,target,parentMap,found);
  std::list<Node *>path;
  for(auto p:parentMap){
    std::cout<<p.first->data<<"  "<<p.second->data<<std::endl;
  }
  if(found) {
    std::cout<<"\n path to TARGET found : ";
    Node *current=target;
    do{
      current=parentMap[current];
      path.push_front(current);
    }while(current!=root);
  }
  else {
    std::cout<<"No Path found";
    return;
  }
  for(auto p: path)
    std::cout<<p->data<<"  ";
  
}
void iterativePreorder(Node * root){
  std::cout<<"\n preorder traversal is :";
  std::stack<Node *> vert;
  Node *current=root;
  //vert.push(root);
  while(true){
   if(current!=NULL){
     std::cout<<current->data<<"  "	;
     if(current->rc!=NULL) vert.push(current->rc);
     current=current->lc;
   }
   else if(!vert.empty()){
    current=vert.top();
    vert.pop();
   }
  else break;
 }    
}
void inorder2circularLinkedList(Node * root){
  std::stack<Node *> vertex;
  Node * current =root;
  Node *prev=NULL;
  Node *first =NULL;
  std::cout<<"circular traversal is ";
  while(true){
    if(current!=NULL){
      vertex.push(current);
      current=current->lc;
     
    }
    else if(!vertex.empty()){
      current =vertex.top();
      if(first==NULL) first=current;
      if(prev!=NULL) {
        prev->rc=current;
        current->lc=prev;
       std::cout<<"inside prev is "<<prev->data<<std::endl;
      }
      vertex.pop();
      prev=current;
     
      current=current->rc;
    } 
    else {
   // std::cout<<"prev is "<<prev->data<<std::endl; 
    break;
    }
  }
  std::cout<<"root is "<<root->data<<std::endl;

//  std::cout<<"prev is "<<prev->data<<std::endl; 
  prev->rc=first;
 first->lc=prev;
 current=root;
  do {
    std::cout<<current->data<<"  ";
    current=current->rc;
  }while(current!=root);
  
}
void postOrder(Node *root){
  if(root==NULL) return ;
  postOrder(root->lc);
  postOrder(root->rc);
  std::cout<<root->data<<"  ";
}
void preOrder(Node *root){
  if(root==NULL) return ;
  std::cout<<root->data<<"  ";
  preOrder(root->lc);
  preOrder(root->rc);
}
void inOrder(Node *root){
  if(root==NULL) return ;
  inOrder(root->lc);
  std::cout<<root->data<<"  ";
  inOrder(root->rc);
}
int main(){
  Node *root=new Node(2); 
	Node *A =new Node (7);
	Node *B =new Node (5);
	Node *C =new Node (6);
	Node *D =new Node (9);
	Node *E =new Node (1);
	Node *F =new Node (11);
	Node *G=new Node (4);
	Node *H=new Node (3);
	root->lc=A;
	root->rc=B;
	A->rc=C;
	C->lc=E;
	C->rc=F;
	B->rc=D;
	D->rc=G;
	E->rc=H;
	std::cout<<"\n";
	preOrder(root);
	std::cout<<"\n";
	iterativePreorder(root);
	std::cout<<"\n";
	inOrder(root);
	iterativeInorder(root);
	std::cout<<"\n";
	postOrder(root);
	
	iterativePostorder(root);
	findPath2(root,H);
	findPath(root,H);
	inorder2circularLinkedList(root);
//	deleteTree(root);
}
