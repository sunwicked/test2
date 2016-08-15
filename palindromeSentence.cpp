/*. Check if a string is a palindrome where strings are almost the same (cases might be different, there might be punctuations etc.)
** Eg. "A man, a plan, a canal, Panama!" is a **  **  **  palindrome.
**
*/

#include<iostream>
#include<string>
#include<cctype>
using namespace std;
bool isEquals(char a,char b){
   int X=a-'A';
   int Y=b-'A';
   int x=a-'a';
   int y=b-'a';
   if(X==Y || x==Y|| X==y|| x==y) return true;
   return false;   
}

bool isPalindrome(string str){
   int j=str.length()-1;
   int i=0;
   while(i<j){
     if(!isalpha(str[i])) {
        ++i;
        continue;
     }
     if(!isalpha(str[j])) {
        --j;
        continue;
     }
     if(isEquals(str[i],str[j]) ){
        ++i;
        --j;
        continue;
     }
     else return false;
   }
   return true;
}
    

int main(){
  string s="A man, a plan, a canal, Panam!" ;
  if(isPalindrome(s) )std::cout<<"is Palindrome "<<endl;
  else cout<<"Not Palindrome";
}

