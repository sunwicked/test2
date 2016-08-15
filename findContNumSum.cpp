#include<iostream>
#include<vector>

using namespace std;
void printNum(int i,int j){
	std::cout<<"\n";
	for(int s=i;s<=j;++s) std::cout<<s<<"  ";
	std::cout<<"  \n";
}
void findContNumbers(int num){
	int sum =0;
	int sI=1;
	for(int i=1;i<=num;++i){
		sum = sum+i;
		if(sum==num) printNum(sI,i);
		else if(sum>num){
			do{
				sum-=sI;
				sI++;	
				if(sum==num) printNum(sI,i);	
			}while(sum>num);
		}
	}
}
int main(){
	for(int i =10;i<=30;++i){
	std::cout<<"\n All NUmbers WHich sum up to "<<i<<std::endl;
	findContNumbers(i);
}
}