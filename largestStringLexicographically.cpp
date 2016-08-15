#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
using vecPair =std::vector<std::pair<int,int>> ;
using pair =std::pair<int,int>;
void swap(std::string &str,int i,int j){
  char x=str[i];
  str[i]=str[j];
  str[j]=x;
}
std::string largestString(std::string &str,vecPair &sp){
   std::set<int> *swapS=new std::set<int>[str.size()];
   std::set<int> visitedIndex;
   vecPair::iterator itr = sp.begin();
   std::string str2="";
   while(itr!=sp.end()){
       int p1= itr->first;
       int p2=itr->second;
       swapS[p1].insert(p2);
       swapS[p2].insert(p1); 
       for(auto p : swapS[p1]){
            swapS[p2].insert(p);
            swapS[p].insert(p2);
        }   
       for(auto p : swapS[p2]){
            swapS[p].insert(p1);
            swapS[p1].insert(p);
            }   
       ++itr;
   }
   int i=0;
   for(int l=0;l<str.size();l++){
      std::cout<<l<<" : ";
      for(auto p : swapS[l]){
         std::cout<<p<<"  ";
       }
       std::cout<<"\n";
    }
   while(str[i]){
       if(swapS[i].size()==0){
         // str2=str2+str[i];
          i++;
          continue;
       }
       else{
          int  max = i;
          for(auto p: swapS[i]){
            if(!visitedIndex.count(p)){
              if(str[p]>str[max])
                max=p;
            }
          }
          visitedIndex.insert(i);
          swap(str,i,max);
       }
          
         i++; 
   }
   return str ;
}
int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::string str;
    std::cout<<"enter String ";
    std::cin>>str;
    int n;
    std::cout<<"enter no of exchanges ";
    std::cin>>n;
    vecPair sp;
    sp.reserve(n);
    for(int i=0;i<n;i++){
      int k,j;
      std::cout<<"enter pairs ";
      std::cin>>k>>j;
      sp.push_back(pair(k,j));
    }
    std::cout<<largestString(str,sp)<<std::endl;
return 0;
}
