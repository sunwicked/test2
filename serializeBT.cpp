#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Node{
	public:
	Node *lc=NULL;
	Node *rc=NULL;
	char data;
	//int data;
	//Node(int val){
	//	data=val;
	//}
	Node(char val){
		data=val;
	}
	
};
ostream & operator<<(ostream & out,Node *root){
    return out<<root->data<<"  ";
}

void preOrderDisplay(Node *root){
    if(root==NULL) return;
    std::cout<<root->data<<" ";
    preOrderDisplay(root->lc);
    preOrderDisplay(root->rc);
}
//------------------------SERIALIZE BINARY TREE------------------------------------>
void serializeUtil(Node* root, vector<string> &tree){
	if(root==NULL){
		tree.push_back("#");
		return;
	}
	tree.push_back(std::to_string(root->data));
	serializeUtil(root->lc,tree);
	serializeUtil(root->rc,tree);
}

vector<string> serialize(Node *root){
	vector<string> tree;
	serializeUtil(root,tree);
	std::cout<<"\n";
	for(auto p : tree){
		std::cout<<p<<"  ";
	}
	
	std::cout<<"\n";
	return tree;
}
//------------------------DESERIALIZE BINARY TREE------------------------------------>
Node* deserializeBTUtil(vector<string> &tree,int& index,int len){
	if(index>=len || tree[index]=="#"){
		return NULL;
	}
	Node *newNode = new Node(std::stoi(tree[index++]));
	
	newNode->lc= deserializeBTUtil(tree,index,len);
	index++;
	newNode->rc= deserializeBTUtil(tree,index,len);
	
	return newNode;
}
Node* deserializeBT(vector<string> & tree){
	int len=tree.size();
	int index=0;
	Node *root = deserializeBTUtil(tree,index,len);
	return root;
//	preOrderDisplay(root);
	
}
//----------------------MAIN---------------------------------------------->
int main(){
	/*
	Node *root=new Node(100); 
	Node *B =new Node (50);
	Node *C =new Node (150);
	Node *D =new Node (40);
	Node *E =new Node (60);
	Node *F =new Node (130);
	Node *G=new Node (30);
	Node *H=new Node (55);
	Node *I=new Node (125);
	Node *J=new Node (120);
	Node *K=new Node (110);
	Node *L=new Node (105);
	Node *M=new Node (102);
	root->lc=B;
	root->rc=C;
	B->lc=D;
	B->rc=E;
	C->rc=F;
	D->lc=G;
	E->lc=H;
	F->lc=I;
	I->lc=J;
    J->lc=K;
    K->lc=L;
    L->lc=M;*/
	Node *A = new Node('A');
	Node *B = new Node('B');
	Node *C = new Node('C');
	A->lc=B;
	A->rc=C;
	preOrderDisplay(A);
	vector<string> tree= serialize(A);
	preOrderDisplay(deserializeBT(tree));
}