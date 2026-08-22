/* Pattern Used : Three Pointers
                    next = current->next
                    current->next = previous
                    previous = current
                    current = next
When to use : To reverse a linked list.
Complexity: O(n) time complexity and O(1) space complexity.*/

class solution {
    public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* next = NULL;
        while(current != NULL) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }
};