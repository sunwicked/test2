#include<iostream>
#include<list>
#include<vector>
class Node{
	public:
	Node *lc=NULL;
	Node *rc=NULL;
	int data;
	Node(int val){
		data=val;
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
void levelOrderTraversal(Node *root){
	std::list<Node *> queue;
	if(root==NULL) return;
	queue.push_back(root);
	while(queue.size()!=0){
		if(root->lc!=NULL) queue.push_back(root->lc);
		if(root->rc!=NULL) queue.push_back(root->rc);
		int temp=queue.front()->data;
		queue.pop_front();
		std::cout<<temp<<" ";
		root=queue.front();
	}
}

void printLevelOrderTraversal(Node *root){
	std::list<Node *> queue;
	//Node *dummy=new Node(0);
	if(root==NULL) return;
	Node *dummy =new Node(0);
	queue.push_back(root);
	queue.push_back(dummy);
	int count = 0;
	std::cout<<"\n level "<<count++<<" : ";
	while(queue.size()!=1){
		if(root== dummy){
		  std::cout<<" \n level "<<count++<<" : ";
		  queue.pop_front();
		  queue.push_back(dummy);
		  root=queue.front();
		}
		else{
		  if(root->lc!=NULL) queue.push_back(root->lc);
		  if(root->rc!=NULL) queue.push_back(root->rc);
		  int temp=queue.front()->data;
		  queue.pop_front();
		  std::cout<<temp<<" ";
		  root=queue.front();
		}
	}
}
void printlevelOrderTraversal(Node *root){
	std::vector<Node *> queue;
	if(root==NULL) return;
	Node *temp=new Node(0);
	queue.push_back(root);
	queue.push_back(temp);
	int n=0;
	int count=1;
	while(queue.size()!=1){
		if(root == temp){
			if (count>10) return;
			std::cout<<"\n level  "<<count++<<" : ";
			queue.push_back(temp);
			root=queue[++n];
		}
		else{
			if(root->lc!=NULL) queue.push_back(root->lc);
			if(root->rc!=NULL) queue.push_back(root->rc);
			std::cout<<queue[n]->data<<" ";
			root=queue[++n];
		}
	}
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
	C->lc=E;
	C->rc=F;
	B->rc=D;
	D->rc=G;
	E->rc=H;
   printLevelOrderTraversal(root);
	//levelOrderTraversal(root);
	deleteTree(root);
}
