

// LINK : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=head;
        ListNode *fast=head;

        while(n--){
            fast = fast->next;
        }
        if(fast==NULL) return head->next;
        while(fast->next){
            fast = fast->next;
            slow= slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

// YOU CAN ADD MAIN FUNTION 