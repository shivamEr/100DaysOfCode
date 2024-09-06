
// Problem Link : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/ 


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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>um;
        for(auto it:nums) um[it]++;

        ListNode *head1 = new ListNode(0);
        ListNode *tm = head1;

        while(head){
            if(!(um.find(head->val)!=um.end())){
                tm->next = head;
                tm = tm->next;
            }
            head = head->next;
        }
        tm->next = NULL;
        return head1->next;
    }
};