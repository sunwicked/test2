#include<iostream>
#include<list>
#include<map>
class Graph{
	int v;
	std::list<int> *adj;
	void dfsUtil(bool[], int);
	void printpathdest(std::map<int,int> &,int,int);
	public:
	Graph(int);
	~Graph();
   void addEdge(int ,int );
	void DisplayNodes();
	void bfs();
	void dfs();
	void printPath(int , int);
};

Graph::Graph(int n){
	v=n;
	adj=new std::list<int>[v];
}
	
Graph:: ~Graph(){
	delete []adj;
}

void Graph::addEdge(int src,int dest){
  src--;
  dest--;
  adj[src].push_back(dest);
}

void Graph::DisplayNodes(){
  for(int i=0;i<v;i++){
    std::list<int>::iterator it;
    std::cout<<"the edges for node "<<i+1<<"->"; 
    //for(it=adj[i].begin();it!=adj[i].end();it++){
    for(auto &p: adj[i]){
      std::cout<<"->"<<p+1<<"\t";
	  }
	  std::cout<<"\n";
  }
}


void Graph::dfsUtil(bool visited[], int index){
  visited[index]=true;
  std::cout<<index+1<<"\t";
  std::list<int>::iterator it;
  for(it=adj[index].begin();it!=adj[index].end();++it){
	  if(!visited[*it])
		  dfsUtil(visited,*it);
  }
}

void Graph::dfs(){
  bool *visited =new bool[v];
  std::cout<<"\n"<<"dfs traversal is "<<std::endl;
  for(int i=0;i<v;i++){
  visited[i]=false;
  }
  for(int i=0;i<v;i++){
	  if(!visited[i])
		  dfsUtil(visited,i);
  }
}

void Graph::bfs(){
  bool *visited = new bool[v];
  for(int i=0;i<v;i++){
    visited[i]=false;
  }
  std::cout<<"\n"<<"bfs traversal is "<<std::endl;
  std::list<int> queue;
  queue.push_back(0);
  visited[0]=true;
  int s;
  while(!queue.empty()){
    s=queue.front();
	 std::cout<<s+1<<"\t";
	 queue.pop_front();
	 for(auto p: adj[s]){
	   if(!visited[p]){
		  queue.push_back(p);
		  visited[p]=true;
		}
	  }
  }
  delete []visited;
}

void Graph::printPath(int src,int dest){
       src--;
       dest--;

	bool *visited=new bool[v];
	std::map<int,int> childParent;
	for(int i=0;i<v;i++)
		visited[i]=false;
	std::list<int> queue;
	int s=src;
	queue.push_back(s);
	visited[src]=true;
     //   std::cout<<"queue"<<queue.back();
	while(!queue.empty() && !(queue.back()==dest)){
		s= queue.front();
               // std::cout<<1<<std::endl;
		queue.pop_front();
		std::list<int>::iterator it;
                for(auto p: adj[s]){
	          if(!visited[p]){
                   childParent.insert(std::pair<int,int>(p,s) );
                    //childParent[p]=s;
		    queue.push_back(p);
		    visited[p]=true;
		}
	  }
		/*for(it=adj[s].begin();it!=adj[s].end();++it){
			if(!visited[*it]){
			childParent[*it]=s;
			queue.push_back(*it);
			visited[*it]=true;
			}
			if(*it==dest) break;
		}*/
	}
        std::map<int,int>::iterator it;
        for(auto elem : childParent)
{
   std::cout << elem.first << " " << elem.second<< " " << "\n";
}
        /*for(it=childParent.begin();it!=childParent.end();it++){
         std::cout<<"it->first"<<(*it).first<<"\t" <<(*it).second;
}*/
	printpathdest(childParent,src,dest);
}

void Graph::printpathdest(std::map<int,int> &cp,int src,int dest){
	if(dest==src){
        std::cout<<dest+1<<"->" ;
        return ;}
	else 
		printpathdest(cp,src,cp[dest]);
	std::cout<<dest+1<<"->";
}



int main(){
	Graph g(6);
	g.addEdge(1,6);
	g.addEdge(1,3);
        g.addEdge(3,2);
	g.addEdge(2,4);	
	g.addEdge(3,5);
	//g.addEdge(2,5);
	//g.addEdge(5,4);
	//g.addEdge(5,6);
	//g.addEdge(5,3);
	g.DisplayNodes();
	g.bfs();
	g.dfs();

	std::cout<<"\n";
	g.printPath(1,4);
	std::cout<<"\n";
}

