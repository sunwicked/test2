#include<iostream>
struct link{
	int data;
	link * next;
};
void displayLinklist(link * head){
	std::cout<<"link list  :";
	link *cur =head;
	while(cur!=NULL){
		std::cout<<cur->data<<" -> ";
		cur=cur->next;
	}
	std::cout<<"\n";
}
link* reverseLinkList(link *head){
	link *cur=head;
	link *prev=NULL;
	link *next=cur;
	link *temp2=cur;
	while (cur!=NULL){
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	return prev;
}

		
int main(){
	link *a=new link;
	link *b=new link;
	link *c=new link;
	a->data =1;
	b->data=2;
	c->data=3;
	a->next=b;
	b->next=c;
	c->next=NULL;
	displayLinklist(a);
	link p;
	link q;
	link r;
	p.data =4;
	q.data=5;
	r.data=6;
	p.next=&q;
	q.next=&r;
	r.next=NULL;
	c->next=&p;
	displayLinklist(a);
	displayLinklist(reverseLinkList(a));
}

