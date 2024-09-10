
// Problem Link : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/


class Solution {
public:
// finding gcd of two numbers using modulo operatiors
    int gcd(int n1,int n2){
        while (n1 > 0 && n2 > 0) {
            if (n1 > n2) {
             n1 = n1 % n2;
            }
            else {
             n2 = n2 % n1;
            }
        }
        if (n1 == 0) {
            return n2;
        }
        return n1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;

        ListNode* temp = head;

        while(temp->next){
            // gcd bta de
            int val = gcd(temp->val,temp->next->val);
            // created new nodes with values
            ListNode* newnode = new ListNode(val);
            // linking
            newnode->next = temp->next;
            temp->next = newnode;
            // increment two time
            temp = temp->next->next;
        }
        return head;
    }
};