#include<iostream>
#include<string>
#include<list>
using namespace std;
string balancePar(string str){
   list<int> open;
   list<int> close;
   for(int i=0;i<str.length();++i){
      if(str[i]=='(') open.push_back(i);
      else if(str[i]==')') {
         if(!open.empty())  open.pop_back();
         else close.push_back(i);
      }
      else continue;           
   }
   string s="";
   for(int i=0;i<str.length();++i){
      if(!open.empty() && open.front()==i) open.pop_front();
      else if(!close.empty() && close.front()==i) close.pop_front();
      else s = s+str[i];
   }   
   return s;
}

int main(){
	char * in=new char[30];
	std::cout<<"enter string : ";
	std::cin>>in;
	std::cout<<"string after balancing parentheses"<<balancePar(in)<<std::endl;
}
