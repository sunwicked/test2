#include<iostream>
#define R 6
#define C 5
int maxSquaSub(int [][C]);
int main(){
	int mat[R][C]={{0,1,1,0,1}, {1,1,0,1,0}, {0,1,1,1,0}, {1,1,1,1,0}, {1,1,1,1,1},{0,0,0,0,0}};
	std::cout<<" the largest square submatrix is "<<maxSquaSub(mat);
}
int maxInt(int a,int b){
	return a>b?a:b;
}
int minInt(int n1,int n2,int n3){
	return n1<n2?(n1<n3?n1:n3):(n2<n3?n2:n3);
}
int maxSquaSub(int M[R][C]){
	int maxS =0;
	int S[R][C];
	for(int i=0;i<C;i++)
		S[0][i]=M[0][i];
	for(int i=0;i<R;i++)
		S[i][0]=M[i][0];
	for(int i=1;i<R;i++)
		for(int j=1;j<C;j++){
			if (M[i][j]==1)
				S[i][j]=minInt(S[i-1][j-1],S[i-1][j],S[i][j-1])+1;
			else S[i][j]=0;
			maxS=maxInt(S[i][j],maxS);
		}

/*	for(int i=0;i<R;i++){
		std::cout<<"\n";
		for(int j=0;j<C;j++)
			std::cout<<S[i][j]<<"   ";
	}
	for(int i=0;i<R;i++){
		std::cout<<"\n";
		for(int j=0;j<C;j++)
			std::cout<<M[i][j]<<"   ";
	}*/
	return maxS;
}


