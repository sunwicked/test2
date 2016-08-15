#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<vector>

using namespace std;
using ull = unsigned long long int;
using wordMap = std::map<string,ull>;
using numMap = std::map<ull,string>;
//-------------------------------- NUMBER TO WORD-----------------------------------------------------

void makeNumMap(numMap &nummap,numMap &nummap2){
	nummap.insert({{0,"zero"},{1,"one"},{2,"two"},{3,"three"},{4,"four"},{5,"five"},{6,"six"},{7,"seven"},{8,"eight"},{9,"nine"},
	  {10,"ten"},{11,"eleven"},{12,"twelve"},{13,"thirteen"},{14,"fourteen"},{15,"fifteen"},{16,"sixteen"},{17,"seventeen"},{18,"eighteen"},
	  {19,"nineteen"},{20,"twenty"},{30,"thirty"},{40,"forty"},{50,"fifty"},{60,"sixty"},{70,"seventy"},{80,"eighty"},{90,"ninety"},});
	nummap2.insert({{100,"hundred"},{1000,"thousand"},{1000000,"million"},{1000000000,"billion"},{1000000000000,"trillion"}});
}

std::vector<string> convert2hundred(int  num,numMap &nummap,vector<string> & result){
	int quotient = num/100;
	if(quotient>0)  {result.push_back(nummap[quotient]);result.push_back("hundred");}
	int rem = num%100;
	if(rem>=10 && rem<=19) {result.push_back(nummap[rem]); return result;}
	quotient = rem/10;
	if(quotient>0) result.push_back(nummap[quotient*10]);
	rem=rem%10;
	if(rem>0) result.push_back(nummap[rem]);
	return result;
}
vector<string> convert2string(ull num){
	vector<string> result;
	numMap map1,map2;
	makeNumMap(map1,map2);
	numMap::reverse_iterator itr = map2.rbegin(); 
	while(itr!=map2.rend()){
		int quo = num/(*itr).first;
		ull rem = num%(*itr).first;
		if(quo>0){
			convert2hundred(quo,map1,result);
			result.push_back((*itr).second);
		}
		num= num%((*itr).first);
		++itr;
	}
	convert2hundred(num,map1,result);
	return result;
}

//-------------------------------------------------------- WORD TO NUMBER -----------------------------------------------------
void makeWordMap(wordMap &wordmap,wordMap &wordmap2){
	wordmap.insert({{"zero",0},{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9},
	  {"ten",10},{"eleven",11},{"twelve",12},{"thirteen",13},{"fourteen",14},{"fifteen",15},{"sixteen",16},{"seventeen",17},{"eighteen",18},
	  {"nineteen",19},{"twenty",20},{"thirty",30},{"forty",40},{"fifty",50},{"sixty",60},{"seventy",70},{"eighty",80},{"ninety",90},});
	wordmap2.insert({{"hundred",100},{"thousand",1000},{"million",1000000},{"billion",1000000000},{"trillion",1000000000000}});
}

ull convert2num(string &number){
	wordMap map1,map2;
	makeWordMap(map1,map2);
	std::stringstream ss(number);
	vector<string> word;
	string s;
	while(getline(ss,s,' '))  word.push_back(s);
	ull num=0;
	ull product=1;
	// start processing from the last word in the vector
	for(int i =word.size()-1;i>=0;--i){
		//if word not equal to "million" , "billion","trillion" then multiply
		// with current product and add to previous number
		if(map1.find(word[i])!=map1.end()) num = map1[word[i]]*product + num;
		
		//if equals to "million" , "billion","trillion" then the current product would be same
		// else if hundred then multiply prod with hundred
		// example : one hundred thousand   product was = 1000 new product would be 1000*100;
		else if(map2.find(word[i])!=map2.end()){
			
			if(word[i]== "hundred" ) product = product * 100;
			
			else product = map2[word[i]];
		}
	}
	return num;
}

//----------------------------------MAIN----------------------------------------
int main(){
	
	for(ull i = 1;i<10000000000000;i=i*2){
		string s="";
		std::cout<<i<<"  :  ";
		vector<string> str = convert2string(i);
		for(auto p: str) {
			std::cout<< p<<" ";
			s=s+" "+p;
		}
		std::cout<<"  : "<<convert2num(s)<<std::endl;
	}
}
