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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* curr = head;
        vector<ListNode*> nodes;

        while (curr != nullptr) {
            nodes.push_back(curr);
            curr = curr->next;
        }
        
        for (int i=nodes.size()-1; i>0; i--) {
            curr = nodes[i];
            curr->next = nodes[i-1];
        }

        curr = nodes[0];
        curr->next = nullptr;

        return nodes[nodes.size()-1];
    }
};
