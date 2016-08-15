#include<iostream>
#include<queue>
#include<utility>
#include<list>
#include<map>
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

void vertTraversal(Node *root){
   std::queue<Node *> nod;
   Node * current=root;
   bool done =false;
   while(true){
      while(current!=NULL){
         nod.push(current);
         current=current->lc;
      }
      if(nod.empty()) break;
      Node *top=nod.front();
      std::cout<<top->data<<"  ";
      nod.pop();
      current=top->rc;
   }
  std::cout<<"\n"; 
}
using nodePair= std::pair<Node*,int>;
void printVerticalMap(std::map<int,std::list<Node*>> &disNode){
   for(auto p :disNode){
     for (auto x: p.second){
       std::cout<<x->data<<"  ";
    }
  }  
}
void debugverticalTraversal(Node *root){
   std::queue<nodePair> nod;
   std::map<int,std::list<Node *>> disNode;
   Node * currentNode=root;
   int h=0;
   int count=0;
   while(true){
      while(currentNode!=NULL){
         nodePair current=std::make_pair(currentNode,h);
         nod.push(current);
         currentNode=currentNode->lc;
         h=h-1;
      }
      if(nod.empty()) break;
      nodePair  top=nod.front();
      disNode[top.second].push_back(top.first);
     // std::cout<<top.first->data<<"  ";
      //std::cout<<top.second<<std::endl;
      nod.pop();
      currentNode=top.first->rc;
      
      h=top.second+1;
   }
   printVerticalMap(disNode);

}
///------THIS IS CORRECT ONE------------------------------>
void verticalTraversal(Node *root){
   std::queue<nodePair> nod;
   std::map<int,std::list<Node *>> disNode;
   Node * currentNode=root;
   int h=0;
   while(true){
      while(currentNode!=NULL){
         nodePair current=std::make_pair(currentNode,h);
         nod.push(current);
         currentNode=currentNode->lc;
         h=h-1;
      }
      if(nod.empty()) break;
      nodePair  top=nod.front();
      disNode[top.second].push_back(top.first);
      nod.pop();
      currentNode=top.first->rc;
      h=top.second+1;
   }
   printVerticalMap(disNode);
}  
void preOrderDisplay(Node * root){
	if(root==NULL) return ;
	else {
		std::cout<<root->data<<"  ";
		preOrderDisplay(root->lc);
		preOrderDisplay(root->rc);
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
int main (){
	/*Node *root=new Node(2); 
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
	E->lc=H;*/
	Node *root=new Node(6); 
	Node *A =new Node (3);
	Node *B =new Node (4);
	Node *C =new Node (5);
	Node *D =new Node (1);
	Node *E =new Node (0);
	Node *F =new Node (9);
	Node *G=new Node (2);
	Node *H=new Node (8);
	Node *I=new Node (7);
	root->lc=A;
	root->rc=B;
	A->lc=C;
	A->rc=D;
	B->rc=E;
	C->lc=F;
	C->rc=G;
	G->rc=I;
	E->lc=H;

	//preOrderDisplay(A);
	vertTraversal(root);
	deleteTree(root);
}
