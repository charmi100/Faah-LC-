/*Pattern: Two Pointers used 
            1. Slow pointer moves one step at a time (slow = slow->next)
            2. Fast pointer moves two steps at a time (fast = fast->next->next) 
 When to use : To find the middle node of a linked list.
               Cycle detection in a linked list.
                To check if a linked list is palindrome.
Complexity: O(n) time complexity and O(1) space complexity.*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class solution {
    public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};