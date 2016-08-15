#include<iostream>
#include<algorithm>
#include<climits>
/*every node return maximum of 3 values.
1) Node’s data.
2) Maximum in node’s left subtree.
3) Maximum in node’s right subtree.
*/
struct Node{
	Node *lc=NULL;
	Node *rc=NULL;
	int data;
	Node(int val){
		data=val;
	}
};

int minInBinTree(Node * root){
	if(root==NULL) return INT_MIN;
	int res=root->data;
	int lres=minInBinTree(root->lc);
	int rres=minInBinTree(root->rc);
	return std::max(std::max(lres,rres),res);
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
	root->lc=A;
	root->rc=B;
	A->rc=C;
	C->lc=E;
	C->rc=F;
	B->rc=D;
	D->rc=G;
	std::cout<<" min in bin tree "<<minInBinTree(root);
	delete root;
	delete A;
	delete B;
	delete C;
	delete D;
	delete E;
	delete F;
	delete G;
	//delete A,B,C,D,E,F,G,root;

}
