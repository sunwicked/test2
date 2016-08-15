#include<iostream>
#include<set>
#include<vector>
#include<string>
using stringSet = std::set<std::string>;
using setVector = std::vector<stringSet>;
//----------------------------------GENERATE ALL POSSIBLE STRINGS------------------------>
void generateBracketsUtil(int n1,int n2,setVector & str){
    for(auto p : str[n1]){
        for(auto q : str[n2]){
            str[n1+n2].insert(p+q);
            str[n1+n2].insert(q+p);
        }
    }
}
void generateBrackets(int n, setVector & str){
    str[1].insert("()");
    for(int i=2;i<=n;++i){
        std::string s="";
        s.insert(0,i,'(');
        s.insert(s.end(),i,')');
        str[i].insert(s);
        for(int j=1;j<i;++j){
            generateBracketsUtil(j,i-j,str);
        }
    }
}
//----------------------GENERATE ALL POSSIBLE STRINGS METHID 2--------------------------->
void generateBracketUtil2(string&str,int &count,int n){
    
}
void generateBracket2(int n){
   string str="";
   str.insert(0,n*2," ");
   generateBracketUtil(str,count,n)
}

//--------------------------MAIN METHID-------------------------------------------------->

int main(){
    int n;
    std::cout<<"Enter Number : ";
    std::cin>>n;
    setVector str(n+1,std::set<std::string>());
    generateBrackets(n,str);
    for(auto p : str[n]){
        std::cout<<p<<"  ";
    }
}
