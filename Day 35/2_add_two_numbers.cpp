// Link : https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL;
        ListNode *tail=NULL;
        int carri =0; // carri initialy zero rahega

        // jab tak dono me koe bhi null na ho jaye
        while(l1 && l2){
            // current value batade
            int currVal = l1->val + l2->val + carri;
            int val = currVal % 10; // ye values answer hoga
            carri = currVal / 10; // carri ko update
            ListNode *newnode = new ListNode(val);
            // Normal insertion operation hai
            if(!head){
                head = tail = newnode;
            }
            else{
                tail->next = newnode;
                tail = newnode;
            }

            // Increment har bar hoga
            l1 = l1->next;
            l2 = l2->next;
        }

        // Dono list me kisi ka size jayada bhi to ho sakta hai
        while(l1){
            int currVal = l1->val + carri;
            int val = currVal % 10;
            carri = currVal / 10;

            ListNode *newnode = new ListNode(val);

            if(!head){
                head = tail = newnode;
            }
            else{
                tail->next = newnode;
                tail = newnode;
            }
            l1=l1->next;
        }
        // agar ab bhi tere pass node hai to run kar
        while(l2){
            int currVal = l2->val + carri;
            int val = currVal % 10;
            carri = currVal / 10;

            ListNode *newnode = new ListNode(val);

            if(!head){
                head = tail = newnode;
            }
            else{
                tail->next = newnode;
                tail = newnode;
            }
            l2=l2->next;
        }
        // jab carri bach gya ho to esko bhi insert karna padega na
        if(carri!=0) tail->next = new ListNode(carri);
        return head;
    }
};