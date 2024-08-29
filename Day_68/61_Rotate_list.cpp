
// <!-- Problem Link : https://leetcode.com/problems/rotate-list/ -->


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        int size = 1;
        ListNode* tail = head;
        // finding size of the list
        while(tail->next){
            tail = tail->next;
            size++;
        }
        
        k = k%size;
        // jab k ka size equal to length
        if(k==0) return head;

        ListNode* curr = head;
        int i =1;
        while(i < size-k){
            curr = curr->next;
            i++;
        }
        // Proper Linking after finding exate position of nodes
        tail->next = head;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};