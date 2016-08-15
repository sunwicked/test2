#include<iostream>

int ways2Score(int target){
   int table[target+1];
   for(int i=0;i<=target;++i) table[i]=0;
   table[0]=1;
   for(int i=3;i<=target;++i) table[i]=table[i]+table[i-3];
   for(int i=5;i<=target;++i) table[i]=table[i]+table[i-5];
   for(int i=7;i<=target;++i) table[i]=table[i]+table[i-7];
   return table[target];
}
int ways2score2(int target){
  if(target==0) return 1;
  else if(target<0) return 0;
  int n= ways2score2(target-3)  + ways2score2(target-5)+ways2score2(target-7);
  return n;
}

int main(){
	int score;
	int arr[]={3,5,7};
	std::cout<<" enter the score you want to reach : ";
	std::cin>>score;
	std::cout<<"total ways= "<<ways2score2(score)<<std::endl;
	std::cout<<"total ways= "<<ways2Score(score)<<std::endl;
	//std::cout<<"total ways= "<<f(score,0,arr,3)<<std::endl;
}
