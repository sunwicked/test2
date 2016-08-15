#include<iostream>
#include<list>
struct node{
	int data;
	node * lc=NULL;
	node * rc=NULL;
};
void printLeafPath(struct node * root,std::list<node *>& path){
	if(root->lc==NULL && root->rc==NULL){
		for(auto p: path)
			std::cout<<p->data<<"->";
		std::cout<<"\n";
	}
	else {
		if(root->lc!=NULL){
			path.push_back(root->lc);
			printLeafPath(root->lc,path);
			path.pop_back();
		}
		if(root->rc!=NULL){
			path.push_back(root->rc);
			printLeafPath(root->rc,path);
			path.pop_back();
		}
	}
}
/*
void printLeafPath(struct node * root,std::list<node *>& path){
	if(root->lc==NULL && root->rc==NULL){
		for(auto p: path)
			std::cout<<p->data<<"->";
		std::cout<<"\n";
	}
	else {
		if(root->lc!=NULL){
			path.push_back(root->lc);
			printLeafPath(root->lc,path);
			path.pop_back();
		}
		if(root->rc!=NULL){
			path.push_back(root->rc);
			printLeafPath(root->rc,path);
			path.pop_back();
		}
	}
}*/
void path2leaf(struct node * root){
	std::list<node *> path;
	path.push_back(root);
	printLeafPath(root,path);
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
	path2leaf(A);
}

