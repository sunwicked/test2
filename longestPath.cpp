#include<iostream>
#include<climits>
#include<algorithm>
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
int maxheight(Node *root){
	if(root==NULL) return 0;
	int lmax=maxheight(root->lc)+1;
	int rmax=maxheight(root->rc)+1;
	return std::max(lmax,rmax);
}
int longestPath(Node * root,int & maxLength){
	if(root==NULL) return 0;
	int l =maxheight(root->lc);
	int r=maxheight(root->rc);
	int ldiam=longestPath(root->lc,maxLength);
	int rdiam=longestPath(root->rc,maxLength);
	if(l+r>maxLength) maxLength=l+r;

}

int longestPathBinarytree(Node *root){
	int maxP=INT_MIN;
	longestPath(root,maxP);
	return maxP;
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
	Node *I=new Node (0);
	Node *J=new Node (0);
	Node *K=new Node(0);
	Node *L=new Node(0);
	H->lc=I;
	I->lc=J;
	J->lc=K;
	K->lc=L;
	
	root->lc=A;
	//root->rc=B;
	A->rc=C;
	C->lc=E;
	C->rc=F;
	B->rc=D;
	D->rc=G;
	E->rc=H;
	F->lc=B;
	std::cout<<"the longest path is "<<longestPathBinarytree(root)<<std::endl;
	deleteTree(root);
}
