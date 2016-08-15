#include<iostream>
#include<limits.h>
int maxInt(int a,int b){
	return ((a>b)?a:b);
}
int eggDropDp(int e, int f){
	int eggFloor[e+1][f+1];
	for(int i=1;i<=e;i++){
		eggFloor[i][1]=1;
		eggFloor[i][0]=0;
	}
	for(int j=1;j<=f;j++){
		eggFloor[1][j]=j;
	}
	int res;
	for(int i=2;i<=e;i++){
		for(int j=2;j<=f;j++){
			eggFloor[i][j]=INT_MAX;
			for(int x=1;x<=j;x++){
				res=1+maxInt(eggFloor[i-1][x-1],eggFloor[i][j-x]);
				if(eggFloor[i][j]>res)
					eggFloor[i][j]=res;
			}
		}
	}
	return eggFloor[e][f];
}
int eggDrop(int e,int f){
	if(f==0||f==1)
		return f;
	if(e==1)
		return f;
	int c,i;
	int min=INT_MAX;
	for( i=1;i<=f;i++){
		c=maxInt(eggDrop(e-1,i-1),eggDrop(e,f-i));
		if(min>c) min =c;
	}
	return min+1;
}
int main(){
	int f,e,t;
	std::cout<<"enter no of floors : ";
	std::cin>>f;
	std::cout<<"number of eggs for trial : ";
	std::cin>>e;
	//std::cout<<"min no of trials to find the critical floor"<<eggDrop(e,f)<<std::endl;
	std::cout<<"min no of trials to find the critical floor"<<eggDropDp(e,f)<<std::endl;
	return 0;
}
