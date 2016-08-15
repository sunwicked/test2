#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
using namespace std;
/*
int f2(int num,vector<int> sqr,int k,int &maxSum){
	if(num==0) return 0;
	if(num<0) return INT_MIN;
	int sum=0;
	for(int i=k;i>=0;--i){
		for(int j = num/sqr[i];j>=0;--j){
			sum=j;
			std::cout<<"\n "<<num<<"  "<<sqr[i]<<"  "<<j<<std::endl;
			sum = sum + f2(num-j*sqr[i],sqr,i-1,maxSum);
			if(sum>0) {
				maxSum=std::min(sum,maxSum);
			}
			else if(sum<0) break;
		}
	}
	return sum;
}*/
int f2(int number,vector<int> &sqrTrm){
	vector<int> num(number+1,INT_MAX);
	num[0]=0;
	vector<int> lastNumber(number+1,-1);
	for(int i=0;i<sqrTrm.size();++i){
		for(int j=sqrTrm[i];j<=number;++j){
			if(num[j]>1+num[j-sqrTrm[i]]){
				num[j]=1+num[j-sqrTrm[i]];
				lastNumber[j]=i;
			}
		}
	}
	int value =number;
	std::cout<<"\n Numbers are  : ";
	while(value>0){
		std::cout<<sqrTrm[lastNumber[value]]<<"  ";
		value-=sqrTrm[lastNumber[value]];
	}
	return num[number];
	
}

int sumOfSqr(int number){
	if(number<=0) return 0;
	int x = std::sqrt(number);
	if(x*x== number) return 1;
	vector<int> sqrTrm(x,0);
	for(int i=0;i<x;i++) sqrTrm[i]= (i+1)*(i+1);
	return f2(number,sqrTrm);
}


int main(){
	int n = 63;
	std::cout<<"\n NUMBER IS "<<sumOfSqr(n)<<std::endl;
	return 0;
}