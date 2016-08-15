#include<iostream>

class Node {
  public:
  float data;
  Node *next=NULL;
  Node *down=NULL;
  Node(float x) : data(x){}
};
Node *flattenLinkedList(Node * head){
   if((head->next==NULL) && (head->down ==NULL)){
      std::cout<<head->data<<"  ";
      return head;
   }
   std::cout<<head->data<<"  ";
   Node * prev=NULL;
   Node * NEXT=NULL;
   if(head->down!=NULL){
      if(head->next!=NULL) NEXT= head->next;
      prev=flattenLinkedList(head->down);
      head->down=NULL;
   }
   if(NEXT!=NULL){
      prev->next=NEXT;
      flattenLinkedList(NEXT);
   }
   else if(head->next!=NULL) return flattenLinkedList(head->next);
 //  return prev;
}

int main(){
   Node *root= new Node(1);
   Node *A= new Node(2.1);
   Node *B= new Node(2.2);
   Node *C= new Node(2.3);
   Node *D= new Node(3);
   Node *E= new Node(4.1);
   Node *F= new Node(4.2);
   root->next=D;
   root->down=A;
   A->next=B;
   B->next=C;
   D->down=E;
   E->next=F;
   Node *current=root;
    while(current->next!=NULL){
    //std::cout<<current->data<<"  ";
    current=current->next;
   }
   std::cout<<"\n";
   flattenLinkedList(root);
   current=root;
   std::cout<<"\n";
   do {
    std::cout<<current->data<<"  ";
    current=current->next;
   } while(current!=NULL);
   

   
}
