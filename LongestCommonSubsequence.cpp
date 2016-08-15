#include<iostream>
#include<string>
int longestCommonSubsequence(std::string str1,std::string str2){
    int len1=str1.length();
    int len2=str2.length();
    int lengthTable[len1+1][len2+1];
    for(int i=0;i<=len1;++i){
        for(int j=0;j<=len2;++j){
            if(i==0 || j==0 ) lengthTable[i][j]=0;
            else if(str1[i-1]==str2[j-1]){
                lengthTable[i][j]=lengthTable[i-1][j-1]+1;
            }
            else lengthTable[i][j]= (lengthTable[i][j-1]>lengthTable[i-1][j] ? lengthTable[i][j-1] :lengthTable[i-1][j]);
        }
    }
    return lengthTable[len1][len2];
}
int main(){
    std::string str1="HNWNKUEWHSQMGBBUQCLJJIVSWMDKQTBXIXMVTRRBLJPTNSNFWZQFJMAFADRRWSOFSBCNUVQHFFBSAQXWPQCACEH ";
    std::string str2="LRBBMQBHCDARZOWKKYHIDDQSCDXRJMOWFRXSJYBLDBEFSARCBYNECDYGGXXPKLORELLNMPAPQFWKHOPKMCOQ";
    std::cout<<"Length of Longest Common Subsequence is "<<longestCommonSubsequence(str1,str2);
    
}
