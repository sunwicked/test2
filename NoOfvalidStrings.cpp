#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
using namespace std;
/*
*  test case 220 - should give only one answer :
*  10 20 
*
*/
///*---------------   SOLUTION FOR PRINTING WORDS ------------------------------------------------>


int noOfWords(string str,int l,int r,map<int,char> charMap,string str3){
  
	if(l>=r) {
		std::cout<<str3<<std::endl;
		return 1;
	}
	if(str[0]=='0') return 0;
	string str1="";
	string str2="";
	int x=std::stoi(str.substr(0,2));
	int y=std::stoi(str.substr(0,3));
	if(r-l>=2){
		
		str1=str3+charMap[std::stoi(str.substr(0,1))];
		str2=str3+charMap[std::stoi(str.substr(0,2))];
	//	if(x==10 || x==20) 
    //  return noOfWords(str.substr(2),l+2,r,charMap,str2);  
		if(x<=26){
			return noOfWords(str.substr(1),l+1,r,charMap,str1)+noOfWords(str.substr(2),l+2,r,charMap,str2);
		}
		else return noOfWords(str.substr(1),l+1,r,charMap,str1);
	}
	else {
		str1=str3+charMap[std::stoi(str.substr(0,1))];
		return noOfWords(str.substr(1),l+1,r,charMap,str1);
	}
}
/*
int noOfWords(string str,int l,int r,map<int,char> charMap,string str3){
	if(l>=r) {
		std::cout<<str3<<std::endl;
		return 1;
	}
	string str1="";
	string str2="";
	int x=std::stoi(str.substr(0,2));
	int y=std::stoi(str.substr(0,3));
	if(r-l>=2){
		
		str1=str3+charMap[std::stoi(str.substr(0,1))];
		str2=str3+charMap[std::stoi(str.substr(0,2))];
		if(r-l>=3){
		   if(y%10==0){
		      return noOfWords(str.substr(1),l+1,r,charMap,str1);
		   }
		}
		if(x==10 || x==20) 
      return noOfWords(str.substr(2),l+2,r,charMap,str2);  
		if(x<=26){
			return noOfWords(str.substr(1),l+1,r,charMap,str1)+noOfWords(str.substr(2),l+2,r,charMap,str2);
		}
		else return noOfWords(str.substr(1),l+1,r,charMap,str1);
	}
	else {
		str1=str3+charMap[std::stoi(str.substr(0,1))];
		return noOfWords(str.substr(1),l+1,r,charMap,str1);
	}
}

*/
//*/


/* -------------------------------SOLUTION FOR COUNTING----------------------------------------------->


int noOfStrings(string str,int sI,int endI){
   if(sI==endI || sI ==endI-1) return 1;
   int x=std::stoi(str.substr(0,2));
   if(x==10 || x==20) 
      return noOfStrings(str.substr(2),sI+2,endI);    
   if(x<=26)
      return noOfStrings(str.substr(1),sI+1,endI)+noOfStrings(str.substr(2),sI+2,endI);
   else return noOfStrings(str.substr(1),sI+1,endI);
}*/

/*
///* -------------------------------SOLUTION FOR COUNTING----------------------------------------------->
int noOfStrings(string str,int endI){
   if(str.length()==0 || str.length()==1) return 1;
   int x=std::stoi(str.substr(0,2));
   if(x==10 || x==20) 
      return noOfStrings(str.substr(2),endI);    
   if(x<=26)
      return noOfStrings(str.substr(1),endI)+noOfStrings(str.substr(2),endI);
   else return noOfStrings(str.substr(1),endI);
}
*/



///* ----------------------------------- --- SOLUTION WITH DP FOR COUNTING---------------------------------->
/*

int f2(string str, vector<int> &res,int index){
    if(res[index]!=0) return res[index];
    if(str.length()==0 || str.length()==1){
       res[index]==1 ;
       return 1;
    }
    int x=std::stoi(str.substr(0,2));
    int y=std::stoi(str.substr(0,3));
    if(y%10 == 0) {
      if(str.length()>=3)
      res[index]=f2(str.substr(1),res,index+1);      
    }
    else if(x==10 || x==20) {
      res[index]=f2(str.substr(2),res, index+2);
      res[index+1]== res[index];
    }
    else  if(x<=26) res[index]=f2(str.substr(2),res, index+2)+ f2(str.substr(1),res, index+1);
    else  res[index]=f2(str.substr(1),res, index+1);
    return res[index];
}



int noOfStrings(string str,int len){
   vector<int> res(len+1,0);
   std::set<string> words;
   return f2(str,res,0);
 //  return res[0];
}
*/

///*-------------------------------------SOLUTION FOR PRINTING WORDS WITH DP -------------------------------------------->


int f2(string str, map<int,char> int2char,vector<std::set<string> > &ll,vector<int>& res,int index){
    if(res[index]!=0) return res[index];
       if(str.length()==0 ){
       res[index]==1 ;
       return 1;
    }
    if(res[index]=='0') return 0;
       char first=int2char[std::stoi(str.substr(0,1))];
		   char second =int2char[std::stoi(str.substr(0,2))];
    if(str.length()>=2){
       int x=std::stoi(str.substr(0,2));
       int y=std::stoi(str.substr(0,3));
      /* if(y%10 == 0) {
          if(str.length()>=3)
          res[index]=f2(str.substr(1),int2char,ll,res,index+1);    
          for(auto &p: ll[index+1]){
             ll[index].insert(first+p);
          }  
       }*/
    
       //else 
       if(x==10 || x==20) {
          res[index]=f2(str.substr(2),int2char,ll,res, index+2);
          for(auto &p:ll[index+2])  ll[index].insert(second+p);
          res[index+1]== res[index];
       }
       else  if(x<=26){
          res[index]=f2(str.substr(1),int2char,ll,res, index+1)+ f2(str.substr(2),int2char,ll,res, index+2);
          for(auto &p:ll[index+2])  ll[index].insert(second+p);
          for(auto &p:ll[index+1])  ll[index].insert(first+p);
       }
       else {
          res[index]=f2(str.substr(1),int2char,ll,res, index+1);
          for(auto &p: ll[index+1]){
             ll[index].insert(first+p);
          }  
        }
    }
    else {
 
       res[index]=f2(str.substr(1),int2char,ll,res, index+1);
       for(auto &p: ll[index+1]){
           ll[index].insert(first+p);
       }  
    }
    return res[index];
}

int printWordsDP(string str, map<int,char> int2char){
  int len=str.length();
   vector<int> res(len+1,0);
   vector<std::set<string> > ll;
   ll.reserve(len+1);
   for(int i=0;i<len;++i) {
     set<string> se;
     ll.push_back(se);
   }
   set<string>se;
   string str1="";
   se.insert(str1);
   ll.push_back(se);
   f2(str,int2char,ll,res,0);
   
   for(auto p : ll[0]){
    std::cout<<p<<std::endl;
   }
   return res[0];
}
//----------------------------------------------------MAIN-------------------------------------------------------->
int main(){
   map<int,char> int2char;
   std::vector<string> words;
   for(int i=1;i<=26;++i)
     int2char[i]='a'+i-1;
    while(true){
   string s;
   std::cout<<"Enter String : ";
   std::cin>>s;
   int len=s.length();
   string s1="";
   std::cout<<"No of valid string : "<<printWordsDP(s,int2char)<<std::endl;
  std::cout<<"No of valid string : "<<noOfWords(s,0,len,int2char,s1)<<std::endl;
  // std::cout<<"No of valid string : "<<noOfStrings(s,len)<<std::endl;
   }
   return 0;
}

