#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool validSudoku(std::vector<vector<int>> &val){
	int len =  val.size();
	vector<vector<bool>> c(len,vector<bool>(len,false));
	vector<vector<bool>> r(len,vector<bool>(len,false));
	vector<vector<vector<bool>>> rc(3,vector<vector<bool>>(3,vector<bool>(9,false)));
	//memset(rc,false,sizeof(rc));
	for(int i = 0;i<len;++i){
		for(int j = 0;j<len;++j){
			try{
			int num = val[i][j]-1;
			if(r[i][num]) return false;
			r[i][num]=true;
			if(c[j][num]) return false;
			c[j][num]=true;
			if(rc[i/3][j/3][num]) return false;
			rc[i/3][j/3][num] = true;
			}
			catch(...){
				std::cout<<"\nCATCH EXCEPTION\n";
			}
		}
		
	}
	return true;
}
int main(){
    std::vector<vector<int>> val=
                   {{5,3,4,6,7,8,9,1,2},
                    {6,7,2,1,9,5,3,4,8},
                    {1,9,8,3,4,2,5,6,7},
                    {8,5,9,7,6,1,4,2,3},
                    {4,2,6,8,5,3,7,9,1},
                    {7,1,3,9,2,4,8,5,6},
                    {9,6,1,5,3,7,2,8,4},
                    {2,8,7,4,1,9,6,3,5},
                    {3,4,5,2,8,6,1,7,9}
					};
	if(validSudoku(val)) std::cout<<"\n Is valid\n";
	else std::cout<<"NOT VALId\n";
	return 0;
}
					