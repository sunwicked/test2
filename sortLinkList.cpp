#include<iostream>
#include<cstdlib>
#include<ctime>
/* --------------------ALGORITHM--------------------------------------------
   Have used merge sort method to sort link list . Time complexity of this
   sort id O( N log N) where N is the size of the link list and it  is done 
   in place 
*/
// Node of link List 
class ListNode {
    public:
	int val;
	ListNode * next = NULL;
	// constructor 
	ListNode(int x) :val(x){}
};

// overloaded output operator 
std::ostream & operator<<(std::ostream &out, ListNode * node){
	return out << node->val << "  ";
}

// function to display the link list sequentially
void displayLinkList(ListNode *head){
	ListNode *current = head;
	while (current != NULL){
		std::cout << current;
		current = current->next;
	}
}

/*
    Merge function sorts two sorted link list recursively and return head of the new link list
*/
ListNode * merge(ListNode * firstHead, ListNode *secondHead){
	//base case when one of the node is null return other
	if (firstHead == NULL) return secondHead;
	if (secondHead == NULL) return firstHead;
	// to store the next link
	ListNode *head = NULL;
	// compare linklist head values
	// head will be pointing to the smaller and we call recursively for the next nodes
	if (firstHead->val > secondHead->val){
		head = secondHead;
		head->next = merge(firstHead, secondHead->next);
	}
	else {
		head = firstHead;
		head->next = merge(firstHead->next, secondHead);
	}
	return head;
}

/*
  splitLinkList function splits a linklist into two halves and after the function returns firsthead contains 
  reference to the head of the first link list and secondHead contains reference to the head of the second link
  list. We are keeping two pointers and we make fast pointer move twice the speed of slow pointer so that when 
  fast pointer is at end of the link list slow is at the middle and we split at that point  and assign slow->next
  to secondHead and head to firstHead
*/
void splitLinkList(ListNode *head, ListNode **firstHead, ListNode **secondHead){
	if (head == NULL || head->next == NULL) return;
	ListNode *slow = head;
	ListNode *fast = head->next;
	while (fast != NULL){
		fast = fast->next;
		if (fast != NULL){
			fast = fast->next;
			slow = slow->next;
		}
	}
	*firstHead = head;
	*secondHead = slow->next;
	slow->next = NULL;
}

/*
  sortList function utilizes merge sort for sorting the linklist .
  Have splitted the linklist recursively into two halves and then we
  merged it
*/ 
ListNode * sortList(ListNode *head){
	ListNode * first = NULL;
	ListNode * second = NULL;
	if (head == NULL || head->next == NULL) return head;
	splitLinkList(head, &first, &second);
	first = sortList(first);
	second = sortList(second);
	return merge(first,second);
}
/*
  this is called recursively to avoid memory leak 
*/
void deleteLinkList(ListNode *head){
	if (head == NULL) return;
	deleteLinkList(head->next);
	delete head;
}

int main(){
	unsigned int size = 10;
    srand(time(0));
	//randomly generated 5 different link list of different lengths ranging from 1 to 15
	for(int i = 0;i<5;++i){ 
	    int repeat = rand()%15 + 1;
	    ListNode * head = NULL;
    	ListNode *current = NULL;
		// creating a link list
	    for (int i = 0; i< repeat; ++i){
		    int x = rand() % 100;
		    ListNode *newNode = new ListNode(x);
			// assign head to the link list for first node of the link list
		    if (head == NULL) head = newNode;
		    else current->next = newNode;
	    	current = newNode;
	    }
	    std::cout << "\nLink List without sort :  ";
	    displayLinkList(head);
	    std::cout << "\n After Sorting Link List is ";
		// calls sortList and returns new head and then display the link list 
	    displayLinkList(sortList(head));
	    std::cout << "\n";
        deleteLinkList(head);
	}
}
