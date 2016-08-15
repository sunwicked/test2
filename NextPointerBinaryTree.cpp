-----------USING RECURSION WITH SPACE OPTIMIZED-------------------->
 /*
  * getNextSibling  function used to get the next
  * Sibling. We are passing the parent Node 
  * here and it will return the next Sibling for its
  * child. It will iterate through the parents 
  * sibling untill it finds a child node and return it.
  * else it will return NULL;
  */
 Node *getNextSibling(Node *parent){
	 parent=parent->S;
	 while(parent!=NULL){
		 if(parent->L!=NULL)  return parent->L;
		 if(parent->R!=NULL) return parent->R;
		 parent=parent->S;
	 }
	 return NULL;
 }
 
 /* 
  * assignSibling function called from assignS.
  * uses getNextSibling function to find the 
  * sibling for right child of node and for the left
  * child if the right child is Null
  */
 void assignSibling(Node *current){
    if(current==NULL ) return ;	
     Node *left= current->L;
	Node *right=current->R;
	//If left & right are NULL then we will go to 
	// find siblings for current Sibling
	if(left==NULL && right ==NULL){
		assignSibling(current->S);
		return;
	}
	else if(left!=NULL && right!=NULL) {
		left->S=right;
	}
	else if(right==NULL){
		left->S=getNextSibling(current);
	}
    if(right!=NULL) right->S=getNextSibling(current);
	// we need to find recursively sibling for current child 
	// and sibling
	assignSibling(current->S);
	assignSibling(left);
	assignSibling(right);	
 }
 /*
  * This is the function which will be called to 
  * assign Sibling. Here we are assigning NULL to 
  * Sibling of the root and then passing the root
  * to determine the sibling of the rest tree
  */
  
 int assignS(Node *root){
	 root->S=NULL;
	 assignSibling(current);
	 return 0;
 }

--------USING BREADTHFIRST APPROACH---------------------------->
int assignS(Node *root){
     std::queue<Node *> nodes;
     Node *prev=NULL;
     Node *dummy=new Node;
     Node *current=root;
     nodes.push(root);
     nodes.push(dummy);
     while(!nodes.empty()){
        current=nodes.front();
        nodes.pop();
        if(current==dummy) {
             prev=NULL;
             nodes.push(current);
             continue;
        }
        if(current->L != NULL)  nodes.push(current->L);
        if(current->R != NULL)  nodes.push(current->R);
        if(prev!=NULL){
             prev->S=current;
	}
        prev=current;
	}
    return 0;
}
