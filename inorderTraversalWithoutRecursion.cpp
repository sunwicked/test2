#include<iostream>
#include<list>

struct node{
	int data;
	node * lc=NULL;
	node * rc=NULL;
};
/*
                  1
					  / \
					 /   \
					2     3
			     / \   / \
				 4   5 6   7

*/
void inorderTraver2(struct node *root){
	std::list<node *>vertex;
	node *current =root;
	bool done=false;
	while(!done){
		if(current!=NULL){
			vertex.push_back(current);
			current=current->lc;
		}
		else{
			if(vertex.size()!=0){
				current=vertex.back();
				std::cout<<current->data<<"->";
				vertex.pop_back();
				current=current->rc;
			}
			else done=1;
		}
	}
}


void inorderTraversal(struct node *root){
	std::list<node *> vertex;
	node *current =root;
	node *parent =current;
	while(current!=NULL){
		while(current!=NULL){
	    	vertex.push_back(current);
		   parent=current;
		   current=current->lc;
		}
		current=parent;
		while(current->rc==NULL && vertex.size()!=0){
		  parent=vertex.back();
		  std::cout<<parent->data<<" -> ";
		  vertex.pop_back();
		  current=vertex.back();
		}
		if(vertex.size()!=0){
			std::cout<<current->data<<" -> ";
		   vertex.pop_back();
		}
		current=current->rc;
		while(current!=NULL && current->lc==NULL &&  vertex.size()==0 ){
		   std::cout<<current->data<<" ->";
			current=current->rc;
		}
	}
}

int main(){
	node *A=new node;
	node *B=new node;
	node *C=new node;
	node *D=new node;
	node *E=new node;
	node *F=new node;
	node *G=new node;
	node *H=new node;
	A->data=5;
	B->data=3;
	C->data=7;
	D->data=2;
	E->data=4;
	F->data=6;
	G->data=8;
	H->data=1;
	A->lc=B;
	A->rc=C;
	B->lc=D;
	B->rc=E;
	D->lc=H;
	C->lc=F;
	C->rc=G;
	inorderTraversal(A);
	inorderTraver2(A);
}
