#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<list>
#include<set>

#include<fstream>
using Vector=std::vector<std::string>;
using Map= std::map<char,std::list<char> >;

void DFSUtil(Map &adj,char src, char des,std::string &str, std::set<char> &visited,Vector &path){
  if(src==des){
    path.push_back(str);
    return;
  }
  else{
   for(auto p:adj[src]){
     if(!visited.count(p)){
       str.push_back(p);
       visited.insert(p);
       DFSUtil(adj,p,des,str,visited,path);
       str.pop_back();
       visited.erase(visited.find(p)); 
     }
    }
  }   
}

Vector findPath(Map &adj,char src,char des){
  Vector path;
  Map::iterator itr;
  std::set<char> visited;
  std::string str="";
  
  if((itr=adj.find(src))!=adj.end()){
    str.push_back(src);
    DFSUtil(adj,itr->first ,des,str,visited,path);
  }  
  return path;  
}
Vector parseLine(Vector &lines){
  std::string temp=lines[0];
  char s=temp[0];
  char d=temp[2];
  Map adjMap;
  std::cout<<s<<"  "<<d<<std::endl;
  for(int i=1;i<lines.size();i++){
   temp=lines[i];
   int k=0;
   bool isKey=true;
   char key;
   std::list<char> adj;
   while(temp[k]){
     if(isalpha(temp[k])){
       if(isKey){
         key=temp[k];
         isKey=false;
        }
        else{
          adj.push_back(temp[k]);
        }
       }
       k++;  
    }
    adjMap.insert(std::pair<char,std::list<char> >(key,adj));
  }
  Map::iterator itr;
  for(auto p: adjMap){
    std::cout<<p.first<<" : ";
    for(auto x: p.second)
      std::cout<<x<<"  ";
    std::cout<<"\n";
   }
  Vector path= findPath(adjMap,s,d);
  return path;
}

int main(){
 Vector lines;
 Vector path;
 lines.push_back("A C");
 lines.push_back("A : B D E ");
 lines.push_back("B : C D A");
 lines.push_back("D : C");
// lines.push_back("D : C");
 lines.push_back("E : B");
 
 path=parseLine(lines);
 std::cout<<"Following are the paths : ";
 for(auto p:path){
 
   std::cout<<p<<"  ";
 }
 
}
