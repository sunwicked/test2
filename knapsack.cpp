#include<iostream>
#include<vector>

int maxInt(int n1,int n2){
	return n1>n2?n1:n2;
}
int knapsackdp(int cap,int val[],int w[],int index,int n){
vector<int>dp(}
int knapsack(int cap,int val[],int w[],int index,int n){
	if(index>n) return 0;
	if (w[index]>cap) return knapsack(cap,val,w,index+1,n);
	else return	maxInt(knapsack(cap,val,w,index+1,n),val[index]+knapsack(cap-w[index],val,w,index+1,n));
}
int main(){
	int value[]={7,2,1,6,12};
	int weight[]={3,1,2,4,6};
	int capacity;
	std::cout<<"The maximum weight : ";
	std::cin>>capacity;
	int no_of_items=sizeof(value)/sizeof(int);
	std::cout<<"the maximum value :	"<<knapsack(capacity,value,weight, 0,
	no_of_items-1);
	return 0;
}

