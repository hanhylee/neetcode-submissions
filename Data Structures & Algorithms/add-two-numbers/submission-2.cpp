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
        ListNode *c1=l1, *c2=l2;
        bool carry = false;

        while (c1) {
            int temp;
            if (c2) temp = c1->val + c2->val;
            else temp = c1->val;

            temp += carry ? 1 : 0;
            carry = false;
            c1->val = temp % 10;

            if (temp/10 > 0) carry = true;
            
            if (c2 && c1->next == nullptr && c2->next) {
                ListNode* new_node = new ListNode(0);
                c1->next = new_node;
            }

            c1 = c1->next;
            if (c2) c2 = c2->next;
        }

        if (carry) {
            ListNode* new_node = new ListNode(1);
            ListNode* curr = l1;
            while (curr) {
                if (curr->next == nullptr) {
                    curr->next = new_node;
                    return l1;
                }
                curr = curr->next;
            }
        }

        return l1;
    }
};
