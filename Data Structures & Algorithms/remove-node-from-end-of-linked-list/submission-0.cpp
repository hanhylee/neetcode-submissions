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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head;
        for (int i=0; i<n-1; i++) {
            if (curr) {
                curr = curr->next;
            } else {
                return head;
            }
        }

        // edge case nth = head
        ListNode *nth = head;
        if (curr->next == nullptr) {
            head = head->next;
            delete nth;
            return head;
        }

        curr = curr->next;
        nth = nth->next;
        ListNode *prev = head;
        while (curr->next) {
            curr = curr->next;
            nth = nth->next;
            prev = prev->next;
        }

        // edge case nth = tail
        if (nth->next == nullptr) {
            prev->next = nullptr;
            delete nth;
            return head;
        }

        prev->next = prev->next->next;
        delete nth;
        return head;
    }
};
