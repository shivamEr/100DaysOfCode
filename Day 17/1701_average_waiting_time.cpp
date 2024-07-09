// Input: customers = [[1,2],[2,5],[4,3]]
// Output: 5.00000
// Explanation:
// 1) The first customer arrives at time 1, the chef takes his order and starts preparing it immediately at time 1, and finishes at time 3, so the waiting time of the first customer is 3 - 1 = 2.
// 2) The second customer arrives at time 2, the chef takes his order and starts preparing it at time 3, and finishes at time 8, so the waiting time of the second customer is 8 - 2 = 6.
// 3) The third customer arrives at time 4, the chef takes his order and starts preparing it at time 8, and finishes at time 11, so the waiting time of the third customer is 11 - 4 = 7.
// So the average waiting time = (2 + 6 + 7) / 3 = 5.

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        double tat = customers[0][0];
        double wt =0;
        for(int i =0;i<customers.size();i++){
            if(tat<customers[i][0]){
                tat = customers[i][0] + customers[i][1];
            }
            else
            tat = tat + customers[i][1];
            wt = wt + (tat - customers[i][0]);
        }
        return wt/customers.size();
    }
};

int main(){
    Solution s;
    vector<vector<int>> customers = {{1,2},{2,5},{4,3}
    cout<<s.averageWaitingTime(customers);
    return 0;
}