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
    void reorderList(ListNode* head) {
        ListNode *curr = head;
        vector<ListNode*> nodes;

        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        /**
        [0, 1, 2, 3, 4, 5, 6]
        0 -> 6 -> 1 -> 5 -> 2 -> 4 -> 3
            i=1        i=2      i=3     i=4

        [0, 1, 2, 3, 4, 5]
        0 -> 5 -> 1 -> 4 -> 2 -> 3
            i=1       i=2       i=3
        */
        curr = nodes[0];
        int i = 1;
        while (i < nodes.size() - i) {
            curr->next = nodes[nodes.size()-i];
            curr = curr->next;
            curr->next = nodes[i];
            curr = curr->next;
            i++;
        }
        if (i == nodes.size() - i) {
            curr->next = nodes[i];
            curr = curr->next;
        }
        curr->next = nullptr;
    }
};
