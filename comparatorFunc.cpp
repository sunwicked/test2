#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
	class String{
		public:
		std::string str;
		String(std::string s):str(s){}
		/*bool operator<(const String& rhs)const{
	std::cout<<"abc ";
	int ll=str.length();
	int rl=rhs.str.length();
	bool alpha1 =false;
	bool alpha2 =false;
	int i,j;
	for(i =0;i<ll;i++)
		if((str[i]-'0'>=0) && (str[i]-'0'<=9))
			alpha1=true;
	for(j =0;j<rl;i++)
		if((rhs.str[j]-'0'>=0) && (rhs.str[j]-'0'<=9))
			alpha2=true;
	if(alpha1 && alpha2){
		if((i==j)&& str.substr(0,i)==str.substr(0,i)){
			int l1=std::stoi(str.substr(i));
			int r1=std::stoi(rhs.str.substr(j));
			return l1<r1;
			std::cout<<"l1 = "<<l1<<" r1 = "<<r1<<std::endl;
		}
	}
	else return str<rhs.str;
}*/
	};

class comparator{
	public:
   bool operator()(const String& lhs,const String& rhs){
	std::cout<<"lhs = "<<lhs.str <<" rhs = " <<rhs.str<<std::endl;
	int ll=lhs.str.length();
	int rl=rhs.str.length();
	bool alpha1 =false;
	bool alpha2 =false;
	int i=0,j=0;
	for( i =0;i<ll;i++){
		if((lhs.str[i]-'0'>=0) && (lhs.str[i]-'0'<=9)){
			alpha1=true;
			break;
		}
	}
	for( j =0;j<rl;j++){
		if((rhs.str[j]-'0'>=0) && (rhs.str[j]-'0'<=9))	{
			alpha2=true;
			break;
		}
	}
	std::cout<<" i = "<<i<<" j = "<<j<<std::endl;
	if(alpha1 && alpha2){
		if((i==j)&& (lhs.str.substr(0,i)==rhs.str.substr(0,j))){
			int l1=std::stoi(lhs.str.substr(i));
			int r1=std::stoi(rhs.str.substr(i));
			std::cout<<"l1 = "<<l1<<" r1 = "<<r1<<std::endl;
		std::cout<<"i = "<<i<<" j = "<<j<<"  i+j "<<i+j<<std::endl;
			return l1<r1;
		}
		
	}
	return lhs.str<rhs.str;
}
};



int main(){
	std::vector<String>
	str={String("b1"),String("b2"),String("a1"),String("aaa11"),String("a2"),String("b11")};
//	std::vector<String>
//	str={String("ab"),String("cd"),String("ac"),String("a"),String("aa"),String("ae")};
	for(auto p:str)
	std::cout<<p.str<<"  ";
	std::cout<<"\n";
	sort(str.begin(),str.end(),comparator());
	for(auto p:str)
		std::cout<<p.str<<"  ";
}
