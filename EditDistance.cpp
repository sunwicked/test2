#include<iostream>
#include<algorithm>
const int CD=1;//cost of deletion
const int CR=1;//cost of replacement
const int CI=1;//cost of insertion
int min(int a,int b,int c){
	//int x= a<b?(a<c?a:c):(b<c?b:c);
	return std::min(std::min(a,b),c);
}
// recursive approach worst case can be 3^m
int editDistance(std::string in, std::string out, int l1,int l2){
	if (l1==0)  return l2;
	if(l2==0) return l1;
	if (in[l1-1]==out[l2-1]) return editDistance(in,out,l1-1,l2-1);
	return
	min(CD+editDistance(in,out,l1-1,l2),CR+editDistance(in,out,l1-1,l2-1),CI+editDistance(in,out,l1,l2-1));

}
// dp approach bottom up 
//both time and space complexity o(m n)
int editDisDp(std::string str1, std::string str2, int l1,int l2){
	int costEdit[l1+1][l2+1];
	for(int i=0;i<=l1;i++){
		for(int j=0;j<=l2;j++){
			if(i==0) costEdit[i][j]=CI*j;
			else if(j==0) costEdit[i][j]=CD*i;
			else if(str1[i-1]==str2[j-1]) 
				costEdit[i][j]=costEdit[i-1][j-1];
			else costEdit[i][j]=min(CI + costEdit[i][j-1],
				                     CR + costEdit[i-1][j-1],
											CD + costEdit[i-1][j]);
		}
	}
	return costEdit[l1][l2];
}
int main(){
	std::string in,out;
	in="sunday";
	out="saturday";
	int l1=in.length();
	int l2=out.length();
	std::cout<<in<<" "<<out<<"  "<<l1<<" "<<l2<<"\n";
	std::cout<<"cost of converting the string :	"<<editDisDp(in,out,l1,l2)<<std::endl;
	std::cout<<"cost of converting the string :	"<<editDistance(in,out,l1,l2)<<std::endl;
}
 
