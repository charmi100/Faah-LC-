/*Pattern used : Floyd's Cycle Detection Algorithm
When to use : To detect if there is a cycle in a linked list.
               To find the starting node of the cycle in a linked list.
Complexity: O(n) time complexity and O(1) space complexity.*/       

class solution{
    public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                return true;
            }
        }
        return false;
    }
};