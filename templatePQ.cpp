#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
template<typename T>
class priorityQueue{
	public:
	priorityQueue():size(0){}
	void exch(T i,T j){
		T temp=items[i];
		items[i]=items[j];
		items[j]=temp;
	}
	void push(T num){
		size++;
		items.push_back(num);
		swim();
	}
	
	void swim(){
		int i =size-1;
		int p;
		while(i>0){
			p=(i-1)/2;
			if(items[p]<items[i]) break;
			exch(i,p);
			i=p;
		}
	}
	void sink(){
		int len=size-1;
		int i=0;
		while(len>=2*i+1){
			int lc = 2*i+1;
			if(lc+1<=len && items[lc]>items[lc+1]) lc++;
			if(items[i]< items[lc]) break;
			exch(i,lc);
			i=lc;
		}
	}
	void pop(){
		exch(0,--size);
		sink();
	}
	int getSize(){ return size;}
	bool empty(){ return size==0;}
		
	
	int getMaxP(){
		return items[0];
	}
	void display(){
		std::cout<<"\n Array is : ";
		for(auto p: items) std::cout<<p<<"  ";
	}
	private:
	vector<T> items;
	int size;
};

int main(){
	int n=10;
	srand(time(0));
	priorityQueue<char> pq;
	vector<char> numbers;
	int x;
	for(int i=0;i<n;++i){
		x= std::rand()%26;
		std::cout<<'a'+x<<"\n";
		pq.push((char)('a'+x));
	}
	pq.display();
	std::cout<<"\n";
	while(!pq.empty()){
		std::cout<<pq.getMaxP()<<" ";
		pq.pop();
	}
	return 0;
}