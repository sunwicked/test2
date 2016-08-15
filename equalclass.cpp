#include<iostream>
bool isEqual(int ar1[],int l1,int ar2[],int l2){
	int l;
	if(l1>l2) l=l2;
	else l=l1;
	int i=0;
	//int j=0;
	int count=0;
	while (i<l){
		if(ar1[i]==ar2[i]){
			i++;
		}
		else{ break;}
	//	if(i==l) return true;
	}
	if(l1==l2) return true;
	int j=i+1;
	if(j<l1 && ar1[j]==ar2[i]){
		while(j<l1) {
			if(ar1[j]==ar2[i]){
				i++;
				j++;
			if(j==l1) return true;
			}
			else return false;
		}
	}
	else if(j<l2 && ar1[i]==ar2[j]){
		while(j<l2){
			if(ar1[i]==ar2[j]){
				i++;
				j++;
				if(j==l2) return true;
			}
			else return false;
		}
	}
		return false;
}
int main(){
	int arr1[]={1,2,3,4,0};
	int arr2[]={1,2,3,0};
	int l1=sizeof(arr1)/sizeof(arr1[0]);
	int l2=sizeof(arr2)/sizeof(arr1[2]);
	if(isEqual(arr1,l1,arr2,l2)) std::cout<<" is equal "<<std::endl;
	else std::cout<<" not equal ";
}
