#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;


bool is_column_safe(int board[][10],int i,int j,int n){

  for(int row=0;row<n;row++){
    if(board[row][j]==1){
        return false;
    }
  }

  return true;

}

bool is_frontd_safe(int board[][10],int i,int j,int n){

 while(i>=0 && j<n){
    if(board[i][j]==1)
        return false;

    i--;
    j++;
 }
  return true;

}

bool is_backd_safe(int board[][10],int i,int j,int n){

 while(i>=0 && j>=0){
    if(board[i][j]==1)
        return false;

    i--;
    j--;
 }
  return true;

}


bool can_place(int board[][10],int i,int j,int n){

    if(!is_column_safe(board,i,j,n))
        return false;
    if(!is_frontd_safe(board,i,j,n))
        return false;
    if(!is_backd_safe(board,i,j,n))
        return false;

    return true;




}

void sudoku_solve(int board[][4],int i,int j,int n){

for(int k=1;k<=4;k++){

    if(can_place(board,i,j,k,n)){
        board[i][j]=k;
    }
}

}

void solve_sudoku(int board[][4],int n){

int row = -1;
int col = -1;
boo isempty = false;

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){

        if(board[i][j]==0){
            isempty =true;
            row=i;
            col=j;
            break;
        }

    }
     if(isempty)
            break;

}


}


int main(){
int 4;
int board[4][4]={{1,0,0,2},
                 {0,0,3,0},
                 {2,0,0,1},
                 {0,4,0,0}
                 };


solve_sudoku(board,0,0,n);


return 0;
}
