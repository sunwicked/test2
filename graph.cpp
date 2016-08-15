#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <cassert>
#include <climits>
#include <stack>
#include <map>
using namespace std;
class Node {
  public:
  std::list<Node *> child;
  char data;
  Node (char x) : data(x){}
};
std::ostream& operator<<(std::ostream &out,Node *node){
   return out<<node->data<<"  ";
}

class Graph{
   std::vector<Node *> vertexList;
   Node *root;
   public:
   void setRoot(Node *x){
      root=x;
   }
   Graph(){}
   Node * newNode(char x){
      Node  * temp=new Node(x);
      vertexList.push_back(temp);
      return temp;
   }
   void addEdge(Node *src,Node *tar){
      src->child.push_back(tar);
   }
   void displayAdjList(){
      for(auto p: vertexList) {
         std::cout<<p<<" : ";
         for(auto x:p->child)
           std::cout<<x;
         std::cout<<"\n";
      }      
   }
   void BFS(){
      queue<Node *> graphNode;
      Node *current=root;
      std::set<Node *> visited;
      visited.insert(current);
      graphNode.push(current);
      std::cout<<"\n BFS traversal is : ";
      while(!graphNode.empty()){
         current=graphNode.front();
         std::cout<<current;  
         graphNode.pop();
         for(auto p:current->child){
            if(!visited.count(p)) {
               visited.insert(p);
               graphNode.push(p);
            }
         }
      }      
   }
   
   void DFSUtility(Node *current, std::set<Node *>& visited){
      visited.insert(current);
      std::cout<<current;
      for(auto p: current->child){
         if(!visited.count(p)) {
            visited.insert(p);
            DFSUtility(p,visited);
         }
      }
   }
   
   void DFS(){
      Node *current=root;
      std::cout<<"\n BFS traversal is : ";
      std::set<Node *> visited;
      for(auto p: vertexList){
         if(!visited.count(p)){
            DFSUtility(p,visited);
         }
      }
   }
   
   bool detectCycleUtil(set<Node*> &visited, Node *current,set<Node *>& recStack){
     visited.insert(current);
     recStack.insert(current);
     for(auto p:current->child){
       if(!visited.count(p) && detectCycleUtil(visited,p,recStack)) return true;
       else if(recStack.count(p))return true;
     }
     recStack.erase(current);
     
     return false;   
   }
   
   bool detectCycle(){
      std::set<Node *> visited;
      std::set<Node *> recStack;  
      for(auto p:vertexList){
         if(!visited.count(p)){
            if(detectCycleUtil(visited,p,recStack)) {
               std::cout<<"\n size is "<<recStack.size()<<std::endl;
               return true;
            }
         }          
      }
      std::cout<<"\n size is "<<recStack.size()<<std::endl;
      return false;
   }
   
   void printPath2leaf(Node *root,set<Node*> &visited, list<Node*> &path){
      visited.insert(root);
      path.push_back(root);
      
     // std::cout<<"current node is "<<root<<std::endl;
      if(root->child.size()==0) {
        std::cout<<" \n PATH IS : ";
        for(auto p: path) std::cout<<p;
        std::cout<<"\n";
         path.pop_back();
         visited.erase(root); 
        return;
      }
      for(auto p:root->child){
         if(!visited.count(p)) 
           printPath2leaf(p,visited,path);
      }
      path.pop_back();
      visited.erase(root);  
      
   }
   void path2leaf(){
      set<Node *> visited;
      list<Node *> path;
      std::cout<<"Vertex List is : ";
      for(auto p:vertexList) {
         std::cout<<p;
      }
      cout<<endl;
    //  for(auto p:vertexList){
      //   if(!visited.count(p)){
            printPath2leaf(root,visited,path);
        // }
      //}
   }
   void shortestPath(Node *src,Node *target){
       if(src==target) {
           std::cout<<" src is same as target\n";
           return;
       }
       std::queue<Node *> graphNode;
       Node *current =src;
       std::set<Node *> visited;
       graphNode.push(current);
       std::map< Node *,Node*> parent;
       parent[current]=current;
       visited.insert(current);
       bool found =false;
       while(!graphNode.empty()){
           current=graphNode.front();
           graphNode.pop();
           for(auto p: current->child){
               if(!visited.count(p)){
                   parent.insert(std::pair<Node *, Node*>(p,current));//parent[p]=current;
                   graphNode.push(p);
                   
                   if(p==target){
                    found=true;
                    break;
                   }
                   visited.insert(p);
                }                   
           }
           if(found) break;
       } 
       if(!found) {std::cout<<"\n target not found"<<std::endl;    return;}
       current=target;
       std::list<Node *> path;
       path.push_front(current);
       do{
           current=parent[current];
           path.push_front(current);
           
       }while(current!=root);
       
       std::cout<<"\n shortest path is : " ;
       for(auto p: path) std::cout<<p;
   }
   
};


int main(){
  Graph g;
	/*Node * A = g.newNode('a');
	Node * B = g.newNode('b');
	Node * C = g.newNode('c');
	Node * D = g.newNode('d');
	Node * E = g.newNode('e');
	Node * F = g.newNode('f');
	Node * G = g.newNode('g');
	g.setRoot(A);
	g.addEdge(A,B);
	g.addEdge(A,C);
	g.addEdge(A,D);
	g.addEdge(B,D);
	g.addEdge(B,C);
	g.addEdge(C,D);
	g.addEdge(C,E);
	g.addEdge(E,F);
	g.addEdge(D,E);
	g.addEdge(F,G);*/
	Node * A = g.newNode('a');
	Node * B = g.newNode('b');
	Node * C = g.newNode('c');
	Node * D = g.newNode('d');
	Node * E = g.newNode('e');
	Node * F = g.newNode('f');
	Node * G = g.newNode('g');
	Node * H = g.newNode('h');
	g.setRoot(A);
	g.addEdge(A,B);
	g.addEdge(A,C);
	g.addEdge(A,E);
	g.addEdge(B,D);
	g.addEdge(D,E);
	g.addEdge(A,D);
	g.addEdge(C,D);
	g.addEdge(E,F);
	g.addEdge(F,G);
	g.addEdge(G,E);
		g.addEdge(G,H);
	g.displayAdjList();
	g.BFS();
	g.DFS();
	g.shortestPath(A,G);
	if(g.detectCycle()) std::cout<<"\n Cycle is present"<<std::endl;
	
	else std::cout<<"\nNo cycle is present"<<std::endl;
	g.path2leaf();
}
