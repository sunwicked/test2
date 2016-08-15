#include<iostream>

bool  chkCollision(int arr[], int row){
   int tmp;
   for(int i=0;i<row;++i){
     tmp=arr[row]-arr[i];
     if(tmp==0 || tmp == row-i || tmp == i-row)   return true;
   }
   return false;
}

void search(int arr[], int row, int N,int &count){
   if(row==N){
      ++count;
      if(count<5){
         for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
               if(arr[i]==j) std::cout<<"Q"<<"  ";
               else std::cout<<"-"<<"  ";
            }
            std::cout<<"\n";
         }
         std::cout<<"\n";
      }
      
      return;
   }
   for(int i = 0; i<N; ++i){
      arr[row]=i;
      if(!chkCollision(arr,row))  search(arr,row+1,N,count);
   }
}

int main(){
   int N;
   std::cin>>N;
   int count =0;
   int arr[N];
   search(arr,0,N,count);
   std::cout<<"\n Count = "<<count;
}
