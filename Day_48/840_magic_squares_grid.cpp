

// Problem link : https://leetcode.com/problems/magic-squares-in-grid/description



// BRUTE FORCE TECHNIQUE
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkMagic(vector<vector<int>>&grid,int r,int c){
        bool checked[10] = {false};
        // distinct element hai ya nhi 
        for(int i=r;i<r+3;i++){
            for(int j =c;j<c+3;j++){
                int num = grid[i][j];
                if(num<1 || num>9) return false;
                if(checked[num]) return false;
                checked[num]=true;
            }
        }
        // find and check diagonal equality
        int dia1 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        int dia2 = grid[r+2][c] + grid[r+1][c+1] + grid[r][c+2];
        if(dia1!=dia2) return false;


        // Row Sum equality check karega
        int r1 = grid[r][c]+grid[r][c+1]+grid[r][c+2];
        int r2 = grid[r+1][c]+grid[r+1][c+1]+grid[r+1][c+2];
        int r3 = grid[r+2][c]+grid[r+2][c+1]+grid[r+2][c+2];

        if(r1!=r2 || r2!=r3) return false;

        // for col sum equality
        int c1 = grid[r][c]+grid[r+1][c]+grid[r+2][c];
        int c2 = grid[r][c+1]+grid[r+1][c+1]+grid[r+2][c+1];
        int c3 = grid[r][c+2]+grid[r+1][c+2]+grid[r+2][c+2];
        if(c1!=c2 || c2!=c3) return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // base case agar row,col < 3 se
        if(grid.size()<3 && grid[0].size()<3) return 0;

        int cnt =0;
        int sqGridRow = grid.size()-3;
        int sqGridCol = grid[0].size()-3;

        for(int row=0;row<=sqGridRow;row++){
            for(int col =0;col<=sqGridCol;col++){
                if(checkMagic(grid,row,col)) cnt++;
            }
        }
        return cnt;
    }
};


int main(){
    vector<vector<int>> grid = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    Solution obj;
    cout<<obj.numMagicSquaresInside(grid)<<endl;
    return 0;
}