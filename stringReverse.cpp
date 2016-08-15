#include<iostream>
#include<list>
void reverseString(std::string str){
	int prev=0;
	std::list<std::string> st;
	for(int i=0;i<str.length();){
		if(str[i]==' '){
			st.push_front(str.substr(prev,i-prev));
			prev=i+1;
			i++;
		}
		else if(i==str.length()-1){
			st.push_front(str.substr(prev,i));
			++i;
		}
		else ++i;
	}
	for(auto p: st)
		std::cout<<p<<" ";


}
int main(){
	std::string str="dog bites man man can ban";
	std::cout<<"len = " <<str.length()<<std::endl;
	std::cout<<"reversed string is : ";
	reverseString(str);
	std::cout<<"\n";
	return 0;
}
