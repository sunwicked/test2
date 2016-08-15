#include<iostream>
#include<string>
#include<list>
#include<vector>
class BigInteger{
   public:
   std::list<int> Number;
   BigInteger( const std::string &num){
     int i=0;
     while(num[i]){
       Number.push_front(num[i]-'0');
       i++;
     }
   }
   
   std::list<int> getNumber(){
     return Number;
   }
   
   void printInteger(){
   }
      
};

void printResult(std::list<int>  res){
   std::list<int>::const_reverse_iterator itr = res.crbegin();
   while(itr!=res.crend()){
     std::cout<<*itr;
     ++itr;
   }
   std::cout<<"\n";
}
  
BigInteger Add( BigInteger & num1,BigInteger & num2){
   std::string result="";
   std::list<int> n1=num1.getNumber();
   std::list<int> n2=num2.getNumber();
   int carry=0;
   int sum;
   std::list<int>::iterator itr1=n1.begin();
   std::list<int>::iterator itr2=n2.begin();
   
   while(true){
     sum=carry;
     if(itr1!=n1.end()){
       sum=sum+(*itr1);
       ++itr1;
     }
     if(itr2!=n2.end()){
       sum=sum+(*itr2);
 
       ++itr2;
     }
     result= std::to_string(sum%10) + result;
     carry=sum/10;
     if(itr1==n1.end() && itr2==n2.end()){
       if(carry!=0)
          result.insert(0,std::to_string(carry));
         // result= std::to_string(carry) + result;
       break;
     }
   }
   return BigInteger(result);
}

BigInteger multiplyNum(BigInteger n1,int n){
  BigInteger b(std::to_string(0));
  for(int i=0;i<n;i++){
    b=Add(n1,b);
  }
  return b;
}

BigInteger Multiply( BigInteger num1,  BigInteger num2){
   std::string result;
   std::list<int> n1=num1.getNumber();
   std::list<int> n2=num2.getNumber();
   std::list<int>::iterator itr=n2.begin();
   BigInteger in_res(std::to_string(0));
   BigInteger in_res2(std::to_string(0));
   int count=0;
   while(itr!= n2.end()){
     in_res =  multiplyNum(num1, *itr);
     
     for(int i=0;i<count;i++){
       in_res.Number.push_front(0);
     }
     in_res2=Add(in_res,in_res2);
     ++itr;
     count++;
   }
   return in_res2;
}

int main(){
  BigInteger num1("12345678987654321");
  BigInteger num2("123456789123456789");
  std::cout<<"Addition  is : ";
  
  BigInteger SUM = Add(num1,num2);
  BigInteger prod=Multiply(num1,num2);
  printResult(SUM.getNumber());
  std::cout<<"\nProduct  is : ";
  printResult(prod.getNumber());
}






 

