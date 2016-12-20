// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include<vector>
#include<iostream>
#include<climits>
#include<limits.h>
using namespace std;
bool isValidStep(int r, int c, int rows,int columns){
    if(r>=0 && r<rows && c>=0 && c<columns) return true;
    return false;
}
void helper(vector<vector<int> >&maze,int &rows, int &columns, int & exitRow, int exitCol, int r,int c, int &minStep,vector<vector<int> > &visited, int currentLength, bool &flag ){
    if(!isValidStep(r,c,rows,columns)) return ;
    if(maze[r][c]) return;
    if(r==exitRow && c == exitCol) {
        minStep = std::min(minStep,currentLength);
        flag = true;
        visited[r][c]=1;
        return;
    }
    if(visited[r][c]) return ;
    visited[r][c]=1;
    helper(maze,rows,columns,exitRow,exitCol,r,c+1,minStep,visited,1+currentLength,flag);
    helper(maze,rows,columns,exitRow,exitCol,r,c-1,minStep,visited,1+currentLength,flag);
    helper(maze,rows,columns,exitRow,exitCol,r+1,c,minStep,visited,1+currentLength,flag);
    helper(maze,rows,columns,exitRow,exitCol,r-1,c,minStep,visited,1+currentLength,flag);
    
}
int findMinNumSteps(vector<vector<int>> maze, int rows, int columns, int exitRow, int exitCol)
{
    if(rows ==0 || columns ==0) return 0;
    vector<vector<int> > visited (rows,(vector<int>(columns,0)));
    if(exitRow>= rows || exitCol>=columns) return -1;
    int minStep = 2147483647;
    bool flag = false;
    helper(maze,rows,columns,exitRow,exitCol,0,0,minStep,visited,0,flag);
    
   if(minStep ==2147483647 ) return -1;
    return minStep;
}
// FUNCTION SIGNATURE ENDS

int main(){
   std::vector<vector<int>> maze = {{0,1,0,1},
                                    {0,0,0,1},
									{0,1,0,1}};
	std::cout<<findMinNumSteps(maze,3,4,2,2);
}