

// LINK :  https://leetcode.com/problems/odd-even-linked-list/description/

#include <bits/stdc++.h>
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
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        // Agar yr node hi null to aage kya krna
        if (!head)
            return NULL;
        // odd and even dono ke liye head and tail bna lete hai
        ListNode *oddH = NULL;
        ListNode *oddT = NULL;
        ListNode *evenH = NULL;
        ListNode *evenT = NULL;

        int cnt = 1; // odd and even place batayega
        while (head != NULL)
        {
            // Agar head odd hai to
            if (cnt % 2 == 1)
            {
                // Agar oodH Null hoga tab
                if (!oddH)
                {
                    oddH = oddT = head;
                    head = head->next;
                    cnt++;
                }
                else
                {
                    oddT->next = head;
                    oddT = head;
                    head = head->next;
                    cnt++;
                }
            }
            // Jab even Node hoga tab
            else
            {
                // check kreaga evenH null hai kya
                if (!evenH)
                {
                    evenH = evenT = head;
                    cnt++;
                    head = head->next;
                }
                else
                {
                    evenT->next = head;
                    evenT = head;
                    cnt++;
                    head = head->next;
                }
            }
        }
        // Odd ka tail ko even ke head se join to krna prega meri jaan
        oddT->next = evenH;
        // Ab bhai even ka tail->next ko NULL karde nhi to LOOP INFINITE JALEGA
        if (evenT)
            evenT->next = NULL;
        return oddH;
    }
};