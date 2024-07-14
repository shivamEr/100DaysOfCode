
// CONTEST 406 
// LINK : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/

// Solution: 
#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
        ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toDelete(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;

        while (current->next != nullptr) {
            if (toDelete.find(current->next->val) != toDelete.end()) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; 
            } else {
                current = current->next;
            }
        }
        return dummy->next;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,6,3};  
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head = s.modifiedList(nums, head);

    // OUTPUT
    while (head!=NULL)
    {
        cout<<head->val<<" -> ";
        head = head->next;
    }
    
    return 0;
}