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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* res;
        if (list1->val <= list2->val) {
            res = list1;
            list1 = list1->next;
        } else {
            res = list2;
            list2 = list2->next;
        }

        ListNode* curr = res;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                ListNode* temp = list1->next;
                curr->next = list1;
                curr = curr->next;
                list1 = temp;
            } else {
                ListNode* temp = list2->next;
                curr->next = list2;
                curr = curr->next;
                list2 = temp;
            }
        }

        if (list1 == nullptr) curr->next = list2;
        else if (list2 == nullptr) curr->next = list1;

        return res;
    }
};
