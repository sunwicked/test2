#include<iostream>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<vector>
#include<list>
#include<utility>
using namespace std;
using Map = std::map<std::string,std::set<std::string>>;
using listset =std::list<std::set<std::string>> ;

void modifiedDFS(Map &stringMap,set<string> &keys, set<string> &visited,std::string  con,std::set<string>& cont){
  visited.insert(con);
  if(keys.count(con)) cont.insert(con); 
  Map::iterator itr=stringMap.find(con);
  if(itr==stringMap.end()) return;
  for(auto p : itr->second){
    if(!visited.count(p)){
       modifiedDFS(stringMap,keys,visited,p,cont);
    }
  }
}

void findContactUtility(Map &stringMap, set<string> &keys){
  listset contacts;
  std::set<std::string>::iterator itr=keys.begin();
  set<string> visited;
  std::set<string> cont;
  while(itr!=keys.end()){
    if(!visited.count(*itr)){
       std::set<std::string> cont;
       modifiedDFS(stringMap,keys,visited,*itr,cont);
       contacts.push_back(cont);
    }
    ++itr;
  }
  for(auto p: contacts){
    for(auto x: p){
      std::cout<< x<<"  ";
    }
    std::cout<<std::endl;
  }
     
}


void findCommonContact(Map& stringMap){
  Map::iterator itr=stringMap.begin();
  std::set<std::string> keys;
  Map::iterator iter;
  while(itr!=stringMap.end()){
    keys.insert(itr->first);
    ++itr;
  }
  itr=stringMap.begin();
  while(itr!=stringMap.end()){
    if(keys.count(itr->first)){
      for(auto p: itr->second){
        if((iter=stringMap.find(p))!=stringMap.end())  (iter->second).insert(itr->first);
        else   stringMap.insert({p,{itr->first}});
      }
    }
    ++itr;
  }
  findContactUtility(stringMap,keys);
}



int main(){
  Map stringMap ={{"C1",{"A","B"}},
                  {"C2",{"D"}},
                  {"C3",{"B","E"}},
                  {"C4",{"E"}},
                  {"C5",{"D"}},
                  {"C6",{"F"}},
                 };
  findCommonContact(stringMap);
}
