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
    ListNode* reverseKGroup(ListNode* head, int k) {
        /* input
        given head of SINGLY-LINKED LIST
        */

        /* todo
        1. store nodes in an array until reaching k nodes
        2. if there are at least k nodes in list
            a. reverse order of those nodes
        3. else
            b. return head of modified list
        */

        ListNode* curr = head;
        ListNode* prev_end = curr;
        while (curr) {
            vector<ListNode*> k_nodes;
            for (int i=0; i<k; i++) {
                // if there aren't at least k nodes in remainder of list, return head
                if (curr == nullptr) return head;

                // else, reverse those nodes
                k_nodes.push_back(curr);
                cout << "adding " << curr->val << " to k_nodes\n";
                curr = curr->next;
            }
            // at end of this loop, curr points to the first element in the next k elements set

            // if this is the start, gotta update head too
            if (k_nodes[0] == head) {
                head = k_nodes[k-1];
                cout << "updated head\n";
            }

            // set the prev_end node's next to the new next
            prev_end->next = k_nodes[k-1];

            // reverse nodes and set next of the last node to curr
            for (int i=k-1; i>0; i--) {
                k_nodes[i]->next = k_nodes[i-1];
            }
            k_nodes[0]->next = curr;
            cout << "reversed k nodes\n";

            prev_end = k_nodes[0];
        }

        /* output 
        modified list
        */

        return head;
    }
};
