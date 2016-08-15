#include<iostream>
#include<climits>
#include<vector>
using namespace  std;
void swap(vector<int> &num,int i,int j){
   int temp=num[i];
   num[i]=num[j];
   num[j]=temp;
}
int greatestNo(int n){
   int x=n;
   int rem;
   int prev=INT_MAX;
   vector<int>num;
   while(x>0){
      rem=x%10;
      x=x/10;
      num.push_back(rem);
      if(rem>prev) break;
      if(x==0) return n;
      prev=rem;     
   }
   int i=0;
   int len=num.size();
   for(int i=0;i<len-1;++i){
      if(num[i]<num[len-1]){
         swap(num,i,len-1);
         break;
      }
   }
   x=x*10+num[len-1];
   for(int i=0;i<len-1;++i){
    x=x*10+num[i];
   }
   return x;
}

int countGreaterNumber(int n){
   int count=0;
   while(true){
      int x=greatestNo(n);
      if(x==n){
         return count;
      }
      ++count;
      n=x;
      std::cout<<x<<"  ";
   }
}

int main(){
int x;
std::cout<<"enter number ";
std::cin>>x;
std::cout<<"greatest number less than x is : "<<countGreaterNumber(x)<<std::endl;
return 0;
}
