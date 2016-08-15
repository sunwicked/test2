#include<iostream>
#include<string>
int longestCommonSubstring(std::string str1,std::string str2){
    int len1=str1.length();
    int len2=str2.length();
    int table[len1+1][len2+1];
    int maxLen=1;
    for(int i=0;i < len1;++i){
        for(int j=0;j<len2;++j){
            if(str1[i-1]==str2[j-1]){
                table[i][j]=table[i-1][j-1]+1;
                maxLen=std::max(maxLen,table[i][j]);
            }
            else table[i][j]=0;
        }
    }
    return maxLen;
}
int main(){
    std::string str1="ABCDEFGHIJKL";
    std::string str2="ABCDZABCZEFGHI";
    std::cout<<"\n Length of the longest common Substring : "<<longestCommonSubstring(str1,str2)<<std::endl;
    return 0;
}
