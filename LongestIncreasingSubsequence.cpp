#include<iostream>

//------------------------USING DP WITH O(N^2)-------------------------->
int lis(const int arr[],int len){
    int longest[len];
    int maxLis=1;
    for(int i=0;i<len;++i) longest[i]=1;
    for(int i =0;i<len;++i){
        int maxEndingAtI=1;
        for(int j=0;j<i;++j){
            if(arr[j]<arr[i]){
                longest[i]=std::max(maxEndingAtI,longest[j]+1);
                maxEndingAtI = longest[i];
            }
        }
    }
    for(int i=1;i<len;++i) {
        std::cout<<i<<"  "<<longest[i]<<std::endl;
        maxLis=std::max(maxLis,longest[i]);
    }
    return maxLis;
}
//--------------------OPTIMIZED DP USING (O N LOG N )-------------------------->
//http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
int calcIndex(int table[],int r, int a){
    int l=-1;
   int m;
    while(r-l>1){
        int m= l+(r-l)/2;
        if(table[m]>=a){
           r = m;
        } 
        else l=m; 
    }
    return r;
}
int longestIncreasingSubsequence( int A[], int length){
   int *table = new int[length];
   for(int i=0;i<length;++i) table[i]= 0;
   int len=1;
   table[0]=A[0];
   for(int i=1;i<length;++i){
      if(A[i]<table[0]) table[0]=A[i];
      else if(A[i]>table[len-1]) table[len++]=A[i];
      else {
          table[calcIndex(table,len-1,A[i])]=A[i];
      } 
   }
   return len;
}

int main(){
    int arr[]={ 10, 22, 9, 33, 21, 50, 41, 60, 80,42,43,75,44};
    int num=sizeof(arr)/sizeof(arr[0]);
    std::cout<<"Longest LIS length is "<<lis(arr,num)<<std::endl;
    std::cout<<"Longest LIS length is "<<longestIncreasingSubsequence(arr,num)<<std::endl;
}
