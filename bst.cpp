#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<climits>
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
    int lo  = INT_MIN;
    int hi  = INT_MAX;
    return verifyBSTUtil(root,lo,hi);
}
//--------------------------------SEARCH BST--------------------------------------------->
bool searchBst(Node *root,int key){
    Node *current = root;
    while(true){
        if(current == NULL ) return false;
        if(current->data== key) return true;
        else if(current->data > key) current= current->lc;
        else current = current->rc;
    }
}

//--------------------------------LOWEST COMMON ANCESTOR -------------------------------->
Node *lca(Node *root,Node *A,Node *B){
    if(root==NULL) return NULL;
    if((A->data <= root->data && B->data>=root->data) ||
       ( B->data <= root->data && A->data>=root->data)){
        return root;
    }
    if(A->data >= root->data && B->data >=root->data){
        return lca(root->rc,A,B);
    }
    else return lca(root->lc,A,B);
}
//--------------------NUMBER OF POSSIBLE BST--------------------------------------------->
ull noOfPossibleBst(int n){
    std::vector<ull> T(n+1,0);
    T[0]=1;
    T[1]=1;
 //   int sum =0 ;
    for(int i=2;i<=n;++i){
        for(int j=0;j<i;++j){
            T[i]+=T[j]*T[i-j-1];
        }
    }
    return T[n];
}
//--------------------------------INORDER BST-------------------------------------------->
void inorderBST(Node *root){
    if(root == NULL ) return;
    inorderBST(root->lc);
    std::cout<<root;
    inorderBST(root->rc);
}

//----------------------------------MAIN ------------------------------------------------>
int main(){
  /*  Node *A = new Node(100); 
    Node *B = new Node(50); 
    Node *C = new Node(200);
    Node *D = new Node(25);
    Node *E = new Node(75);
    Node *F = new Node(150);
    Node *G = new Node(225);
    Node *H = new Node(20);
    Node *I = new Node(80);
    Node *J = new Node(125);  
    Node *K = new Node(280);    */
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
    if(verifyBST(A)) std::cout<<" \nIT IS BST"<<std::endl;
    else  std::cout<<" \nIT IS NOT BST"<<std::endl;
   /* for(int i =1;i<30;++i){
        if(searchBst(A,i)) std::cout<<"\n"<<i<<"  "<<"PRESENT";
        else std::cout<<"\n"<<i<<"  "<<"NOT PRESENT";
    }*/
    std::cout<<"\n LCA OF TWO NODES IS "<<lca(A,E,I)<<std::endl;
    for(int i =1;i<30;++i){
        std::cout<<"\nNUMBER OF POSSIBLE BST FOR "<<i<<" is "<<noOfPossibleBst(i)<<std::endl;
    }
}

