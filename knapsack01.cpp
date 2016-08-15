#include<iostream>


int knapsack(int W,int wt[],int val[],int n){
    int maxWeight[n+1][W+1];
    for(int i=0;i<=n;++i){
        for(int j=0;j<=W;++j){
            if(i==0 || j==0 ) maxWeight[i][j]=0;
            else if(wt[i-1]<=j){
                maxWeight[i][j]=std::max(val[i-1]+ maxWeight[i-1][j-wt[i-1]],maxWeight[i-1][j]);
            }
            else maxWeight[i][j]=maxWeight[i-1][j];
        }
    }
    return maxWeight[n][W];
}

int main(){
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 40;
    int n = sizeof(val)/sizeof(val[0]);
    std::cout<<"\n Max value is : "<<knapsack(W,wt,val,n)<<std::endl;
}
