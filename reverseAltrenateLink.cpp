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
	while (cur!=NULL){
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	return prev;
}
link* reverseAlternateLink(link *head,int k,bool rev){
	link *current=head;
	link *head1=NULL;
	link *prev=NULL;
	link *next;
	link *bottom1=NULL;
	int count=0;
	while(current !=NULL){
		if(rev){
			for(int i=0;i<k;i++){				
				if(current==NULL) return prev;
				if(i==0){
					head1=current;
					next=current->next;
					prev=current;
					current=next;
				}
				else if(i==k-1){
				//	bottom1=current;
					next=current->next;
					current->next=prev;
					if(count==0) head=current;
					if(bottom1!=NULL) bottom1->next=current;
					prev=head1;
					current=next;
				}
				else{
					next=current->next;
					current->next=prev;
					prev=current;
					current =next;
				}
				
			}
			head1->next=current;
			rev=false;
		}
		else {
			count++;
			for(int j=0;j<k;j++){
				if(current==NULL) return prev;
				if(j==k-1){
					prev=current;
					bottom1=current;
					current=current->next;
				}
				else {
					prev=current;
			   	current =current->next;
				}
			}
				rev=true;
		}
	}
	return head;
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
	link p;
	link q;
	link r;
	p.data =4;
	q.data=5;
	r.data=6;
	p.next=&q;
	q.next=&r;
	//r.next=NULL;
	c->next=&p;
	
	link *x=new link;
	link *y=new link;
	link *z=new link;
	r.next=x;
	x->data =7;
	y->data=8;
	z->data=9;
	x->next=y;
	y->next=z;
	z->next=NULL;
	displayLinklist(a);
	int k=3;
	link * l=reverseAlternateLink(a,k,true);
	displayLinklist(l);
	//displayLinklist(reverseLinkList(a));
}

