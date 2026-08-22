/*Pattern Used : Two Pointers
                    1. Create a dummy node to hold the merged list.
                    2. Use two pointers to traverse both lists and compare their values.
                    3. Append the smaller value to the merged list and move the pointer of that list forward.
                    4. If one list is exhausted, append the remaining elements of the other list.
When to use : To merge two sorted linked lists into one sorted linked list.
Complexity: O(n + m) time complexity and O(1) space complexity, where n and m are the lengths of the two linked lists.*/    

class solution{
    public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        
        if(l1 != NULL) {
            current->next = l1;
        } else {
            current->next = l2;
        }
        
        return dummy->next;
    }
}