

// Problem link : https://leetcode.com/problems/reverse-nodes-in-k-group/description/


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // just ek base case
        if(!head) return head;

        ListNode* tmp = head;
        int cnt=0;
    //  check kar aage k size ka node hai kya
        while(cnt!=k && tmp){
            tmp=tmp->next;
            cnt++;
        }
        // aage node size less hai k then no changes required
        if(cnt!=k) return head;
        cnt=0;
        // now, we have to reverse next kth nodes
        ListNode* curr=head;
        ListNode* nxt = head;
        ListNode* pre = NULL;
        while(cnt<k && curr){
            nxt = curr;
            curr = curr->next;
            nxt->next = pre;
            pre = nxt;
            cnt++;
        }
        // recursive call with proper linking
        head->next = reverseKGroup(curr,k);
        return pre;
    }
};

