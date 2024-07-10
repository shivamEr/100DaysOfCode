// Author : Shivam Kuma
r
// Input: logs = ["d1/","d2/","../","d21/","./"]
// Output: 2
// Explanation: Use this change folder operation "../" 2 times and go back to the main folder.

// Example 2:
// Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
// Output: 3

// Example 3:
// Input: logs = ["d1/","../","../","../"]
// Output: 0

#include<iostream>
using namespace std;
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int mainFolder = 0;
        for(int i =0;i<logs.size();i++){
            if(logs[i]=="./"){
                continue;
            }
            else if(logs[i]=="../"){
                if(mainFolder>0) mainFolder--;
            }
            else{
                mainFolder++;
            }
        }
        return mainFolder;
    }
};

int main(){
    Solution s;
    vector<string> logs = {"d1/","d2/","../","d21/"};
    cout<<s.minOperations(logs)<<endl;
    return 0;

}
 