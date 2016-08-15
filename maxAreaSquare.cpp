#include<iostream>
#include<vector>
int minNum(int x,int y,int z){
    return std::min(std::min(x,y),z);
}
int calcArea(std::vector<std::vector<int>> & matrix){ 
    int nC=matrix[0].size();
    int nR=matrix.size();
    std::vector<std::vector<int>> result(nR,std::vector<int>(nC,0));
    int maxArea=-1;
    for(int i=0;i<nR;++i){
        for(int j=0;j<nC;++j){
            if(i==0 || j==0 )result[i][j]= matrix[i][j];
            else if (matrix[i][j]==0 ) result[i][j] = 0;
            else{
                result[i][j]= minNum(result[i][j-1],result[i-1][j],result[i-1][j-1])+1;
            }
            maxArea=std::max(maxArea,result[i][j]);
        }
    }
    return maxArea*maxArea;
}
int main(){
    std::vector<std::vector<int>> matrix= {
        {0,1,0,1,0,1},
        {0,1,1,1,1,0},
        {0,1,1,1,1,1},
        {0,1,1,1,1,1},
        {0,1,1,1,1,1},
        {0,1,0,1,0,1},
    };
  //  std::cout<<"\nArea is : "<< matrix.size()<<std::endl;
   std::cout<<"\nArea is : "<<calcArea(matrix)<<std::endl;
}
