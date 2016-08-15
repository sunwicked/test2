#include<iostream>
#include<cstdlib>
#include<ctime>
void exch(int arr[],int l,int r){
	int temp=arr[l];
	arr[l]=arr[r];
	arr[r]=temp;
}

void toggleDown(int arr[],int pos,int size){
	int lc;
	int rc;
	while(size>=2*pos+2){
		lc=2*pos+1;
		rc=2*pos+2;
			if(arr[pos] <arr[lc]||arr[pos]<arr[rc]){
				if((rc <size-1) && arr[rc]>arr[lc]){
					exch(arr,rc,pos);
					pos=rc;
				}
				else  {
					exch(arr,lc,pos);
					pos=lc;
				}
			}
			else break;
	}
}

void heapSort(int arr[],int l){
	for(int i=(l-2)/2;i>=0;i--){//created max heap
		toggleDown(arr,i,l);
	}
	while(l>1){
		exch(arr,0,l-1);
		toggleDown(arr,0,--l);
   }
}
int main(){
	const int len=10;
	int arr[len];

	srand(time(0));
	for(int i=0;i<10;i++){
		int x= rand()%127;
	    arr[i]=x;
		std::cout<<x <<"  ";
	}
	std::cout<<"\n";
	heapSort(arr,len);
	for(int i=0;i<10;i++)
		std::cout<<arr[i]<<"  ";
	return 0;
}

