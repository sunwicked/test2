#include<iostream>
#include<list>

int calcMaxArea(int arr[],int c){
    std::list<int> stack;
    int maxArea=-1;
    int i;
    int area=-1;
    for( i =0;i<c;){
        if(stack.empty() || arr[stack.back()]<= arr[i]) stack.push_back(i++);
        else {
            int top = stack.back();
            stack.pop_back();
            if(stack.empty()){
                area = arr[top] * i;
            }else {
                area= arr[top] * (i-stack.back()-1);
            }            
            maxArea=std::max(maxArea,area);
        }
    }
    
    while(!stack.empty()){
        int top = stack.back();
        stack.pop_back();
        if(stack.empty()){
            area=arr[top] * i;           
        }else {
            area=arr[top] * (i - stack.back() -1);
        }
        
        maxArea=std::max(maxArea,area);
    }
    return maxArea;
}
int calcArea(int arr[][6],int r,int c){
    int * row = new int[c];
    row[0]=arr[0][0];
    int maxArea=-1;
    
    for(int i = 1;i<c; ++i){
        if(arr[0][i]==0) row[i]=0;
        else row[i]=row[i-1]+1;
        maxArea = std::max(maxArea,row[i]);
    }
    
    for(int i=1;i<r;++i){
        for(int j = 0;j<c; ++j){
            if (arr[i][j]==0) row[j]=0;
            else row[j]= row[j]+1;
        }
        maxArea=std::max(maxArea,calcMaxArea(row,c));
    }
    return maxArea;    
}

int main(){
    int arr[][6] = {
        {0,1,0,1,0,1},
        {0,1,1,1,1,0},
        {0,1,1,1,1,1},
        {0,1,1,1,1,1},
        {0,1,0,1,0,1},
        {0,1,0,1,0,1},
    };
    std::cout<<"\nArea is : "<<calcArea(arr,6,6)<<std::endl;
}
