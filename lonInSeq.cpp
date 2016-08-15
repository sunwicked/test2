#include<iostream>
#include<string>
int lis(std::string);
int maxInt(int,int,int);
int lislen(std::string,int);
int main(){
	std::string s1="123";
	std::cout<<"the length of increasing longest subsequence is"<<lis(s1)<<std::endl;
	return 0;
}

int lis(std::string s1){
	int l1=s1.length();
	return lislen(s1,l1);
}

int lislen(std::string s1,int l1){
	if (l1==0)return 0;
	for(int i=0;i<l1;i++)
		for(int j=0;j<l1;j++)
		if(s1[i]-'0'<=s1[j]-'0'){
			std::cout<< (s1[i]-'0')+(s1[j]-'0')<<"\t";
			return 1+lislen(s1.substr(j+1),l1-j);
		}
		else
			return 0; 
}
int maxInt(int n1,int n2, int n3){
	return n1>n2 ? (n1>n3?n1:n3):(n2 >n3?n2:n3);
}
