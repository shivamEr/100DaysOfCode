
// Problem Link : https://leetcode.com/problems/split-linked-list-in-parts/


class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;  
        int size = 0;

        // simple case jab head null or k ka size 1 hoga
        if (k == 1) {
            ans.push_back(head);
            return ans;
        }

        if(head == NULL){
           while(k--){
            ans.push_back(NULL);
           }
           return ans;
        }

    // size calculate krega
        ListNode* temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        int p = size / k;
        int r = size % k;

        // Split list k part me
        ListNode* current = head;
        for (int i = 0; i < k; i++) {
            ans.push_back(current); 
            int currentPartSize = p + (r > 0 ? 1 : 0);  
            r--;

            for (int j = 1; j < currentPartSize && current != NULL; j++) {
                current = current->next;
            }

             if (current != NULL) {
                ListNode* nextPart = current->next;
                current->next = NULL;
                current = nextPart;
            }
        }

        return ans;
    }
};