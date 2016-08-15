#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
class interval{
	private :
	int lower_x;
	int upper_x;
	static std::multimap<int , int> point;
	public :
	interval(int x1,int x2){
		lower_x=x1;
		point.insert(std::pair<int,int>(x1,1));
		upper_x=x2;
		point.insert(std::pair<int,int>(x2,2));
	}
	int getLower(){return lower_x;}
	int getUpper(){return upper_x;}
	bool operator <(const interval& rhs){ return lower_x<rhs.lower_x;}
	int static findOverlappingPoint(){
		int maxFreq=0;
		int maxPoint=0;
		int count =0;
		std::multimap<int,int>::const_iterator itr;
		for(itr=point.cbegin();itr!=point.cend();++itr){
			if (itr->second==1) {
				count ++;
				if (count>maxFreq){
					maxFreq=count;
					maxPoint=itr->first;
				}
			}
			else if(itr->second==2)count --;
		}
		return maxPoint;
	}
};
std::multimap<int,int> interval::point;
int main(){
	std::vector<interval>  interv;
	interv.push_back(interval(0,5));
	interv.push_back(interval(2,6));
	interv.push_back(interval(4,8));
	interv.push_back(interval(5,12));
	interv.push_back(interval(9,15));
	std::cout<<"max occuring point is	"<<interval::findOverlappingPoint()<<std::endl;
	//sort(interval.begin(),interval.end());
}	
