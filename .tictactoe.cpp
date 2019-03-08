#include <bits/stdc++.h>
#include<limits.h>

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

bool winGame(char board[3][3], char player){
	int i,j;
	//Row check
	for(i=0;i<3;++i)
		if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == player){
			cout<<player<<" Wins!";
			return true;
		}
	//Col check
	for(i=0;i<3;++i)
		if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == player){
			cout<<player<<" Wins!";
			return true;
		}
	//Dig check
	if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player){
		cout<<player<<" Wins!";
		return true;
	}
	if(board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] == player){
		cout<<player<<" Wins!";
		return true;
	}
	bool flag=false;
	for(i=0;i<3;++i)
		for(j=0;j<3;++j)
			if(board[i][j] == '-')
				flag=true;
	if(!flag){
		cout<<"Draw\n";
		return true;
	}
	return false;
}

int trySolution(char board[3][3],char player, int x, int y, int D){
	
	board[x][y] = player;
	//cout<<"**********************";
	//printBoard(board);
	//cout<<"**********************\n";
	if(winGame(board,player)){
		board[x][y]='-';
		return D;
	}
	if(D>1){
		board[x][y]='-';
		return 3;
	}
	int score=INT_MAX;
	int i,j,k,l;
	for(i=0;i<3;++i)
		for(j=0;j<3;++j){
			if(board[i][j]=='-'){
				board[i][j]=player=='x'?'o':'x';
				for(k=0;k<3;++k)
					for(l=0;l<3;++l){
					if(board[k][l] == '-'){
						int t=trySolution(board,k,l,player,D+1);
						if(score > t)
							score=t;
					}
				}
			board[i][j]='-';
			}
		}					
	board[x][y]='-';
	return score+1;
	
}
void game(char board[3][3]){
	bool isFinish = false;
	bool xTurn = false;
	printBoard(board);
	while(!isFinish){
		int x,y;
		if(xTurn){
			//cout<<"X :\t";
			int i,j,tX,tY,score=INT_MAX;
			for(i=0;i<3;++i)
				for(j=0;j<3;++j)
					if(board[i][j]=='-'){
						int t = trySolution(board,'x',i,j,0);
						if(score > t){
							score=t;
							tX=i;
							tY=j;
						}
					}
			x=tX;
			y=tY;
		}
		else{
			cout<<"O :\t";
			cin>>x>>y;
		}
		if(x>3 || x<0 || y>3 || y<0){
			cout<<"Enter valid move!\n";
			continue;
		}
		else if(board[x][y] != '-'){
			cout<<"Enter valid move!\n";
			continue;
		}
		else{
			board[x][y]=xTurn?'x':'o';
			printBoard(board);
			isFinish = winGame(board,xTurn?'x':'o');
			xTurn=!xTurn;
		}
	}
}

int main(){
	char board[3][3] = { { '-','-','-'}, {'-','-','-'},{'-','-','-'} };
	game(board);
	return 0;
}
