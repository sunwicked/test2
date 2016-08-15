#include<iostream>
#include<queue>
#include<mutex>
#include<condition_variable>
#include<mutex>
#include<thread>

using namespace std;
using uniqueLock = std::unique_lock<std::mutex>;

class ReaderWriterLock{
	int readerCount;
	int writerCount;
	bool writing;
	std::condition_variable rcv,wcv;
	std::mutex lock;
	public:
	ReaderWriterLock():readerCount(0),writerCount(0),writing(false){}
	void readLock(){
		uniqueLock ul(lock);
		readerCount++;
		rcv.wait(ul,[&](){return !writing;}); //while(writing) rcv.wait(ul);
	}
	
	void writeLock(){
		uniqueLock ul(lock);
		writerCount++;
		wcv.wait(ul,[&](){return !writing && readerCount==0;});
		writing = true;
		writerCount--;
	}
	
	void readUnlock(){
		uniqueLock ul(lock);
		readerCount--;
		if(readerCount==0) wcv.notify_all();
	}
	
	void writeUnlock(){
		uniqueLock ul(lock);
		writing = false;
		if(writerCount==0) rcv.notify_all();
		else wcv.notify_all();
	}
};

template <typename T>
class Queue{
	std::queue<T> tQueue;
	ReaderWriterLock lock;
	public:
	Queue(){}
	void push(T item){
		lock.writeLock();
		tQueue.push(item);
		lock.writeUnlock();
	}
	
	void pop(){
		lock.writeLock();
		tQueue.pop();
		lock.writeUnlock();
	}
	
	T front(){
		lock.readLock();
		T temp= tQueue.front();
		lock.readUnlock();
		return temp;
	}
	
};
//=============================
class ProducerConsumer{
	public:
	int count;
	int k =0;
	int j=0;
	std::mutex lock;
	int size ;
	condition_variable cv;
	std::queue<int> q;
	
	ProducerConsumer():count(0),size(10){}
	
	void remove(){
		uniqueLock lck(lock);
		cv.wait(lck,[&](){ return !q.empty();});j++;
		std::cout<<"\n Popped value is : "<<q.front()<<"  "<<j;
		q.pop();
		count--;
		cv.notify_all();
	}
	
	void add(int n ){
		uniqueLock lck(lock);
		cv.wait(lck,[&](){return count<=size;});
		k++;
		count++;
		q.push(n);
		std::cout<<"\n Added : "<<n<<"SIZE is "<<q.size()<<"  "<<k;
		cv.notify_all();
	}
};


void addinQueue(ProducerConsumer &pc){
	for(int i =0;i<200;++i){
		pc.add(i);
	}
}

void removeQueue(ProducerConsumer &pc){
	for(int i =0;i<200;++i){
		pc.remove();
	}
}

int main(){
	ProducerConsumer pc;
	std::thread threads[4];
	threads[0] = std::thread(addinQueue,std::ref(pc));
	threads[1] = std::thread(removeQueue,std::ref(pc));
	threads[2] = std::thread(addinQueue,std::ref(pc)) ;
	threads[3] = std::thread(removeQueue,std::ref(pc));
	for(int i=0;i<4;++i){
		threads[i].join();
	}
}

