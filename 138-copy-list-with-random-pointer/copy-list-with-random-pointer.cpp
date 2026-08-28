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

        if (head == NULL)
            return NULL;

        unordered_map<Node*, Node*> mp;

        Node* current = head;

        while (current != NULL) {
            mp[current] = new Node(current->val);
            current = current->next;
        }

        current = head;

        while (current != NULL) {

            mp[current]->next = mp[current->next];

            if (current->random != NULL) {
                mp[current]->random = mp[current->random];
            }

            current = current->next;
        }

        return mp[head];
    }
};