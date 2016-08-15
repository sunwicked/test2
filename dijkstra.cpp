#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<fstream>
#include<set>
#include<climits>
#include<string>
#include<map>
#include "Graph.cpp"
using namespace std;
using Pair = std::pair<string,int>;
class mycomparison {
  public:
  bool operator() (const Pair &lhs,const Pair &rhs) {
    return lhs.second>rhs.second;
  }
};
void calculateShortestpath(string &src,string &des,Graph&g,std::set<std::string> &visited,
                           std::map<std::string,int> &distance, priority_queue< Pair, vector<Pair> ,mycomparison> &pq, int& dist){
	if(pq.empty()) return ;
	Pair p = pq.top();
//	if(p.first==des) return ;
    pq.pop();
	visited.insert(p.first);
	std::cout<<p.first<<"  "<<p.second<<"  "<<dist<<std::endl;
	for(auto x : g.cities[p.first]->connectedEdges){
		string city= x.first->name;
		
		if(!visited.count(city)) {
			if(distance[city]>dist+ x.second){
				distance[city] = dist+ x.second;
				pq.push(Pair(x.first->name,distance[city]));
			}			
		}
	}
	dist = pq.top().second;
	calculateShortestpath(src,des,g,visited,distance,pq,dist);
}

int  dijkstra(std::string src,std::string des,Graph &g){
	std::set<std::string> visited;
	std::map<std::string,int> distance;
	for(auto p: g.cities)   distance[p.first]=INT_MAX;
	distance[src]=0;
	priority_queue< Pair, vector<Pair>,mycomparison> pq;
	//std::map<std::string,int>::iterator itr =distance.begin();
	//while(itr!=distance.end()){ std::cout<<(*itr).first<<"  "<<(*itr).second<<std::endl;++itr;}
	int dist = 0;
	pq.push(Pair(src,0));
	//calculateShortestpath(src,des,g,visited,distance,pq,dist);
//	for(auto p: distance)std::cout<<p.first<<" " <<p.second<<std::endl;
	return dist;
}
void calculateMST(std::set<std::string> &visited,Graph &g,std::priority_queue<Pair,vector<Pair>,mycomparison> &pq,int &mst){
	if(pq.empty()) return ;
	
	Pair p= pq.top();
	pq.pop();
	if(visited.count(p.first)) {}
	else {
	visited.insert(p.first);
	
	mst+=p.second;
	std::cout<<p.first<<"  "<<p.second<<"  "<<mst<<"  "<<visited.size()<<std::endl;
	if(visited.size() == g.cities.size()) return ;
	for(auto x : g.cities[p.first]->connectedEdges){
		if(!visited.count(x.first->name)){
			pq.push(Pair(x.first->name,x.second));
		}
	}
	}
	calculateMST(visited,g,pq,mst);
	
}
int primsMST(Graph&g){	
	std::set<std::string> visited;
	std::priority_queue<Pair,vector<Pair>,mycomparison> pq;	
	//pq.push(Pair((*g.cities.begin()).first,0));
	pq.push(Pair("Charlotte",0));
	int mst=0;
	calculateMST(visited,g,pq,mst);
	return mst;
}
int main(){
	std::ifstream inputFile("Graph.txt");
	Graph g(inputFile);
//	std::cout<<"\n Distance is : "<<dijkstra("Wilmington","Charlotte",g)<<std::endl;
	std::cout<<"\n MST distance  is : "<<primsMST(g)<<std::endl;
}