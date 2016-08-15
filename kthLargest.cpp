#include<iostream>
#include<algorithm>
using namespace std;
void swap(int arr[],int l,int r){
  int temp=arr[l];
  arr[l]=arr[r];
  arr[r]=temp;
}

void displayArr(int arr[],int len){
   cout<<"\n Array content is : ";
   for(int i =0;i<len;++i) cout<<arr[i]<<"  ";
}

void trickleUp(int arr[],int ndx, int len){
    int lc;
    while(len>=2*ndx+1){
      lc=2*ndx+1;
      if((lc+1<=len) && arr[lc]>arr[lc+1]) ++lc;
      if(arr[ndx]<arr[lc]) break;
      swap(arr,ndx,lc);
      ndx=lc;
    }            
}
int findKthItem(int arr[], int len, int k){
    int heapArr[k];
    for(int i=0;i<k;++i) heapArr[i]=arr[i];
    for(int j=(k-2)/2;j>=0;--j){
       trickleUp(heapArr,j,k);
    }
    for(int i=k;i<len;++i){
       if(heapArr[0]< arr[i]){
          heapArr[0]=arr[i];
          trickleUp(heapArr,0,k);
       }
    }   
    return  heapArr[0]; 
}
int main(){
	int len (10);
	int arr[len];
	srand(time(0));
	for(int i=0;i<10;i++)
		arr[i]=rand()%100;
	displayArr(arr,len);
	int k=4;
	std::cout<<"\n Kth item is "<<findKthItem(arr,len,k)<<std::endl;
	//sort(arr[0],arr[10]);
	//heapSort(arr,len);
	displayArr(arr,len);
	return 0;
}
