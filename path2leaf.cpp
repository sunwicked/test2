#include<iostream>
#include<list>
class Graph{
	private:
	int v;
	std::list<int> *adj;
	//std::list<int> path;

	public:
	Graph(int n){
		this->v=n;
		adj=new std::list<int>[v];
	}
	void addEdge(int src,int des){
		adj[src].push_back(des);
	}

	void displayGraph(){
		for(int i=0;i<v;i++){
			std::cout<<" Adjacent vertex list for vertex "<<i<<" are ";
		   for(auto p: adj[i]){
				std::cout<<" -> "<<p;
			}
			std::cout<<"\n";
		}
	}

	void printleaf(int n){
		bool *visited=new bool[v];
		for(int i=0;i<v;i++)
			visited[i]=false;
		std::list<int> path;
	visited[n]=true;
		path.push_back(n);
		printpath2leaf(n,visited,path);
	}

	void printpath2leaf(int n, bool *visited,std::list<int> &path){
		if(adj[n].size()==0){
			for(auto p: path){
				std::cout<<p<<"-> ";
			}
	   	std::cout<<"\n";
			//path.pop_back();
		}
		else {
	//	if(!visited[n]) {
	//		path.push_back(n);
	//		visited[n]=true;
	//	}
			for(auto p: adj[n]){
				if(!visited[p]){
					visited[p]=true;
					path.push_back(p);
					printpath2leaf(p,visited,path);
					path.pop_back();
					visited[p]=false;
				}
			}
		}
	}
};


int main(){
/*	Graph g(8);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,5);
	g.addEdge(2,6);
	g.addEdge(5,7);
	g.displayGraph();
	g.printleaf(0);*/
/*	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(3,5);
	g.addEdge(4,6);
	g.addEdge(5,6);
	g.displayGraph();
	g.printleaf(0);*/
   Graph g(7);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(3,5);
	g.addEdge(4,6);
	g.addEdge(5,6);
	g.displayGraph();
	g.printleaf(0);
}


