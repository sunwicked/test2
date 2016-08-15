#include<iostream>
#include<set>
#include<stack>
#include<map>
#include<list>
#include<climits>
using namespace std;
class Node{
	public:
	Node *lc=NULL;
	Node *rc=NULL;
	int data;
	Node(int val){
		data=val;
	}
};
struct resultSet{
    bool result;
    int lo;
    int hi;
    int siz;
    resultSet(){}
    resultSet(bool v,int l,int h,int s):result(v),lo(l),hi(h),siz(s){}
    resultSet set(bool v,int l,int h,int s){
        result=v;
        lo=l;
        hi=h;
        siz=s;
        return *this;
    }
};
ostream & operator<<(ostream & out,Node *root){
    return out<<root->data<<"  ";
}
//------------------------------INORDER ITERATOR----------------------------------------->
void inOrderDisplay(Node *root){
    if(root==NULL) return;
    inOrderDisplay(root->lc);
    std::cout<<root->data<<" ";
    inOrderDisplay(root->rc);
}

void iterativeInorder(Node *root){
    std::stack<Node *> node;
    Node * current=root;
    std::cout<<"Iterative inorder is : ";
    while(true){
        if(current!=NULL){
            node.push(current);
            current=current->lc;
        }
        else if(node.empty()) break;
        else{
            current= node.top();
            node.pop();
            std::cout<<current->data<<" ";
            current=current->rc;
        }
    }
}

class InorderIterator{
    public:
    Node *prev=NULL;
    Node *current=NULL;
    Node *root=NULL;
    int data;
    std::stack<Node *> node;
    InorderIterator(Node *root){
        this->root=root;
        current=root;
    }
    Node * operator++(){
        while(current!=NULL){
            node.push(current);
            current=current->lc;
        }
        if(node.empty()) return NULL;
        prev = node.top();
        node.pop();
        current=prev->rc;
        data=prev->data;
        return prev;
    }
    Node * operator++(int){
        while(current!=NULL){
            node.push(current);
            current=current->lc;
        }
        if(node.empty()) return NULL;
        prev = node.top();
        node.pop();
        current=prev->rc;
        data=prev->data;
        return prev;
    }
    
};
//------------------------------PREORDER ITERATOR---------------------------------------->
void preOrderDisplay(Node *root){
    if(root==NULL) return;
    std::cout<<root->data<<" ";
    preOrderDisplay(root->lc);
    preOrderDisplay(root->rc);
}

void iterativePreorder(Node *root){
    std::stack<Node *> node;
    Node * current=root;
    std::cout<<"Iterative PreOrder is : ";
    while(true){
        if(current!=NULL){
            std::cout<<current->data<<"  ";
            if(current->rc!=NULL) node.push(current->rc);
            current=current->lc;
        }
        else if(node.empty()) break;
        else{
            current= node.top();
            node.pop();
        }
    }
}

class PreOrderIterator{
    public:
    Node *prev=NULL;
    Node *current=NULL;
    Node *root=NULL;
    int data;
    std::stack<Node *> node;
    PreOrderIterator(Node *root){
        this->root=root;
        current=root;
    }
    Node * operator++(int){
       if(current!=NULL);
        else if(node.empty()) return NULL;
        else {
            current = node.top();
            node.pop();            
        }
        prev=current;
        data=current->data;
        if(current->rc!=NULL) node.push(current->rc);
        current = current->lc;
        return prev;
    }   
    
    Node * operator++(){
        if(current!=NULL);
        else if(node.empty()) return NULL;
        else {
            current = node.top();
            node.pop();            
        }
        prev=current;
        data=current->data;
        if(current->rc!=NULL) node.push(current->rc);
        current = current->lc;
        return prev;
    }    
};

//------------------------------POSTORDER ITERATOR--------------------------------------->
void postOrderDisplay(Node *root){
    if(root==NULL) return;
    postOrderDisplay(root->lc);
    postOrderDisplay(root->rc);
    std::cout<<root->data<<" ";
}

void iterativePostOrder(Node *root){
    std::stack<Node *> node;
    Node * current=root;
    std::cout<<"Iterative PostOrder is : ";
    std::stack<Node *> s1;
    std::stack<Node *> s2;
    s1.push(root);
   // current=root;
    while(!s1.empty()){
        current=s1.top();
        s1.pop();
        s2.push(current);
        if(current->lc) s1.push(current->lc);
        if(current->rc) s1.push(current->rc);
    }
    while(!s2.empty()){
        current=s2.top();
        std::cout<<current<<" ";
        s2.pop();
    }
}
void postOrderSingleStack(Node *root){
    std::stack<Node *> node;
    Node* current=root;
    Node * temp = NULL;
    while(current!=NULL || !node.empty()){
        if(current!=NULL) {
            node.push(current);
            current=current->lc;
        }
        else{
            if(!node.empty())temp = node.top()->rc;
            if(temp==NULL){
                temp= node.top();
                node.pop();
                std::cout<<temp<<" ";
                while(!node.empty() && temp==node.top()->rc){
                    temp= node.top();
                    node.pop();
                    std::cout<<temp<<" ";
                }
            }
            else current = temp;
        }
    }
}
class PostOrderIterator{
    public:
    Node *prev=NULL;
    Node *current=NULL;
    Node *root=NULL;
    int data;
    std::stack<Node *> node;
    PostOrderIterator(Node *root){
        this->root=root;
        current=root;
    }
    Node * operator++(int){
       if(current!=NULL);
        else if(node.empty()) return NULL;
        else {
            current = node.top();
            node.pop();            
        }
        prev=current;
        data=current->data;
        if(current->rc!=NULL) node.push(current->rc);
        current = current->lc;
        return prev;
    }   
    
    Node * operator++(){
        if(current!=NULL);
        else if(node.empty()) return NULL;
        else {
            current = node.top();
            node.pop();            
        }
        prev=current;
        data=current->data;
        if(current->rc!=NULL) node.push(current->rc);
        current = current->lc;
        return prev;
    }    
};
//--------------LONGEST PATH IN BINARY TREE---------------------------------------------->
int longestPath(Node *root, int &maxLen){
    if(root==NULL) return 0;
    int lenL=0;
    int lenR=0;
    int pathL=0;
    lenL = 1 + longestPath(root->lc,maxLen);
    lenR = 1 + longestPath(root->rc,maxLen);
    pathL = lenL + lenR-1;
    maxLen = std::max(maxLen,pathL);
    return max(lenL,lenR);
}
//--------------------LOWEST COMMON ANCESTOR--------------------------------------------->
Node * findLCAUtil(Node *root, Node *A, Node *B, bool &v1, bool &v2){
    if(root == NULL) return NULL;
    if(root == A) {
        v1 = true;
        return root;
    }    
    if(root == B){
        v2=true;
        return root;
    }
    Node *lca_left = findLCAUtil(root->lc,A,B,v1,v2);
    Node *lca_right = findLCAUtil(root->rc,A,B,v1,v2);
     // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if(lca_left && lca_right ) return root;
    // Otherwise check if left subtree or right subtree is LCA
    return (lca_left!=NULL) ? lca_left : lca_right ;
}
bool find(Node *A, Node *B){
    if(A == NULL) return false ;
    
    if(A==B) return true;
    else return(A==B || find(A->lc,B)|| find(A->rc,A));
    
}

Node * lowestCommonAncestor(Node *root,Node * A, Node *B){
    bool v1=false,v2=false;
    Node *lca = findLCAUtil(root,A,B, v1,v2);
    if(v1 && v2 || v1 && find(lca, B)|| v2 && find(lca,A)) return lca;
    else return NULL;
    
}
void findPathUtil(Node *root, std::list<Node *> &path){
    if(root->lc==NULL && root->rc==NULL){
        for(auto p: path ) std::cout<<p<<" ";
        std::cout<<root<<"\n";
        return ;
    }
    path.push_back(root);
    if(root->lc) findPathUtil(root->lc,path);
    if(root->rc) findPathUtil(root->rc,path);
    path.pop_back();
}
//--------------------------PATH TO LEAF------------------------------------------------->
void printAllPathtoLeaf(Node *root){
    std::list<Node *> path;
    findPathUtil(root,path);
}
//-----------------------------PRINTING SPIRAL ORDER------------------------------------->
void printSpiralOrder(Node* root){
    std::stack<Node *> s1;
    std::stack<Node *> s2;
    s1.push(root);
    Node *temp=NULL;
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            temp = s1.top();
            s1.pop();
            std::cout<<temp;
            if(temp->lc) s2.push(temp->lc);
            if(temp->rc) s2.push(temp->rc);
            
        }
        while(!s2.empty()){
            temp = s2.top();
            s2.pop();
            std::cout<<temp;
            if(temp->rc) s1.push(temp->rc);
            if(temp->lc) s1.push(temp->lc);
            
        }
    }
}


//---------------------------- EQUALITY OF TWO TREES ------------------------------------>
bool equalityOfTwoTrees(Node* T1,Node* T2){
    if(T1==NULL && T2==NULL) return true;
    
    return ((T1 !=NULL && T2!=NULL) && T1->data==T2->data && 
                             equalityOfTwoTrees(T1->lc,T2->lc)&&
                             equalityOfTwoTrees(T1->rc,T2->rc));
 //       return true;
   // return false
}
//--------------------------------VERIFY BST--------------------------------------------->
bool verifyBSTUtil(Node * root,int lo,int hi){

    if(root->data>lo && root->data <= hi){
    
        if(root->lc!=NULL && !verifyBSTUtil(root->lc,lo,root->data)) return false;        
  
        if(root->rc!=NULL && !verifyBSTUtil(root->rc,root->data,hi)) return false;            
        
        return true;
    }
    else return false;
}

bool verifyBST(Node *root){
    if(root==NULL) return true;
    int lo  = INT_MIN;
    int hi  = INT_MAX;
    return verifyBSTUtil(root,lo,hi);
}
//--------------------------FIND LARGEST BST--------------------------------------------->
/*
resultSet findLargestBST(Node *root, int& maxCount){
    if(root==NULL) return resultSet();
    if(root->lc==NULL && root->rc==NULL) return resultSet(true,root->data,root->data,1);
    resultSet lrs,rrs;
    lrs = findLargestBST(root->lc,maxCount);
    rrs = findLargestBST(root->rc,maxCount);
    if((root->lc && root->rc)){// && 
       if( lrs.result && rrs.result &&  lrs.hi< root->data && root->data < rrs.lo ){
         maxCount = std::max(lrs.siz + rrs.siz+1,maxCount);
         return resultSet(true,lrs.lo,rrs.hi,lrs.siz + rrs.siz+1);
      }
      else return resultSet(false,0,0,0);
   }
    else if(root->lc && lrs.hi < root->data){
        maxCount = std::max(lrs.siz +1,maxCount);
        return resultSet(true,lrs.lo,lrs.hi,lrs.siz+1);
    }  
    else if(root->rc && rrs.lo > root->data){
        maxCount = std::max(rrs.siz +1,maxCount);
        return resultSet(true,rrs.lo,rrs.hi,rrs.siz+1);
    } 
    else return resultSet(false,0,0,0);
}*/

resultSet* findLargestBST(Node *root, int& maxCount){
    if(root->lc==NULL && root->rc==NULL) return new resultSet(true,root->data,root->data,1);
    resultSet *lrs=NULL;
    resultSet *rrs=NULL;
    if(root->lc)  lrs = findLargestBST(root->lc,maxCount);
    if(root->rc)  rrs = findLargestBST(root->rc,maxCount);
    if((root->lc && root->rc)){// && 
       if( lrs->result && rrs->result &&  lrs->hi< root->data && root->data < rrs->lo ){
         maxCount = std::max(lrs->siz + rrs->siz+1,maxCount);
         return new resultSet(true,lrs->lo,rrs->hi,lrs->siz + rrs->siz+1);
      }
      else return new resultSet(false,0,0,0);
   }
    else if(root->lc && lrs->hi < root->data){
        maxCount = std::max(lrs->siz +1,maxCount);
        return new resultSet(true,lrs->lo,lrs->hi,lrs->siz+1);
    }  
    else if(root->rc && rrs->lo > root->data){
        maxCount = std::max(rrs->siz +1,maxCount);
        return new resultSet(true,rrs->lo,rrs->hi,rrs->siz+1);
    } 
    else return new resultSet(false,0,0,0);
}

int findLargestbst(Node *root,int &maxCount){
    if(root==NULL) return 0;
    int lsbt = findLargestbst(root->lc,maxCount);
    int rsbt = findLargestbst(root->rc,maxCount);
    bool v1= verifyBST(root->lc);
    bool v2= verifyBST(root->rc);
    if(v1 && v2 && verifyBST(root)){
        maxCount = std::max(lsbt+rsbt+1,maxCount);
        return lsbt+rsbt+1;
    }
    return 0;
        
}
//------------------------------------Main----------------------------------------------->
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
	//A->lc=B;
	C->lc=E;
	C->rc=F;
	B->rc=D;
	D->rc=G;
	E->rc=H;*/
/*	Node *root=new Node(25); 
	Node *B =new Node (18);
	Node *C =new Node (50);
	Node *D =new Node (19);
	Node *E =new Node (20);
	Node *F =new Node (35);
	Node *G=new Node (60);
	Node *H=new Node (15);
	Node *I=new Node (18);
	Node *J=new Node (25);
	Node *K=new Node (20);
	Node *L=new Node (40);
    Node *M=new Node (55);
	Node *N=new Node (70);
	Node *O=new Node (25);
	root->lc=B;
	root->rc=C;
	B->lc=D;
	B->rc=E;
	C->lc=F;
	C->rc=G;
	D->rc=H;
	E->lc=I;
	E->rc=J;
	F->lc=K;
	F->rc=L;
	G->lc=M;
	G->rc=N;
	K->rc=O;*/

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
    L->lc=M;
	//------------------------------
	std::cout<<"\n InOrderDisplay is : ";
	inOrderDisplay(root);
	std::cout<<"\n ";
	iterativeInorder(root);
	std::cout<<"\n Inorder Iterator Display is : ";
	InorderIterator itr(root);
	while(itr++ !=NULL){
	   std::cout<<itr.data<<" ";
	}
	std::cout<<"\n ";
	//----------------------------------------
	std::cout<<"\n Preor Display is : ";
	preOrderDisplay(root);
	std::cout<<"\n ";
	iterativePreorder(root);
	std::cout<<"\n PreOrder Iterator Display is : ";
	std::cout<<"\n ";
	PreOrderIterator iter(root);
	while(++iter !=NULL){
	   std::cout<<iter.data<<" ";
	}
	//-----------------------------------------
	std::cout<<"\n ";
	std::cout<<"\n PostOrderDisplay is : ";
	postOrderDisplay(root);
	std::cout<<"\n ";
	iterativePostOrder(root);
	//std::cout<<"\n Inorder Iterator Display is : ";
	//InorderIterator itr(root);
	//while(itr++ !=NULL){
	  // std::cout<<itr.data<<" ";
	//}
	
	std::cout<<"\n PostOrderDisplay  using Single Stack is : ";
	postOrderSingleStack(root);
	std::cout<<"\n ";
	int maxLen=0;
	longestPath(root,maxLen);
	std::cout<<"Longest Path length is : "<<maxLen<<std::endl;
	std::cout<<"\n PATHS ARE :  ";
	printAllPathtoLeaf(root);
	//std::cout<<"Lowest Common Ancestor "<<lowestCommonAncestor(root,H,G)<<std::endl;
	std::cout<<"SPIRAL ORDER TRAVERSAL IS  ";
	printSpiralOrder(root);
	std::cout<<"\n ";
	int m=1;
	std::cout<<"MAXIMUM SIZE OF BST IS :  ";
	findLargestbst(root,m);
	//findLargestBST(root,m);
	std::cout<<m<<"\n ";
	
}
	
