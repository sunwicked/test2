#include<iostream>
#include<set>
#include<stack>
#include<map>
#include<list>
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
	Node *lc=NULL;
	Node *rc=NULL;
	int data;
	Node(int val){
		data=val;
	}
};
class inorderIterator{
  public:
  Node * current;
  Node *prev;
  int data;
  std::stack<Node *> vertex;
  inorderIterator(Node *root){
    current=root;
  }
  Node *operator ++(int){
    while(current!=NULL){
      vertex.push(current);
      current=current->lc;
    }
    
    if(!vertex.empty()){
      prev=vertex.top();
      vertex.pop();
      current=prev->rc;
      data=prev->data;
      return prev;
    }
    else if(vertex.empty()) return NULL;  
  }  
  
  Node *operator ++(){
    while(current!=NULL){
      vertex.push(current);
      current=current->lc;
    }
    
    if(!vertex.empty()){
      prev=vertex.top();
      vertex.pop();
      current=prev->rc;
      data=prev->data;
      return prev;
    }
    else if(vertex.empty()) return NULL;  
  }  
};


class preorderIterator{
  public:
  int data;
  Node * current;
  Node *prev;
  std::stack<Node *> vertex;
  preorderIterator(Node *root){
    current=root;
    
  }
  
  Node *next(){
    if(current!=NULL){
      prev=current;
      data=prev->data;
      if(current->rc!=NULL) vertex.push(current->rc);
      current=current->lc;
    }
     else if(!vertex.empty()){
      current=vertex.top();
      vertex.pop();
      prev=current;
      data=prev->data;
      if(current->rc!=NULL) vertex.push(current->rc);
      current=current->lc;
    }
    else if(vertex.empty()) return NULL;  
    return prev;
  }  
};

class postorderIterator{
 public:
  std::stack<Node *> stack1;
  std::stack<Node *> stack2;
  Node *current;
  int data;
  postorderIterator(Node * root){
    current=root;   
    stack1.push(current);
    while(!stack1.empty()){
      current = stack1.top();
     // std::cout<<current->data<<"  "; 
      stack2.push(current);
      stack1.pop();
      if(current->lc!=NULL) stack1.push(current->lc);
      if(current->rc!=NULL) stack1.push(current->rc);
    } 
  }
  
  Node *next(){
    if(!stack2.empty()){
      current=stack2.top();
      stack2.pop();
      data=current->data;
      return current;
    }
    else return NULL;
  }
  
};
void preOrderDisplay(Node * root){
	if(root==NULL) return ;
	else {
		std::cout<<root->data<<"  ";
		preOrderDisplay(root->lc);
		preOrderDisplay(root->rc);
	}
}
void postOrderDisplay(Node * root){
	if(root==NULL) return ;
	else {
	  postOrderDisplay(root->lc);
		postOrderDisplay(root->rc);
		std::cout<<root->data<<"  ";
	}
}
void iterativePreOrder(Node *root){
 std::cout<<"\niterative PreOrder : ";
 std::stack<Node *> vertex;
 Node *current=root;
 while(true){
   if(current!=NULL){ 
     std::cout<<current->data<<"  ";
     if(current->rc!=NULL) vertex.push(current->rc);
     current=current->lc;
   }
   else if(!vertex.empty()){
     current=vertex.top();
     vertex.pop();
   }
   else break;
 }
}
 
void inOrderDisplay(Node * root){
	if(root==NULL) return ;
	else {
		inOrderDisplay(root->lc);
		std::cout<<root->data<<"  ";
		inOrderDisplay(root->rc);
	}
}
void deleteTree(Node *root){
	if (root==NULL) return;
	deleteTree(root->lc);
	deleteTree(root->rc);
	delete root;
}
int findPathLength(Node *root,int &sum){
  if(root==NULL) return 0;
  int lh=0;
  int rh=0;
  int len=0;
  lh=1+findPathLength(root->lc,sum);
  rh=1+findPathLength(root->rc,sum);
  len=lh+rh-1;
  sum =sum >len ? sum:len; 
  return lh>rh?lh:rh;
}
void inorderTraversal(Node * root, std::map<Node *,Node *> &parents){
  if(root->lc!=NULL) {
   parents[root->lc]=root;
   inorderTraversal(root->lc,parents);
  }
  if(root->rc!=NULL) {
   parents[root->rc]=root;
   inorderTraversal(root->rc,parents);
 }
   
}
Node * findLCA(Node *root,Node * t1,Node *t2){
  std::map<Node*,Node *> parents;
  inorderTraversal(root,parents);
  for(auto p:parents){
    std::cout<<p.first->data<<"  "<<p.second->data<<std::endl;
  }
  std::list<Node *> path1;
  std::list<Node *> path2;
  Node *current=t1;
  do {
    path1.push_front(current);
    current=parents[current];
  }while(current!=root);
  current=t2;
  
  do {
    path1.push_front(current);
    current=parents[current];
  }while(current!=root);
  Node *prev;
//  for(auto p:path1){
  //  std::cout<<p->data<<"  "<<std::endl;
  //}
  //for(auto p:path2){
    //std::cout<<p->data<<"  "<<std::endl;
  //}
  int count=0;
  while(true){
   std::cout<<"\ncount"<<path1.front()->data<<std::endl;    
   if( path1.front()->data == path2.front()->data ){
     prev=path1.front();
     path1.pop_front();
     path2.pop_front();    
   }    
   else return prev;
  }
}
Node * inorder2circularLinkedList(Node * root){
   Node *current=root;
   Node *prev=NULL;
   Node *head=NULL;
   std::stack<Node *> vertex;
   while(true){
      if(current!=NULL){
        vertex.push(current);
        current=current->lc;
      }
      else if(!vertex.empty()){
        current=vertex.top();
        if(head==NULL) head=current;
        current->lc=prev;
        vertex.pop();
        if(prev!=NULL) prev->rc=current;
        prev=current;
        current=current->rc;
      }
      else break;
   }
   prev->rc=head;
   head->lc=prev;
   return head;
}
void circularLinkListDisplay(Node *head){
  Node *current=head;
  do{
   std::cout<<current->data<<"  ";
   current=current->rc;
  }while(current!=head);
}
int main (){
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
	//A->lc=B;
	C->lc=E;
	C->rc=F;
	B->rc=D;
	D->rc=G;
	E->rc=H;
	inOrderDisplay(root);
	//inorderIterator itr(root);
	//std::cout<<"\n";
	//int count=0;
//	while(++itr !=NULL){
	//  std::cout<<itr.data<<"  ";
	//}
	//iterativePreOrder(root);
	//preOrderDisplay(root);
	//std::cout<<"\n";
	//preorderIterator pitr(root);
	std::cout<<"\n";
//	while(pitr.next()!=NULL){
//	 std::cout<<pitr.data<<" ";
//	}
  //postOrderDisplay(root);
//	std::cout<<"\n";
	//postorderIterator poitr(root);
	//std::cout<<"\n";
	//while(poitr.next()!=NULL){
	 //std::cout<<poitr.data<<" ";
	//}
	//int sum=0;
	//findPathLength(root,sum);
	
	//std::cout<<"\n max path length is : "<<sum<<std::endl;
	//std::cout<<"before main"<<std::endl;
	//std::cout<<findLCA(root,E,H)->data<<std::endl;;
	//std::cout<<"after main"<<std::endl;
	Node * head=inorder2circularLinkedList(root);
	circularLinkListDisplay(head);
//	deleteTree(root);
}
