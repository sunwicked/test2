/*
#include <string>
#include <sstream>
 
std::string lookandsay(const std::string &s)
{
  std::ostringstream r;
 
  for (unsigned int i = 0; i != s.length(); ) {
    unsigned int new_i = s.find_first_not_of(s[i], i+1);
    if (new_i == std::string::npos)
      new_i = s.length();
 
    r << new_i - i << s[i];
    i = new_i;
  }
  return r.str();
}
 
#include <iostream>
 
int main()
{
  std::string laf = "1";
 
  std::cout << laf << std::endl;
  for (int i = 0; i < 10; i++) {
    laf = lookandsay(laf);
    std::cout << laf << std::endl;
  }
 
  return 0;
}
*/
#include<iostream>
#include<string>
std::string lookandsay(const std::string &s)
{
  std::string r="" ;
 
  for (unsigned int i = 0; i != s.length(); ) {
    unsigned int new_i = s.find_first_not_of(s[i], i+1);
    if (new_i == std::string::npos)
      new_i = s.length();
    r=r+std::to_string(new_i-i)+s[i];
   
    i = new_i;
  }
  return r;
}
std::string generateLookandSaySeq(const std::string &abc){
	int len=abc.length();
	std::string x;
	int i=0;
	int count =0;
	for( i=1;i<len;){
		count=1;

		while(i<len && abc[i]==abc[i-1] ){
			  count++;
			  i++;
		}
		x.append(std::to_string(count));
		x.append(1,abc[i-1]);
		i++;
	}
	if(i==len ){
		x.append(1,'1');
	   x.append(1,abc[i-1]);}
	return x;
}
int main(){
	const std::string abc ="121";
	std::cout<<"generated seq is "<<generateLookandSaySeq(abc)<<std::endl;
}

	
