class Solution {
public:
    void reorderList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return;

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Split into two lists
        ListNode* second = slow->next;
        slow->next = NULL;

        // 3. Reverse second half
        ListNode* prev = NULL;
        ListNode* current = second;

        while (current != NULL) {
            ListNode* next = current->next;

            current->next = prev;

            prev = current;
            current = next;
        }

        second = prev;

        // 4. Merge the two lists
        ListNode* first = head;

        while (second != NULL) {

            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};