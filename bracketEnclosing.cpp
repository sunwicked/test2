#include<iostream>
#include<set>
#include<string>
#include<list>
#include<vector>
using namespace std; 
std::ostream& operator<<(std::ostream& out, std::vector<std::string>& a){
    for(auto p :a)  out<<p;
    out<<"\n";
    return out;
}
  
void bracketEnclosedUtil( std::vector<string> numbers,const string s,int n,int k ,int count){                     
    std::vector<string>::iterator itr=numbers.begin();                                           
    for(int i =k;i<n;++i){
        numbers.insert(itr+i+count,s);
        std::cout<<numbers<<" \n";
        bracketEnclosedUtil(numbers,s,n,++k,count+1);
        count--;
        numbers.erase(itr+i+count);
    }
}

void bracketEnclosed(int arr[],int n){
    std::vector<string> numbers;
    for(int i =0;i<n;++i){
        numbers.push_back(to_string(arr[i]));
    }
    numbers.insert(numbers.begin(),"(");
    numbers.push_back(")");
    string s=")(";
    std::cout<<numbers;
    bracketEnclosedUtil(numbers,s,n-1,0,2);
}
/*
void bracketEnclosedUtil( string &str,const string s,int n,int k ,int count){                                                                
    for(int i =k;i<n;++i){
        str.insert(i+2*count,s);
        std::cout<<str<<" \n";
        bracketEnclosedUtil(str,s,n,++k,count+1);
        str.erase(i+2*count,2);
    }
}

void bracketEnclosed(int arr[],int n){
    string str="";
    for(int i =0;i<n;++i){
        str+= to_string(arr[i]);
    }
    str = "("+str+")";
    std::cout<<str<<" \n";
    string s=")(";
    bracketEnclosedUtil(str,s,n-1,0,1);
}*/

int main(){
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof (arr[0]);
    bracketEnclosed(arr,n);
}
