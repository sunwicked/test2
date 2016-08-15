#include<iostream>
#include<cstdlib>
#include<ctime>

void exch(int arr[], int i, int j){
   int temp= arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
}
void merge(int arr[],int aux[],int left,int mid,int right){
    for(int i=left;i<=right;++i) aux[i]= arr[i];
    int m = mid+1;
    int l=left;
    for(int i = left;i<=right;++i){
        if(m>right) arr[i]= aux[l++];
        else if(l>mid) arr[i] = aux[m++];
        else if (aux[l]>aux[m]) arr[i] = aux[m++];
        else arr[i]= aux[l++];
    }
}


void displayArr(int arr[],int len){
   std::cout<<"\n Array content is : ";
   for(int i =0;i<len;++i) std::cout<<arr[i]<<"  ";
}

void mergeSort(int arr[],int aux[],int l,int r){
    if(l>=r) return ;
    int m=l+(r-l)/2;
    mergeSort(arr,aux,l,m);
    mergeSort(arr,aux,m+1,r);
    merge(arr,aux,l,m,r);
}

void mergeSortItem(int arr[],int len){
    int aux[len];
    for(int i=0;i<len;++i){
        aux[i]=arr[i];
    }
    mergeSort(arr,aux,0,len-1);
}

int partition(int arr[],int l,int r){
    int pivot=arr[l];
    int j=l;
    int k=r+1;
    while(true){
        while(arr[++j]<pivot){
            if(j==r) break;
        }
        while(arr[--k]>pivot);
        if(j>=k) break;
        exch(arr,j,k);        
    }
    exch(arr,l,k);
    return k;
}

void quickSort(int arr[], int l,int r){
    if(r>l){
        int p = partition (arr,l,r);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,r);
    }
}

void heapify(int arr[],int len,int k){
    int lc ;
    while(len>=2*k+1){
        lc = 2*k+1;
        if(lc+1<=len && arr[lc]<arr[lc+1]) ++lc;
        if(arr[lc]<arr[k]) break;
        exch(arr,k,lc);
        k=lc; 
    }
    
}

void heapSort(int arr[],int len){
    int k = len/2 - 1;
    for(int i=k; i>=0;--i) heapify(arr,len-1,i);
    exch(arr,0,--len);
    while(len > 0){
        heapify(arr,--len,0);
        exch(arr,0,len);
    }
    
}
int main(){
	int len (10);
	int arr[len];
	//int arr[]={85 , 82,  86,  71,  6 , 72,  85,  32,  95,  6 };
	srand(time(0));
	for(int i=0;i<10;i++)
		arr[i]=rand()%100;
	displayArr(arr,len);
	//mergeSortItem(arr,len);
	//displayArr(arr,len);
	//quickSort(arr,0,len-1);
	heapSort(arr,len);
	displayArr(arr,len);
	return 0;
}
