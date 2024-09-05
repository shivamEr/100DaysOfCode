
// Problem Link : https://leetcode.com/problems/remove-duplicates-from-sorted-list/


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;

        ListNode* head1 = new ListNode(0);
        ListNode* linker = head1;
        ListNode* temp = head;
        int i= INT_MAX;
        while(temp){
            // check duplicate and link using linker
            if(temp->val!=i){
                linker->next= temp;
                linker = linker->next;
            }
            // val assing for next iteration
            i = temp->val;
            temp = temp->next;
        }
        // last null hona chahiye
        linker->next = NULL;
        return head1->next;
    }
};