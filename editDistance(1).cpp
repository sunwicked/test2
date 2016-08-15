#include<iostream>
#include<string>

int editDistance(std::string s1,std::string s2){
    int len1=s1.length();
    int len2=s2.length();
    int distanceTable[len1+1][len2+1];
    for(int i=0;i<=len1;++i){
        for(int j=0;j<=len2;++j){
          if(i==0) distanceTable[i][j]=j;//inserting j elements
          else if(j==0)  distanceTable[i][j]= i;//deleting i elements;
          else if (s1[i-1]==s2[j-1]) distanceTable[i][j]=distanceTable[i-1][j-1];
          else distanceTable[i][j]= 1+ std::min(
                                std::min(distanceTable[i][j-1],
                                distanceTable[i-1][j]),
                                distanceTable[i-1][j-1]
          );
       }
    }
    return distanceTable[len1][len2];
}

int main(){
   std::string s1="sunday";
   std::string s2="saturday";
   std::cout<<"\n Edit Distance is : "<<editDistance(s1,s2)<<std::endl;
}
