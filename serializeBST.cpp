#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<climits>
#include<string>
using namespace std;
using ull= unsigned long long int;
/*
                                                                          
                                100
                               /    \
                              /      \
                            50       200
                           /  \      /  \
                         25   75    150   225
                       /        \    /      \
                      20        80  125     280      
                      
                               100
                               /    \
                              /      \
                            50       75
                           /  \      /  \
                         25   35    15   25
                       /        \    /      \
                      20        30  125     280      
                                                                                                                                            
*/

struct Node{
    int data;
    Node * lc=NULL;
    Node *rc=NULL;
    Node(int x): data(x){}
};

std::ostream& operator<<(std::ostream &out, Node *x){
    return out<<x->data<<"  ";
}

//--------------------------------INORDER BST-------------------------------------------->
void inorderBST(Node *root){
    if(root == NULL ) return;
    inorderBST(root->lc);
    std::cout<<root;
    inorderBST(root->rc);
}
//---------------------------------SERIALIZATION OF BST------------------------------------>
/* We are using PRE_ORDER FOR THIS PURPOSE-
*/
void preOrder(Node *root,vector<string> &BST){
	if(root==NULL) return ;
	BST.push_back(std::to_string(root->data));
	preOrder (root->lc,BST);
	preOrder(root->rc,BST);
}
vector<string> serializeBST(Node *root){
	vector<string> BST;
	preOrder(root,BST);
	return BST;
}
//---------------------------------DE SERIALIZATION OF BST------------------------------------>
//https://www.youtube.com/watch?v=H594EV9OuDI&list=PLamzFoFxwoNjoWpJEkBGDYOTCebkTZwz5&index=2
int partition(vector<string> &BST,int val,int lo,int hi){
	int i;
	for( i =lo;i<=hi;++i){
		if(val<std::stoi(BST[i]))
			break;
	}
	return i;
}
Node *deserializeBSTUtil(vector<string> & BST, int lo,int hi){
	if(lo>hi) return NULL;
	Node *newNode = new Node(std::stoi(BST[lo]));
	std::cout<<"\n New Node Created : "<<newNode->data<<std::endl;
	int iDiv= partition(BST, newNode->data,lo+1,hi);
	newNode->lc = deserializeBSTUtil(BST,lo+1,iDiv-1);
	newNode->rc = deserializeBSTUtil(BST,iDiv,hi);
	return newNode;;
}
//-------------DESERIALIZE BST O(N)------------------------------
Node * deserializeBST2( vector<string> &BS,int &index,int lo,int hi){
	if(index>=BS.size()) return NULL;
	Node *newNode = NULL;
	if(std::stoi(BS[index])>lo && std::stoi(BS[index])<=hi) {
		newNode = new Node(std::stoi(BS[index++]));
		std::cout<<"\n New Node Created : "<<newNode->data<<std::endl;
		newNode->lc= deserializeBST2(BS,index,lo,newNode->data);
		newNode->rc= deserializeBST2(BS,index,newNode->data,hi);
	}
	return newNode;
}
Node* deserializeBST(vector<string> &BS){
	return deserializeBSTUtil(BS,0,BS.size()-1);
	int index=0;
	//return deserializeBST2(BS,index,INT_MIN,INT_MAX);
}
	
//----------------------------------MAIN ------------------------------------------------>
int main(){
    Node *A = new Node(10); 
    Node *B = new Node(5); 
    Node *C = new Node(20);
    Node *D = new Node(3);
    Node *E = new Node(8);
    Node *F = new Node(15);
    Node *G = new Node(23);
    Node *H = new Node(2);
    Node *I = new Node(9);
    Node *J = new Node(13);  
    Node *K = new Node(28);    
    A->lc = B;
    A->rc = C;
    B->lc = D;
    B->rc = E;
    C->lc = F;
    C->rc = G;
    D->lc = H;
    E->rc = I;
    F->lc = J;
    G->rc = K;
    std::cout<<"\n INORDER TRAVERSAL IS : ";
     inorderBST(A);
	 vector<string> BS =serializeBST(A);
	std::cout<<"\n";
	for(auto p : BS) std::cout<<p<<"  ";
	std::cout<<std::endl;
	std::cout<<"\n INORDER TRAVERSAL IS : ";
	inorderBST(deserializeBST(BS));
   
}

