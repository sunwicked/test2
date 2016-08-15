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
    //str.pop_back();
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
int findPath(Map &adj,char src,char des,std::map<char,int> & distTar){
  if(src==des) {
    return 1;
  }
  if(distTar.find(src)!=distTar.end()) return distTar[src];
  int ret=0;
  for(auto p:adj[src]){
    ret=ret+findPath(adj,p,des,distTar);
  }
  distTar[src]=ret;
  return ret;
}
int findNoOfPath(Map &adj,char src, char des){
  std::map<char,int> distTar;
  distTar[des]=0;
  int ret=findPath(adj,src,des,distTar);
  
  return ret;
}

  
  
int parseLine(Vector &lines){
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
  int count= findNoOfPath(adjMap,s,d);
  return count;
}

int main(){
 Vector lines;
 Vector path;
 int count=0;
 lines.push_back("A C");
 lines.push_back("A : B D E");
 lines.push_back("B : C D A");
 lines.push_back("D : C");
// lines.push_back("D : C");
 lines.push_back("E : B");
 
 count=parseLine(lines);
 std::cout<<"Following are the paths : "<<count;
// for(auto p:path){
 
  // std::cout<<p<<"  ";
 //}
 
}
