#include<iostream>
using namespace std;
class Node{
   public:
   int data;
   Node * next=NULL;
   Node (int x): data(x){}
};
ostream & operator<<(ostream &out, Node * current){
   return out<<current->data<<"  ";
}
void displayLL(Node *head){
   cout<<"\n Link list is : ";
   Node *current=head;
   while(current!=NULL){
      std::cout<<current;
      current=current->next;
   }
   std::cout<<"\n";
}

Node * reverseLinkList(Node *head){
  Node *current=head;
  Node *prev=NULL;
  Node *next=NULL;
  while(current!=NULL){
     next=current->next;
     current->next=prev;
     prev=current;
     current=next;
  }
  return prev;
}

Node *mergeLinkList(Node *headA, Node *headB){
   if(headA==NULL|| headB==NULL) return NULL;
   Node *currentA=headA;
   Node *currentB=headB;
   Node *prev=NULL;
   Node *head=NULL;
   while(true){
     // std::cout<<"\n A= "<<currentA<<"  B= "<<currentB<<std::endl;
      if(currentA==NULL & currentB==NULL) break;
      if(currentA==NULL){
         prev->next=currentB;
         prev=currentB;
         currentB=currentB->next;
      }
      else if(currentB==NULL){
         prev->next=currentA;
         prev=currentA;
         currentA=currentA->next;      
      }
      else{
        std::cout<<"\n A= "<<currentA<<"  B= "<<currentB<<std::endl;
         if(currentA->data>currentB->data){
            if(prev==NULL) {
              head=currentB;
              
            }
            else prev->next=currentB;
            prev=currentB;
            currentB=currentB->next;
          }
         else {
            if(prev==NULL) {
              head=currentA;
            }
            else prev->next=currentA;
            prev=currentA;
            currentA=currentA->next;
          }
      }
   }
   return head;
}
int main(){
   Node * A=new Node(1);
   Node * B=new Node(2);
   Node * C=new Node(3);
   Node * D=new Node(4);
   Node * E=new Node(5);
   Node * F=new Node(6);
   Node * G=new Node(7);
   Node * H=new Node(8);
   Node * I=new Node(9);
   Node * J=new Node(10);
    A->next=B;
    B->next=C;
    C->next=D;
    D->next=E;
    E->next=F;
    F->next=G;
    G->next=H;
    H->next=I;
    I->next=J;
    displayLL(A);
   Node * K=new Node(1);
   Node * L=new Node(12);
   Node * M=new Node(13);
   Node * N=new Node(14);
   Node * O=new Node(15);
   Node * P=new Node(16);
   Node * Q=new Node(17);
   Node * R=new Node(18);
   Node * S=new Node(19);
   Node * T=new Node(20);
   K->next=L;
    L->next=M;
    M->next=N;
    N->next=O;
    O->next=P;
    P->next=Q;
    Q->next=R;
    R->next=S;
    S->next=T;
    //displayLL(K);
    displayLL(mergeLinkList(A,K));
  //  displayLL(reverseLinkList(A));
}
