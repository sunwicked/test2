#include<iostream>

int ways2Score(int n){
	int table[n+1];
	for(int i=0;i<=n;i++)
		table[i]=0;
	table[0]=1;
	for(int k=3;k<=n;k++)
		table[k]+=table[k-3];
	for(int k=5;k<=n;k++)
		table[k]+=table[k-5];
	for(int k=10;k<=n;k++)
		table[k]+=table[k-10];
	return table[n];
}

int ways2Score3(int n, int table[]){
	if(n<0) return 0;
	if(table[n]!=-1) return table[n];
	else return table[n]= ways2Score3(n-3,table)+
		ways2Score3(n-5,table)+ways2Score3(n-10,table);
}

int ways2Score2(int n){
	int table[n+1];
	for(int i=0;i<=n;i++)
		table[i]=-1;
	table[0]=1;
	return ways2Score3(n,table);
}
int f(int sum, int index, int arr[],int len){
	if(sum<0) return 0;
	if(sum==0) return 1;

	int count=0;
	for(int i=index; i<len; i++){
		for(int j=sum/arr[i]; j>0; j--){
			count+= f(sum-(j*arr[i]), i+1, arr,len);
		}
	}
	return count;
}
int main(){
	int score;
	int arr[]={3,5,7};
	std::cout<<" enter the score you want to reach : ";
	std::cin>>score;
	std::cout<<"total ways= "<<ways2Score2(score)<<std::endl;
	std::cout<<"total ways= "<<ways2Score(score)<<std::endl;
	std::cout<<"total ways= "<<f(score,0,arr,3)<<std::endl;
}
