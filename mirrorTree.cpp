#include<iostream>

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
void exch(Node *root){
	Node *temp=root->lc;
	root->lc=root->rc;
	root->rc=temp;
}
void mirrorBinaryTree(Node * root){
	if(root==NULL)
		return ;
	mirrorBinaryTree(root->lc);
	mirrorBinaryTree(root->rc);
	exch(root);
}
void deleteTree(Node *root){
	if (root==NULL) return;
	deleteTree(root->lc);
	deleteTree(root->rc);
	delete root;
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
	preOrderDisplay(root);
	mirrorBinaryTree(root);
	preOrderDisplay(root);
	deleteTree(root);
}
