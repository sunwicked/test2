#include<iostream>
#include<vector>
//template<typename A,typename B>
using namespace std;
class KeyPair{
	public:
	string  key;
	string  value;
	KeyPair(const string k,const string v):key(k),value(v){}
};


class Link{
	public:
	KeyPair kv;
	Link* next=NULL;
	Link(KeyPair &kp):kv(kp),next(NULL){}
};
class HashMap{
	int size ;
	vector<Link *> data;
	public:
	HashMap(){
		size=20;
		data.reserve(size);
		for(int i = 0;i<size;++i){
			data.push_back(NULL);
		}
		std::cout<<"SIZE Is"<<data.size();
	}
	int hash(string &str){
		int val = 0;
		for(int i =0;i<str.size();++i)
			val = val*37 + str[i];
		return val;
	}
	
	int  find(string key){
		int has = hash(key);
		int index = has%size;
		if(data[index]==NULL) return -1; 
		else return index;
	}
	
	string  get(string key){
		int val = hash(key);
		
		if(val== -1 ) return "";
		val=val%size;
		Link *current = data[val];
		while(current!=NULL){
			if(current->kv.key==key) return current->kv.value;
			current=current->next;
		}
		return "";
	}
	
	void put(string key,string value){
		int val= hash(key);
		val=val%size;
		Link* current=data[val];
		std::cout<<"\ncalculated value = "<<val<<std::endl;
		Link *prev=NULL;
		while(current!=NULL) {current =current->next;prev=current;}
		//current = new Link();
		KeyPair kp(key,value);
		
	//	KeyPair *kp=new KeyPair(key,value);
		Link *newLink = new Link(kp);
		if(prev!=NULL)prev->next=newLink;
		else data[val]=newLink;
	}
	
	
	
};
int main(){
	HashMap hm;
	hm.put("ABDC","abc");
	std::cout<<hm.get("ABDC")<<std::endl;
}