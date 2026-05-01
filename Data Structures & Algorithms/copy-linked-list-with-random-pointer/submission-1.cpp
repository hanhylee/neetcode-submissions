/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        
        Node* curr = head;
        // map of originals to copies
        unordered_map<Node*, Node*> copies;

        Node* head_copy = new Node(head->val);
        copies[head] = head_copy;

        while (curr) {
            cout << "processing " << curr->val << "\n";

            if (curr->next != nullptr) {
                if (copies.find(curr->next) == copies.end()) {
                    Node* next_copy = new Node(curr->next->val);
                    copies[curr->next] = next_copy;
                    copies[curr]->next = next_copy;
                    cout << "created next copy of " << curr->next->val << "\n";
                } else {
                    copies[curr]->next = copies[curr->next];
                    cout << "assigned next copy of " << curr->next->val << "\n";
                }
            }
            
            if (curr->random != nullptr) {
                if (copies.find(curr->random) == copies.end()) {
                    Node* rand_copy = new Node(curr->random->val);
                    copies[curr->random] = rand_copy;
                    copies[curr]->random = rand_copy;
                    cout << "created rand copy of " << curr->random->val << "\n";
                } else {
                    copies[curr]->random = copies[curr->random];
                    cout << "assigned rand copy of " << curr->random->val << "\n";
                }
            }

            curr = curr->next;
        }

        return head_copy;
    }
};
