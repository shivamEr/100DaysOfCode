

// Problem link : https://leetcode.com/contest/weekly-contest-409/problems/design-neighbor-sum-service/description/

#include<bits/stdc++.h>
using namespace std;

class neighborSum {
public:
    vector<vector<int>>grids;
    neighborSum(vector<vector<int>>& grid) {
        int n = grid.size();
        grids.resize(n,vector<int>(n));
        // copy temp grid me kar le
        grids = grid;

    }
    int i,j;
    int adjacentSum(int value) {
        bool faund = false;
        for(i =0;i<grids.size();i++){
            for(j =0;j<grids[i].size();j++){
                if(grids[i][j]==value){
                    faund = true;
                    break;
                }
            }
            if(faund) break;
        }
        int sum =0;
         if((j-1)>=0) sum+=grids[i][j-1];
         if(i-1>=0) sum+=grids[i-1][j];
         if(j+1<grids[i].size()) sum+=grids[i][j+1];
         if(i+1<grids[i].size()) sum+=grids[i+1][j];
        
        return sum;
    }
    
    int diagonalSum(int value) {
        bool faund = false;
        int i,j;
        for(i =0;i<grids.size();i++){
            for(j =0;j<grids[i].size();j++){
                if(grids[i][j]==value){
                    faund = true;
                    break;
                }
            }
            if(faund) break;
        }
        int dSum=0;
        if(i-1>=0 && j-1>=0) dSum +=grids[i-1][j-1];
        if(i+1 < grids.size() && j+1<grids[i].size()) dSum +=grids[i+1][j+1];
        
        if(i+1<grids.size() && j-1>=0) dSum +=grids[i+1][j-1];
        if(i-1 >=0 && j+1<grids[i].size()) dSum +=grids[i-1][j+1];
        return dSum;
    }
};

int main(){
    Solution s;
    int grid[3][3] = {{1,2,3},{4,5,5},{6,7,8}};
    s.setGrid(grid);
    cout<<s.adjacentSum(5)<<endl;
    return 0;

}