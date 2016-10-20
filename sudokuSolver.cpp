#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
       
public:
    bool validBoard(vector<string>& board) {
         bool r[9][9], c[9][9], s[3][3][9];
         memset(r, false, sizeof(r));
         memset(c, false, sizeof(c));
         memset(s, false, sizeof(s));
         int number;
         for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] > '0' && board[i][j] <='9') {
                    number = board[i][j] - '1';
                    if (r[i][number]) return false;
                    r[i][number] = true;
                    if (c[j][number]) return false;
                    c[j][number] = true;
                    if (s[i / 3][j / 3][number]) return false;
                    s[i / 3][j / 3][number] = true;
                }
            }
        }
        return true;
    }
	
    void helper(vector<string> &board, int r,int c, bool &found ){
		if(found) return;
        if(r== 9 && c==0 ){
			found = true;
            return ;

        }
        if(r>=9 || c>=9) return;
        if(board[r][c]=='.' || board[r][c]=='#'){
        for(char i='1'; i<='9';++i){
          //  std::cout<<r<<" "<<c<<"  "<<i<<"\n";
            board[r][c]=i; 
            if(validBoard(board)){
                if(c<8) helper(board,r,c+1,found);
                else helper(board,r+1,0,found);
            }
			if(found) return;
            board[r][c]='.';
        }
		//std::cout<<r<<" "<<c<<"  "<<"\n";
        }
        else {						
            if(c<8) helper(board,r,c+1,found);
            else helper(board,r+1,0,found);
        }
    }
    void solveSudoku(vector<string>& board) {
        int len = board.size();
		bool found = false;
        helper(board,0,0,found);        
    }
};

int main(){
   Solution st;
   vector<string> s ={ ".........",".........","465897213","123456897",".........",".........",".........",".........","531642978",};
   st.solveSudoku(s);
   for(auto p : s)
   std::cout<< p <<"\n";
}