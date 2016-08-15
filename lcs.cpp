#include<iostream>
#include<string>
int cls(std::string,std::string);
int maxInt(int,int);
int clslen(std::string,int,std::string,int);
int clslenpre(std::string,int,std::string,int);
int main(){
	std::string s1="ABCDEFGH";
	std::string s2="ABABCAGEF";
	std::cout<<"the length of comon longest subsequence is"<<cls(s1,s2)<<std::endl;
	return 0;
}

int cls(std::string s1,std::string s2){
	int l1=s1.length();
	int l2=s2.length();
	std::cout<<l1<<"\t"<<l2<<std::endl;
	return clslenpre(s1,l1,s2,l2);
	//return clslen(s1,l1-1,s2,l2-1);
}

int clslenpre(std::string s1,int l1,std::string s2, int l2){
	int L[l1+1][l2+1];
	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++){
			if(i==0||j==0)
				L[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				L[i][j]=1+L[i-1][j-1];
			else L[i][j]=maxInt(L[i-1][j],L[i][j-1]);
			}
	}
			return L[l1][l2];
}
int clslen(std::string s1,int l1,std::string s2, int l2){
	if(l1<0 || l2<0)
		return 0;
	if(s1[l1]==s2[l2]){
		return 1+clslen(s1,l1-1,s2,l2-1);
	}
	else 
		return
		maxInt(clslen(s1,l1,s2,l2-1),clslen(s1,l1-1,s2,l2));


}
int maxInt(int n1 ,int n3){
	return n1>n3 ?n1:n3;
}
