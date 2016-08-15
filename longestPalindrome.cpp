#include<iostream>
#include<string>
using namespace std;
//---------------------------------------USING DP -------------------------->
std::string longestPalindrome(std::string &str){
   int n=str.size();
   bool table[n][n];
   for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
         if(j==i) {
            table[i][j]=true;
            continue;
         }
         table[i][j]=false;
      }
   }
   int start=0;
   int maxlength=1;
   for(int i=0;i<n-1;++i){
      if(str[i]==str[i+1]){
         table[i][i+1]=true;
         start =i;
         maxlength=2;
      }
   }
   for(int k=3;k<=n;++k){
      for(int i=0;i<n-k+1;++i){
         int j=i+k-1;
         if(table[i+1][j-1]==true && str[i]==str[j]){
            table[i][j]=true;
            start=i;
            maxlength=k;
         }
      }
   }
   return str.substr(start,maxlength);        
}
//---------------------------------WITH CONST SPACE O[1]--------------->
std::string checkPalindrome(std::string &str, int l,int r){
  int n=str.length();
  while(l>=0 && r<=n-1 && str[l]==str[r]){
     l--;
     r++;
  }
  
  return  str.substr(l+1,r-l-1);
}
std::string largestPalindrome(std::string &str){
   int len=str.size();
   if(len==0) return "";
   string longest= str.substr(0,1);
   for(int i=0;i<len-1;++i){
      string first=checkPalindrome(str,i,i);
      if(first.length()> longest.length()) longest = first;
      string second=checkPalindrome(str,i,i+1);
      if(second.length()> longest.length()) longest = second;      
   }
   return longest;
}
 //------------------------------------------------------------------------>  
    

int main(){
   std::string str="abccbazgeekforofkeeg";
   std::cout<<"Longest palindrome is : "<<longestPalindrome(str)<<std::endl;
   std::cout<<"Longest palindrome is : "<<largestPalindrome(str)<<std::endl;
}
