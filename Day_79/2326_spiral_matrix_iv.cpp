
// Problem Link : https://leetcode.com/problems/spiral-matrix-iv/


class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));

        int top =0, bottom = m-1;
        int left =0, right = n-1;

        while(left<=right && top<=bottom && head){
            // top row
            for(int i = left;i<=right && head;i++){
                ans[top][i] = head->val;
                head = head->next;
                
            }
            top++;

            // right column
            for(int i=top; i<=bottom && head;i++){
                ans[i][right] =  head->val;
                head = head->next;
            }
            right--;

            // buttom row
            for(int i = right; i>=left && head;i--){
                ans[bottom][i] = head->val;
                head = head->next;
            }
            bottom--;

            // left column ke liye
            for(int i = bottom; i>=top && head;i--){
                ans[i][left] = head->val;
                head =head->next;
            }
            left++;
        }
        return ans;
    }
};