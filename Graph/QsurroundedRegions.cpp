////problem: Given 2D board containing 'X' and 'O' , capture all region surrounded by 'X'
// A region is captured by flipping all 'O's into 'X's  in that surrounded region.
//idea: 1. Traverse the 'O' components around the edges of the grid and change it to '*'
// 2. The remaining 'O' components will be surrounded regions that can be captured.
// 3. Change the '*' back to 'O'. 
 
#include<bits/stdc++.h>
using namespace std;
void change(vector<vector<char>> &A, int x,int y){
    A[x][y] = '*';
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    for(int i=0;i<4;i++){
        int cx= x + dx[i];
        int cy = y + dy[i]; 
        // if if we are not outside the grid
        if(cx>=0 && cx<A.size() && cy>=0 && cy<A[0].size() && A[cx][cy] == 'O'){
           change(A,cx,cy);
        } 
    }
}

int main()
{
    int n,m;cin>>n>>m;
    vector<vector<char>> A(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }

    for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){

              //CORNER CASE
             if(i==0 or i== n-1 or j==0 or j== m-1)
             {   
                 if(A[i][j]=='O'){
                   change(A,i,j); //* convert
                 }
                
             }
         }
    }

    for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
             if(A[i][j]=='O')
             {
                A[i][j]='X';
             }
         }
    }

    for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
             if(A[i][j]=='*')
             {
                A[i][j]='O';
             }
         }
    }
    for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
             cout<<A[i][j]<<" ";
         }cout<<"\n";
    }



  return 0;
}


// INPUT:
// 4 4
// XXXX
// XOOX
// XXOX
// XOXX

// OUTPUT:
// X X X X 
// X X X X
// X X X X
// X O X X