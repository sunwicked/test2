#include<iostream>
#include<climits>
Try this input {1, 3, 6, 3, 2, 3, 6, 8, 9,5} 
//---------------------------------
int minJumps(int arr[],int l, int r){
    if(l>=r) return 0;
    if(arr[l]==0) return INT_MAX;
    int minJump=INT_MAX;
    for(int i=l+1;i<=l+arr[l];++i){
        int jump=0;
        jump = 1+ minJumps(arr,i,r);
        minJump = std::min(jump,minJump);
    }
    return minJump;
}
//---------------------------------------------
int minJumpsRecursive(int arr[],int n){
    int Jumps[n];
    Jumps[0]=0;
    for(int i=1;i<n;++i){
        Jumps[i]=INT_MAX;
        for(int j = 0;j<i;++j){
            if(i<=j+arr[j] && Jumps[j]!=INT_MAX){
                Jumps[i]=std::min(Jumps[i],1+Jumps[j]);
                break;
            }
        }
    }
    return Jumps[n-1];
}
//------------------------------------------------------O( n)----
int minJumpsLinear(int a[],int n){
    for(int i=1;i<n;++i){
        a[i]=std::max(a[i],a[i-1]-1);
        if(a[i]==0 && i!=n-1) return INT_MAX;
    }
    int sum=0,count=0;
    while(sum<n){
        sum+=a[sum];
        count++;
    }
    return count;
}
int main(){
   //int arr[] = {1, 3, 6, 3, 2, 3, 6, 8,9};
   int arr[]={1, 3, 6, 1, 0, 9};
  int n = sizeof(arr)/sizeof(arr[0]);
  std::cout<<"Minimum number of jumps to reach end is "<< minJumps(arr, 0, n-1)<<std::endl;
  std::cout<<"Minimum number of jumps to reach end is "<< minJumpsRecursive(arr,n)<<std::endl;
  std::cout<<"Minimum number of jumps to reach end is "<< minJumpsLinear(arr,n)<<std::endl;
  return 0;
}
