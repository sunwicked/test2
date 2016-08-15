#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <cassert>
#include <climits>
#include <stack>

/*-------------------------------------------------------------------
 * Class Node represents vertex
 * contains two data members 
 *     1) data
 *    2) Adjacency list of vertex 
 *
 *-------------------------------------------------------------------
*/

class Node {
  public:
  char data;
  std::list<Node *> child;
  Node(char x): data(x){}                   //contructor for Node where node data is initialized 
};


/*-------------------------------------------------------------------
 * Class Graph  is wrapper class 
 * helper functions are defined and declared 
 * data member 1) root 
 *             2) vector of all  Nodes in Graph 
 *--------------------------------------------------------------------------------------------------------------------------------------
*/
class Graph{
  private:
    Node *root;
    std::vector<Node *> vertexList;
    bool detectCycleHelper(Node * , std::set<Node *>& , std::map<Node *,int> &);
    int maxPathLength(Node *root);
    void TopSort(Node *root, std::stack<Node *>& sorted);
    void DFS(Node *root, std::set<Node *>& visited, std::stack<Node *>& postfix);
    int maxPathLengthInternal(Node *src, Node *dest, std::map<Node *, int>& level);
  public:  
    Graph();
    void setRoot(Node * );
    Node * newNode(char);  
    void addEdge(Node *,Node *);
    void displayAdjList();
    int maxPathUtil();
    bool detectCycle();
  
};

/*-------------------------------------------------------------------
 * Graph::Graph()
 *
 * Input   : Constructor
 * Output  : Reserve a vector of size 20;
 *           
 * Purpose : To initialize data members
 *-------------------------------------------------------------------
*/

Graph::Graph():root(NULL),vertexList(){
  vertexList.reserve(20);            //this would increae dynamically
}

/*-------------------------------------------------------------------
 * Graph::newNode
 *
 * Input   : char
 * Output  : return a pointer to newly created node 
 *         
 * Purpose : initialize data of Node for newly created node
 *           and also push the nodes in vector 
 *-------------------------------------------------------------------
*/
Node* Graph::newNode(char node){
  Node *temp= new Node(node);
  vertexList.push_back(temp);
  return temp;
}


void Graph::setRoot(Node * root){
  this->root=root;
}


void Graph::addEdge(Node *src,Node *dest){
  (src->child).push_back(dest);
}  
/*-------------------------------------------------------------------
 * Graph::displayAdjList
 *
 * Input   : Nothing
 * Output  : will display adjacency list for each of the node 
 *         
 * Purpose : initialize data of Node for newly created node
 *           and also push the nodes in vector 
 *-------------------------------------------------------------------
*/
void Graph::displayAdjList(){
  std::cout<<"\nAdj List is as below "<<std::endl;
  for(auto p : vertexList){
    std::cout<<p->data<<" : ";
    for(auto y : p->child){
      std::cout<<y->data<<"  ";
    }
    std::cout<<"\n";
  }
}


/*
 *---------------------------------------------------------------------------------------
 * Graph::maxPathLength
 *
 *  Input   : Root of the Graph
 *  Output  : length of the node 
 *         
 *  Purpose : find out the maximum path length 
 *  
 *  Time Complexity ; O(V + E)
 *  Space Complexity : O(V)
 *
 *---------------------------------------------------------------------------------------
 */
int Graph::maxPathLength(Node *root) {
  std::stack<Node*> sorted;
  TopSort(root, sorted);
  Node *last = nullptr;
  while (not sorted.empty()) {
    auto vertex = sorted.top();
    sorted.pop();
    if (sorted.empty()) {
      last = vertex;
    }
  }
  std::map<Node *, int> level;
  level[last] = 0;
  return maxPathLengthInternal(root, last, level);
}

int Graph::maxPathLengthInternal(Node *src, Node *dest, std::map<Node *, int>& level) {
  auto retval = 0;
  for (auto vertex : src->child) {
    auto temp = 0;
    std::map<Node *, int>::const_iterator iter;
    if ((iter = level.find(vertex)) != level.end()) {
      temp = iter->second;
    }
    else if(src==dest) { level[src]=0;}
    else {
      temp = maxPathLengthInternal(vertex, dest, level);
      level[vertex] = temp;
    }
    retval = std::max(retval, temp + 1);
  }
  return retval;
}
/*-------------------------------------------------------------------
 * Graph::TopSort
 *
 * Input   : root node 
 * Output  : stack with nodes in topological order 
 *         
 * Purpose : node that is farthest 
 *-------------------------------------------------------------------
*/

void Graph::TopSort(Node *root, std::stack<Node *>& sorted) {
  std::set<Node *> visited = {root};

  //Run DFS to compute level map.
  DFS(root, visited, sorted);
}

  
void Graph::DFS(Node *root, std::set<Node *>& visited, std::stack<Node *>& postfix) {
  for (auto vertex : root->child) {
    std::set<Node *>::const_iterator iter;
    if ((iter = visited.find(vertex)) != visited.end()) {
      // We have already visited this path.
      continue;
    } else {
      visited.insert(vertex);
    }
    DFS(vertex, visited, postfix);
  }
  postfix.push(root);
  return;
}
/*-------------------------------------------------------------------
 * Graph:: maxPathUtil
 *
 * Input   : called to find maximum node 
 * Output  : returns the maximum pathlength of maximum node 
 *           
 * Purpose : first it will assert whether there is cycle .
 *           If not then only the program will proceed.
 *           else it will stop
 *
 *-------------------------------------------------------------------
*/

int Graph::maxPathUtil(){
  // Have put an assertion to check cyclic condition
  assert(detectCycle()==false && "is Cyclic");                  
	return maxPathLength(root);
}
/*-------------------------------------------------------------------
 * Graph::detectCycleHelper
 *
 * Input   : root , visited set and vertex map with value 0 or 1 which will indicate 
             whether visite
 * Output  : Helper function to detect whether there is cycle or not 
 *           
 * Purpose : To detect whether there is cycle  in the graph
 *
 *-------------------------------------------------------------------
*/

 bool Graph::detectCycleHelper(Node * root, std::set<Node *>& visited, std::map<Node *,int> &vertex){
 if(!visited.count(root)){
     visited.insert(root);
     vertex[root]=1;
     for(auto p: root->child){
       if(!visited.count(p) &&  detectCycleHelper(p,visited,vertex))
         return true;
       else if(vertex[p] == 1) 
         return true;
     }
  }
  vertex[root]=0;
  return false;
}

/*-------------------------------------------------------------------
 * Graph::detectCycleHelper
 *
 * Input   : Graph would call this method 
 * Output  : it will return bool value true - if cycle is there and false
 *            if there is no cycle
 *           
 * Purpose : To detect whether there is cycle  in the graph
 * Time Complexity - O ( V + E )
 *-------------------------------------------------------------------
*/

bool Graph::detectCycle(){
  std::set<Node *> visited;
  std::map<Node *,int> vertex;
  for(int i=0;i<vertexList.size();i++){
    if(detectCycleHelper(vertexList[i],visited,vertex))
      return true;
   }
  return false;
}

void testCase1(){
  Graph g;
	Node * A = g.newNode('a');
	Node * B = g.newNode('b');
	Node * C = g.newNode('c');
	Node * D = g.newNode('d');
	Node * E = g.newNode('e');
	Node * F = g.newNode('f');
	Node * G = g.newNode('g');
	g.setRoot(A);
	g.addEdge(A,B);
	g.addEdge(A,C);
	g.addEdge(A,E);
	g.addEdge(B,D);
	g.addEdge(D,E);
	g.addEdge(C,D);
  g.displayAdjList();
  std::cout<<"\nMaximum Path length is : "<<g.maxPathUtil()<<std::endl;
}

void testCase2(){
  Graph g;
	Node * A = g.newNode('a');
	Node * B = g.newNode('b');
	Node * C = g.newNode('c');
	Node * D = g.newNode('d');
	Node * E = g.newNode('e');
	Node * F = g.newNode('f');
	g.setRoot(A);
	g.addEdge(A,B);
	g.addEdge(A,C);
	g.addEdge(A,D);
	g.addEdge(B,D);
	g.addEdge(B,C);
	g.addEdge(C,D);
	g.addEdge(C,E);
	g.addEdge(E,F);
	g.displayAdjList();
	std::cout<<"\nMaximum Path length is : "<<g.maxPathUtil()<<std::endl;
}
void testCase3(){
  Graph g;
	Node * A = g.newNode('a');
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
	g.addEdge(F,G);
	g.displayAdjList();
	std::cout<<"Maximum Path length is : "<<g.maxPathUtil()<<std::endl;	
}
void testCaseDetectingCycle(){
  Graph g;
	Node * A = g.newNode('a');
	Node * B = g.newNode('b');
	Node * C = g.newNode('c');
	Node * D = g.newNode('d');
	Node * E = g.newNode('e');
	Node * F = g.newNode('f');
	Node * G = g.newNode('g');
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
	g.displayAdjList();
	if(g.detectCycle())
	  std::cout<<"\n Cycle is Present"<<std::endl;
	else std::cout<<"\n no cycle"<<std::endl;
}
void testCaseWithCycle(){
  Graph g;
	Node * A = g.newNode('a');
	Node * B = g.newNode('b');
	Node * C = g.newNode('c');
	Node * D = g.newNode('d');
	Node * E = g.newNode('e');
	Node * F = g.newNode('f');
	Node * G = g.newNode('g');
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
	g.displayAdjList();
	std::cout<<"\nMaximum Path length is : "<<g.maxPathUtil()<<std::endl;
}

int main(){
 testCase1();    // this is the same as given in the problem
 testCase2();    // should return 4
 testCase3();    //  should return 6
 testCaseDetectingCycle(); // this test case would detect whether there is a cycle 
 testCaseWithCycle();     // this should abort the program as cycle is there in this program 
 return 0;
}
