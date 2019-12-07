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

void solve_nqueen(int board[][10],int i,int n){

if(i==n){

    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            if(board[j][k]==1){
                cout<<"Q ";
            }else
            cout<<"_ ";
        }
        cout<<endl;
    }

    cout<<endl<<"###########"<<endl;
}

for(int j=0;j<n;j++){

    if(can_place(board,i,j,n)){
        board[i][j]=1;

        solve_nqueen(board,i+1,n);
        board[i][j]=0;
    }
}

}

int main(){
int n;
int board[10][10]={0};
cin>>n;

solve_nqueen(board,0,n);


return 0;
}
