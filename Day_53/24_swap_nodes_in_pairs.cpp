
// Problem link : https://leetcode.com/problems/swap-nodes-in-pairs/


// Example : 

// Input: head = [1,2,3,4]
// Output: [2,1,4,3]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // base case jab head ka size < 2 hoga
        if(!head || !head->next) return head;
        // swap first two pairs 
        ListNode* temp = head->next->next;
        head->next->next = head;
        head = head->next;
        // after swap call at next recursively
        head->next->next = swapPairs(temp);
       return head;
    }
};



