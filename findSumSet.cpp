#include<iostream>
#include<set>
#include<map>

using mapSet = std::map<int,std::set<int>>;

std::set<int>findSetHelper(mapSet & remSet,int k){
   std::set<int> result;
   if(remSet[0].size()!=0) result.insert(*(remSet[0].begin()));
   for(int i = 1;i<=(k+1)/2; ++i){
     if( k%2==0 && i==k/2  ) {
       if(remSet[i].size()!=0) result.insert(*(remSet[i].begin()));
     }
     else if(remSet[i].size() != 0 || remSet[k-i].size()!=0){
        std::set<int> largeSet = (remSet[i].size() > remSet[k-i].size()? remSet[i] :remSet[k-i] );
        result.insert(remSet[i].begin(),remSet[i].end());
     }
   }
   return result;
}

std::set<int> findSet(int arr[],int n,int k){
    std::set<int> result;
    mapSet remSet;
    int rem;
    for(int i=0;i<n;++i){
        rem = arr[i]% k;
        remSet[rem].insert(arr[i]);
    }
    return findSetHelper(remSet,k);    
}

int main(){
    int n=30;
    int arr[n];
    int k;
    std::cout<<"Enter Number : ";
    std::cin>>k;
    std::cout<<"\n";
    for(int i=0;i<n;++i){
        arr[i]=i+1;
    }
    std::set<int> res= findSet(arr,n,k);
    for(auto p: res){
        std::cout<<p<<"  ";
    }
    std::cout<<"\n";
    return 0;
}
    

