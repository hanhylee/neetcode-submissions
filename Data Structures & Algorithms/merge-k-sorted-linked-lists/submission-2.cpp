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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode *b) {
            return a->val > b->val;
        };

        // initialize listsEmpty and priority queue
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap;
        
        for (const auto& l: lists) {
            if (l) heap.push(l);
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (!heap.empty()) {
            ListNode* temp = heap.top();
            heap.pop();

            curr->next = temp;
            curr = curr->next;

            if (temp->next) heap.push(temp->next);
        }

        return dummy->next;
    }
};
