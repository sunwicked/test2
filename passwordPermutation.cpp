#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<list>
void possibleWords(std::set<std::string> &passwd,std::map<char,std::list<char> > &symbols,std::string word,int len,int level){
	if(level==len){ 
	  return;
	}
	else{
		for(int i=level;i<len;i++){
			level=level+1;
			if(symbols.find(word[i])!=symbols.end()){
				std::map<char,std::list<char> >::const_iterator it=symbols.find(word[i]);
				for(auto p: it->second){
					word[i]=p;
					passwd.insert(word);
					possibleWords(passwd,symbols,word,len,level);
				}
			}
		}
	}
}
int main(){
	std::map<char,std::list<char> >symbols={{'m',{'m','M',}},
	                                         {'y',{'y','Y','4'}},
														  {'a',{'a','A','@'}},
														  {'e',{'e','E','3'}}
														  };
	symbols['s']={'s','S','$'};
	symbols.insert({'i',{'i','I','!'}});
	symbols.insert(std::pair<char,std::list<char> >('n',{'N'}));
	std::map<char,std::list<char> >::const_iterator it;
	for(it=symbols.begin();it!=symbols.end();++it){
		std::cout<<it->first<<" : ";
		for(auto p: it->second)
			std::cout<<p<<" , ";
		std::cout<<"\n";
	}
	std::string pass="myae";
	std::set<std::string> alpha;
	int len=pass.length();
	std::cout<<"possible combinations are  :  "<<std::endl;
	possibleWords(alpha,symbols,pass,len,0);
	std::cout<<"size of set is " <<alpha.size();
	for(auto p:alpha)
		std::cout<<p<<"   ";
}


