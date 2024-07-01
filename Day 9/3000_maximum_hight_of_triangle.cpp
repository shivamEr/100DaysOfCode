// Easy
// Companies
// Hint
// You are given two integers red and blue representing the count of red and blue colored balls. You have to arrange these balls to form a triangle such that the 1st row will have 1 ball, the 2nd row will have 2 balls, the 3rd row will have 3 balls, and so on.

// All the balls in a particular row should be the same color, and adjacent rows should have different colors.

// Return the maximum height of the triangle that can be achieved.

#include<iostream>
using namespace std;
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        
        int cnt =0,i=1;
        int r =red, b =blue;
        // if((blue!=1 && blue<red)){
        //     swap(red,blue);
        // }
        while(blue>=i){
                blue  = blue - i;
                cnt++;
                i++;
                if(red>=i){
                    red = red -i;
                    cnt++;
                    i++;
                }
                else break;
        }
        int cnt2 =0;
        i=1;
        while(r>=i){
                r  = r - i;
                cnt2++;
                i++;
                if(b>=i){
                    b = b -i;
                    cnt2++;
                    i++;
                }
                else break;
        }
        return max(cnt,cnt2);
    }
};

int main(){
    Solution s;
    int red = 3, blue = 2;
    cout<<s.maxHeightOfTriangle(red,blue);
    return 0;
}