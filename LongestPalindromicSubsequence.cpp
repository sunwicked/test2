#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
int f1(string s){
    vector<vector<int> > t(s.length(),vector<int>(s.length(),0));
    for(int i =0;i<s.length();++i){
        t[i][i]=1;
    }
    for(int l = 2;l<=s.length();++l){
        for(int i = 0;i<s.length()-l+1;i++){
            int j = i+l-1;
            if(l==2 && s[i]==s[j]) t[i][j]=2;
            else if(s[i]==s[j]) t[i][j] = t[i+1][j-1]+2;
            else t[i][j] = max(t[i+1][j],t[i][j-1]);
        }
    }
    int m =1;
    for(int i =0;i<s.length()-1;++i){
        m = max(t[0][i]*t[i+1][s.length()-1],m);
    }
    
    return m ;
}

int main() {
    string s = "aabaabd";
   // std::cin>>s;
    std::cout<< s.length()<<"  "<<f1(s);
    return 0;
}

