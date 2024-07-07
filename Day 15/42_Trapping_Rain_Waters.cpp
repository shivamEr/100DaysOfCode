// Author : Shivam Kumar

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9
 

// Constraints:

// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
     int n = height.size();
     int leftmax[n];
     int rightmax[n];
     int temp=0;
     for(int i =0;i<n;i++){
        if(temp<height[i]){
            leftmax[i] = height[i];
            temp = height[i];
        }
        else{
            leftmax[i] = temp;
        }
     }   
     temp = 0;
     for(int i =n-1;i>=0;i--){
        if(temp<height[i]){
            rightmax[i] = height[i];
            temp = height[i];
        }
        else{
            rightmax[i] = temp;
        }
     }   
     // finding trapping waters
     int waters=0;
     for(int i =0;i<n;i++){
        int minbar = min(leftmax[i],rightmax[i]);
        waters = waters + (minbar-height[i]);
     }
     return waters;
    }
};
int main(){
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(height);
    return 0;
}