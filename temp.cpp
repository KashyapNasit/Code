#include<bits/stdc++.h>

using namespace std;

void printBoard(char board[3][3]){
	cout<<"\n\n";
	int i,j;
	for(i=0;i<3;++i){
		for(j=0;j<3;++j)
			cout<<board[i][j]<<"\t";
		cout<<"\n";
	}
}

void fun(char board[3][3]){
	board[1][1]='A';
	printBoard(board);
}

int main(){
	char board[3][3] = { { 'A','-','-'}, {'-','-','-'},{'-','-','-'} };
	
	fun(board);
	printBoard(board);
	return 0;
}

