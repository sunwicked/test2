#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void makePair(std::queue<std::pair<pair<int,int>,int>> &pos, int x,int y, int d,std::vector<vector<int>>& visited){
	pos.push(std::make_pair(std::make_pair(x,y),d));
	visited[x][y]=1;
}
int shortestPath(vector<vector<int>> &maze, int sX,int sY,int tX,int tY){
	int row = maze.size();
	int col = maze[0].size();
	std::vector<vector<int>> visited(row,vector<int>(col,0));
	int dis=0;
	std::queue<std::pair<pair<int,int>,int>> pos;
	makePair(pos,sX,sY,0,visited);
	std::pair<std::pair<int,int>,int> currentLoc;
	while(!pos.empty()){
		currentLoc = pos.front();
		pos.pop();
		std::pair<int,int> loc= currentLoc.first;
		int dis=currentLoc.second;
		int x = loc.first;
		int y = loc.second;
		if(x>0 && maze[x-1][y] && !visited[x-1][y]){ 
			if(x-1==tX && y == tY  ) return dis+1;
			makePair(pos,x-1,y,dis+1,visited);
		}
		if(x<row-1 && maze[x+1][y] && !visited[x+1][y]){ 
			if(x+1==tX && y == tY  ) return dis+1;
			makePair(pos,x+1,y,dis+1,visited);
		}
		if(y>0 && maze[x][y-1] && !visited[x][y-1]){ 
			if(x==tX && y-1 == tY  ) return dis+1;
			makePair(pos,x,y-1,dis+1,visited);
		}
		if(y<col-1 && maze[x][y+1] && !visited[x][y+1]){ 
			if(x==tX && y+1 == tY  ) return dis+1;
			makePair(pos,x,y+1,dis+1,visited);
		}
	}
	return -1;
}

int main(){
	vector<vector<int>> maze = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                  {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
				  
	int startX=0;
	int startY=0;
	int desX=7;
	int desY=7;
	std::cout<<"\n Shortest Path is "<<shortestPath(maze,startX,startY,desX,desY)<<std::endl;
}